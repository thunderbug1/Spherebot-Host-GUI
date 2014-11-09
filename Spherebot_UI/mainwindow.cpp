#include "mainwindow.h"
#include "ui_mainwindow.h"

QString removeComments(QString intext);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resetPortList();

    //////////////////////////////////////////////////// for .svg display
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ////////////////////////////////////////////////////

    sendState = Idle;
    this->bot = new spherebot();

    penDownAngle = DEFAULTPENDOWN;
    penUpAngle = DEFAULTPENUP;

    layerIndex = 0;

    connect( this->bot, SIGNAL(dataSent(QString)),this, SLOT(sendDataUI(QString)));
    connect(&Transceiver,SIGNAL(progressChanged(int)),this,SLOT(refreshSendProgress(int)));
    connect(&Transceiver,SIGNAL(fileTransmitted()),this,SLOT(finishedTransmission()));
    connect(this->bot,SIGNAL(dataSent(QString)),this,SLOT(interpretSentString(QString)));
    connect(&Transceiver,SIGNAL(layerTransmitted()),this,SLOT(finishedLayer()));

    initUI();

    if(LoadSettings())
    {
        FitInTimer.setInterval(10);
        FitInTimer.setSingleShot(true);
        connect(&FitInTimer,SIGNAL(timeout()),this,SLOT(fitgraphicsView()));
        FitInTimer.start();
    }
    qDebug()<<"mainwindow initialised: ";
}

void MainWindow::fitgraphicsView()      ////function to trigger the fitIn function for the graphics view. Actually this shouldn´t be necessary!
{
    QGraphicsItem *item = ui->graphicsView->items().first();
    ui->graphicsView->fitInView(item);

    ui->graphicsView->ensureVisible(item);
    qDebug()<<"fit in";
}

void MainWindow::initUI()
{
    nextLayerMsgBox = new QMessageBox(QMessageBox::Information,
                                      "Next Layer",
                                      "The Layer has been finished!\nplease insert the tool for the layer: " + QString::number(layerIndex),
                                      QMessageBox::Yes|QMessageBox::No);
    nextLayerMsgBox->setButtonText(QMessageBox::Yes,"OK");
    nextLayerMsgBox->setButtonText(QMessageBox::No,"Abort");

    restartLayerMsgBox = new QMessageBox(QMessageBox::Information,
                                         "Restart?",
                                         "Do you want to restart the print?",
                                         QMessageBox::Yes|QMessageBox::No);
    //restartLayerMsgBox->setButtonText(QMessageBox::Yes,"OK");
    //restartLayerMsgBox->setButtonText(QMessageBox::No,"No");
}

MainWindow::~MainWindow()
{
    qDebug()<<"delete main window";
    SaveSettings();
    delete ui;
}
///////////////////////////////////////////////////////////////////////////////

bool MainWindow::LoadSettings()
{
    bool returnvalue = false;
    QSettings settings("thunderbug","SpherebotSettings");
    settings.beginGroup("settings");
    curFile = settings.value("fileName", "").toString();
    curDir = settings.value("currentDirectory", "").toString();
    qDebug() << "curdir"<< curDir<<endl;
    if(!curFile.isEmpty())
    {
        if(QFile::exists(curFile))
        {
            qDebug()<<"load last file.";
            loadFile(curFile);
            returnvalue = true;
        }
    }
    qDebug()<<"load: "<<curFile;
    QString SavedPortName = settings.value("PortName", "").toString();
    QSerialPortInfo info;
    portList = info.availablePorts();
    for(int i = 0; i < portList.size();i++)
    {
        if(QString::compare(portList.at(i).portName(),SavedPortName) == 0)
        {
            ui->portBox->setCurrentIndex(i);
            bot->port->setPortName(SavedPortName);
            on_connectButton_clicked();
            ui->sendButton->setEnabled(true);
        }
    }
    settings.endGroup();
    qDebug()<<"settings loaded: ";
    return returnvalue;
}

void MainWindow::SaveSettings()
{
    QSettings settings("thunderbug","SpherebotSettings");
    settings.beginGroup("settings");
    settings.setValue("fileName", curFile);
    settings.setValue("currentDirectory",curDir.absolutePath());
    settings.setValue("PortName", ui->portBox->currentText());
    settings.endGroup();
}

///////////////////////////////////////////////////////////////////////////////

int getOption(QString string,QString searchString)
{
    int index = string.indexOf(searchString);
    if(index != -1)
    {
        int i = index;
        while(string.at(i) != ' ')
            i++;
        qDebug()<<"index: "<<index+searchString.length()<<"i"<<i;
        QString subsection = string.mid(index+searchString.length(),(i - (index+searchString.length())));
        qDebug()<<subsection;
        return subsection.toInt();
    }
    return -1;
}

void MainWindow::extractOptions(QString file)
{
    penUpAngle = getOption(file,"--pen-up-angle=");
    penDownAngle = getOption(file,"--pen-down-angle=");
    qDebug()<<"penup: "<<penUpAngle;
    qDebug()<<"pendown: "<<penDownAngle;
}

void MainWindow::loadFile(const QString &fileName)
{
    qDebug()<<"loading file: "<<fileName;
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    curFile = QFileInfo(fileName).absoluteFilePath();
    curDir = QFileInfo(fileName).absoluteDir();
    statusBar()->showMessage(tr("File loaded"), 2000);

    QString code = file.readAll();
    extractOptions(code);
    interpretGcode(code);
    refreshLayerNames(code);
    ui->fileTextEdit->setText(code);
    qDebug()<<removeComments(code);

    scene->clear();
    QString picPath = QFileInfo(fileName).absoluteFilePath();
    picPath.chop(5);        //cut .gcode
    picPath.append("svg");
    QGraphicsSvgItem *item = new QGraphicsSvgItem(picPath);
    scene->addItem(item);
    ui->graphicsView->setEnabled(true);
    ui->graphicsView->fitInView(item);

    if(!ui->fileTextEdit->toPlainText().isEmpty())
    {
        setWindowTitle("Spherebot Control      File: " + fileName);
        ui->fileName->setText(QFileInfo(fileName).fileName());
    }
    else ui->sendButton->setEnabled(false);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);

    out<<ui->fileTextEdit->toPlainText();
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::interpretGcode(QString code)       //for future gcode interpretation
{
    code = removeComments(code);
    QStringList lines = code.split("\n");
    QStringList line;
    int state = 0; // 0 = pen up , 1 = pen down
    for(int i = 0;i<lines.length();i++)
    {
        //qDebug()<<lines[i];
        line = lines[i].split(" ");
        if(lines[i].contains("M300 S" + QString::number(penUpAngle) +".00"))
            state = 0;
        else if(lines[i].contains("M300 S" + QString::number(penDownAngle) +".00"))
            state = 1;

        if(state == 1)//drawing
        {
            //to do (Gcode drawer widget)
        }
    }
}

void MainWindow::refreshLayerNames(QString file)
{
    QList<QString> lines = file.split("\n");
    int layerchange = 0;
    for(int i=0;i<lines.size();i++)
    {
        qDebug()<<lines[i];
        if(lines[i].contains("M01"))
        {
            if(layerchange != 0)
            {
                qDebug()<<"This is the Split Line: " << lines[i].split("'");
                layerNames.append(lines[i].split("'")[1]);
            }
            layerchange++;
        }
    }
    qDebug()<<"This are the layernames: "<< layerNames;
}

void MainWindow::receiveData()
{
    if(bot->port->canReadLine())
    {
        QString line = bot->port->readLine(1024);
        line.chop(1);
        if(line != "")
        {
            if(line.contains("rs"))
            {
                bot->repeatLastLine();
            }
            ui->rxList->insertItem(0,line);
            delete ui->rxList->item(MAXLISTITEMS);
        }
    }
}

void MainWindow::refreshSendProgress(int value)
{
    ui->fileSendProgressBar->setValue(value);
}

void MainWindow::finishedLayer()
{
    if(layerNames.size() > 1)
    {
        layerIndex++;
    }
    qDebug()<<"layerIndex: "<<layerIndex;
    qDebug()<<"layerNames: "<<layerNames;
    qDebug()<<"layerNames.size(): "<<layerNames.size();
    if(layerIndex < layerNames.size())      //next layer
    {
        nextLayerMsgBox->setText("Please change the tool for layer: " + layerNames[layerIndex]);
        SetBotToHomePosition();
        switch(nextLayerMsgBox->exec())
        {
            case(QMessageBox::No):
            setState(Idle);    //abort
            break;
            case(QMessageBox::Yes):
            break;
            default:
            setState(Idle);    //abort
            break;
        }

    }
}

void MainWindow::finishedTransmission()
{
    disconnectTranceiver();
    this->Transceiver.resetState();
    ui->sendFileButton->setText("Send File");
    ui->loadFileButton->setText("Load File");
    ui->controllBox->setEnabled(true);
    ui->resetButton->setEnabled(false);
    ui->fileSendProgressBar->setValue(0);
    ui->fileSendProgressBar->setEnabled(false);
    ui->loadFileButton->setEnabled(true);
    statusBar()->showMessage(tr("File successfully sent"));
    sendState = Idle;
    layerIndex = 0;
    SetBotToHomePosition();
    if (QMessageBox::Yes == restartLayerMsgBox->exec())
    {
        on_sendFileButton_clicked();
    }
}

void MainWindow::interpretSentString(QString string)
{
    if(this->sendState == 1)        //if currently sending
    {
        QStringList list = string.split(" ");
        //qDebug()<<"string is : "<<string;
        for(int i = 0;i<list.size();i++)
        {
            if(!list[i].isEmpty())
            {
                if (list[i].startsWith('X'))
                {
                    //qDebug()<<"setting eggslidervalue: ";
                    ui->eggSlider->setValue(list[i].remove(0,1).toDouble());
                }
                else if (list[i].startsWith('Y'))
                {
                    //qDebug()<<"setting penslidervalue";
                    ui->penSlider->setValue(list[i].remove(0,1).toDouble());
                }
                else if (list[i].startsWith('M'))
                {
                    if(list[i].remove(0,1) == "300")
                    {
                        //qDebug()<<"setting servoSlider";
                        ui->servoSlider->setValue(list[i+1].remove(0,1).toDouble());
                    }
                    else if(list[i].remove(0,1) == "400")
                    {
                        // qDebug()<<"setting diameterSlider";
                        ui->diameterSlider->setValue(list[i+1].remove(0,1).toDouble());
                    }
                }
                else if (list[i].startsWith('F'))
                {
                    //qDebug()<<"setting servoFeedrateSlider";
                    ui->servoFeedrateSlider->setValue(list[i].remove(0,1).toDouble());
                }
            }
        }
    }
}
///////////////////////////////////////////////////////////////////

void MainWindow::on_connectButton_clicked()
{
    if(bot->isConnected())
    {
        //disconnect
        bot->disconnectWithBot();
        ui->connectButton->setChecked(false);
        ui->connectButton->setText("Connect");
        ui->controllBox->setEnabled(false);
        ui->resetButton->setEnabled(true);
        ui->portBox->setEnabled(true);
        ui->sendFileButton->setEnabled(false);
        ui->eggSlider->setValue(0);
        ui->diameterSlider->setValue(DEFAULTDIAMETER);
        ui->penSlider->setValue(0);
        ui->servoSlider->setValue(DEFAULTPENUP);
        ui->FeedratespinBox->setValue(DEFAULTFEEDRATE);
        ui->fileSendProgressBar->setValue(0);
        sendState = Idle;
        ui->sendFileButton->setText("Send File");
        ui->sendFileButton->setEnabled(false);
    }
    else if(bot->connectWithBot(ui->portBox->currentText()))
    {
        //successfully connected
        connect( this->bot->port, SIGNAL(readyRead()), this, SLOT(receiveData()));
        ui->connectButton->setChecked(true);
        ui->controllBox->setEnabled(true);
        ui->portBox->setEnabled(false);
        ui->resetButton->setEnabled(false);
        ui->connectButton->setText("Disconnect");
        if(!ui->fileTextEdit->toPlainText().isEmpty()) ui->sendFileButton->setEnabled(true);
    }
    else
    {

    }
}

void MainWindow::resetPortList()
{
    QSerialPortInfo info;
    portList = info.availablePorts();
    ui->portBox->clear();
    for(int i=0;i<portList.size();i++)
    {
        ui->portBox->addItem(portList[i].portName());
    }
}

void MainWindow::on_resetButton_clicked()
{
    resetPortList();
}

void MainWindow::sendDataUI(QString data)
{
    ui->txList->insertItem(0,data);
    delete ui->txList->item(MAXLISTITEMS);
}

void MainWindow::on_sendString_editingFinished()
{
    if(!ui->sendString->text().isEmpty())
    {
        if(!bot->send(ui->sendString->text()))
        {
            qDebug()<<bot->port->errorString();
            sendDataUI("Error while sending Data!");
        }
    }
}

void MainWindow::on_sendButton_clicked()
{
    on_sendString_editingFinished();
    ui->sendString->setText("");
    ui->sendButton->setEnabled(false);
}

void MainWindow::on_servoSlider_sliderMoved(int position)
{
    if(sendState != Sending)
    {
        QString tmp = ("M300 S" + QString::number(position)+"\n");
        bot->send(tmp);
    }
}

void MainWindow::on_servospinBox_valueChanged(int arg1)
{
    if(sendState != Sending)
    {
        ui->servoSlider->setValue(arg1);
        QString tmp = ("M300 S" + QString::number(arg1)+"\n");
        bot->send(tmp);
    }
}

void MainWindow::on_penRotationBox_valueChanged(int arg1)
{
    if(sendState != Sending)
    {
        QString tmp = ("G1 Y" + QString::number((double)arg1));
        bot->send(tmp);
        ui->penSlider->setValue(arg1);
    }
}

void MainWindow::on_penSlider_valueChanged(int value)
{
    if(sendState != Sending)
    {
        ui->penRotationBox->setValue(value);
    }
}

void MainWindow::on_eggSlider_valueChanged(int value)
{
    if(sendState != Sending)
    {
        ui->eggRotationBox->setValue(value);
    }
}

void MainWindow::on_eggRotationBox_valueChanged(int arg1)
{
    if(sendState != Sending)
    {
        QString tmp = ("G1 X" + QString::number((double)arg1)+"\n");
        bot->send(tmp);
        ui->eggSlider->setValue(arg1);
    }
}

void MainWindow::on_loadFileButton_clicked()        //== Abort Button
{
    if(sendState == Idle)
    {
        QString fileName;
        if(!curDir.absolutePath().isEmpty())
        {
            fileName = QFileDialog::getOpenFileName(this,"",curDir.absolutePath());
        }
        else
        {
            fileName = QFileDialog::getOpenFileName(this);
        }
        if (!fileName.isEmpty())
        {
            loadFile(fileName);
        }
    }
    else
    {
        setState(Idle);
    }
}


void MainWindow::on_saveFileButton_clicked()
{
    saveFile(curFile);
    ui->saveFileButton->setEnabled(false);
}

void MainWindow::on_fileTextEdit_textChanged()
{
    if(!ui->fileTextEdit->toPlainText().isEmpty())
    {
        setWindowTitle("Spherebot Controll");
        ui->fileName->setText("");
        if(bot->isConnected()) ui->sendFileButton->setEnabled(true);
        else ui->sendButton->setEnabled(false);
    }
}


void MainWindow::connectTranceiver()
{
    connect(this->bot->port,SIGNAL(readyRead()),(&this->Transceiver),SLOT(sendNext()));
}

void MainWindow::disconnectTranceiver()
{
    disconnect(this->bot->port,SIGNAL(readyRead()),(&this->Transceiver),SLOT(sendNext()));
}

void MainWindow::setState(MainWindow::SendStates state)
{
    switch(state)
    {
    case(Idle):
        switch(sendState)
        {
        case(Sending):      //from Sending to Idle
            //same code as below
            ui->fileSendProgressBar->setValue(0);
        case(Stoped):   //from Stoped to Idle
            disconnectTranceiver();
            this->Transceiver.resetState();
            ui->sendFileButton->setText("Send File");
            ui->loadFileButton->setText("Load File");
            ui->restartButton->setEnabled(false);
            ui->controllBox->setEnabled(true);
            ui->fileSendProgressBar->setEnabled(false);
            ui->loadFileButton->setEnabled(true);
            sendState = Idle;
            break;
        }
        break;
    case(Sending):
        switch(sendState)
        {
        case(Idle):     //start sending     //from Idle to Sending
            sendState = Sending;
            connectTranceiver();
            ui->controllBox->setEnabled(false);
            ui->fileSendProgressBar->setEnabled(true);
            ui->sendFileButton->setText("Stop");
            ui->restartButton->setEnabled(true);
            ui->loadFileButton->setText("Abort");
            ui->loadFileButton->setEnabled(true);
            ui->sendString->setEnabled(false);
            ui->controllBox->setEnabled(false);
            ui->sendButton->setEnabled(false);
            ui->sendString->setEnabled(false);
            Transceiver.set(ui->fileTextEdit->toPlainText(),(*this->bot));
            Transceiver.run();
            statusBar()->showMessage(tr("Sending File"));
            break;
        case(Stoped):   //continue
            sendState = Sending;
            connectTranceiver();
#ifdef Watchdog
            Transceiver.watchdogTimer->start();
#endif
            this->Transceiver.sendNext();
            ui->loadFileButton->setEnabled(false);
            ui->resetButton->setEnabled(true);
            ui->loadFileButton->setText("Abort");
            ui->loadFileButton->setEnabled(true);
            ui->sendFileButton->setText("Stop");
            ui->controllBox->setEnabled(false);
            ui->sendButton->setEnabled(false);
            ui->sendString->setEnabled(false);
            statusBar()->showMessage(tr("Sending File"));
            break;
        }
        break;
    case(Stoped):
        switch(sendState)
        {
        case(Idle):

            break;
        case(Sending):      //from Sending to Stoped
            sendState = Stoped;
            disconnectTranceiver();
            ui->restartButton->setEnabled(true);
            ui->sendFileButton->setText("Continue");
            ui->loadFileButton->setText("Abort");   //used as Abort button
            ui->loadFileButton->setEnabled(true);
            ui->controllBox->setEnabled(true);
            ui->sendButton->setEnabled(true);
            ui->sendString->setEnabled(true);
            statusBar()->showMessage(tr("Stoped sending File"));
            //vScrollBar->setSliderPosition(Transceiver.getLineCounter());
            //ui->fileTextEdit->setVerticalScrollBar();
            break;
        }
        break;
    }
    qDebug()<<"state: "<<state;
}

void MainWindow::on_sendFileButton_clicked()
{
    // QScrollBar *vScrollBar = ui->fileTextEdit->verticalScrollBar();
    switch(sendState)
    {
    case 0:         //start to send
        qDebug()<<"start sending";
        setState(Sending);
        break;
    case 1:       //stop the print
        qDebug()<< "You have stoped sending";
        setState(Stoped);
        break;
    case 2:      //continue
        setState(Sending);
        break;
    }
}

void MainWindow::on_restartButton_clicked()
{
    sendState = Sending;
    Transceiver.set(ui->fileTextEdit->toPlainText(),(*this->bot));
    connectTranceiver();
    ui->controllBox->setEnabled(false);
    ui->fileSendProgressBar->setEnabled(true);
    ui->sendFileButton->setText("Stop");
    ui->loadFileButton->setText("Load File");
    ui->controllBox->setEnabled(false);
    ui->sendButton->setEnabled(false);
    ui->sendString->setEnabled(false);
    ui->loadFileButton->setEnabled(false);
    Transceiver.set(ui->fileTextEdit->toPlainText(),(*this->bot));
    Transceiver.run();
    statusBar()->showMessage(tr("Sending File"));
}

void MainWindow::SetBotToHomePosition()
{
    QString tmp = ("G1 Y0");
    bot->send(tmp);
    tmp.clear();
    tmp.append("M300 S" + QString::number(penUpAngle));
    bot->send(tmp);
}

void MainWindow::on_servoFeedrateSlider_valueChanged(int value)
{
    if(sendState != Sending)
    {
        QString tmp = ("G1 F" + QString::number(value));
        bot->send(tmp);
    }
}

void MainWindow::on_setDiameterButton_clicked()
{
    if(sendState != Sending)
    {
        QString tmp = ("M400 S" + QString::number(ui->diameterSlider->value()));
        bot->send(tmp);
        tmp.clear();
        tmp = ("M401 S" + QString::number(ui->diameterSlider->value()));
        bot->send(tmp);
    }
}

void MainWindow::on_undoButton_clicked()
{
    ui->fileTextEdit->undo();
}

void MainWindow::on_redoButton_clicked()
{
    ui->fileTextEdit->redo();
}

void MainWindow::on_fileTextEdit_undoAvailable(bool b)
{
    ui->saveFileButton->setEnabled(true);
    if(b) ui->undoButton->setEnabled(true);
    else ui->undoButton->setEnabled(false);
}

void MainWindow::on_fileTextEdit_redoAvailable(bool b)
{
    if(b) ui->redoButton->setEnabled(true);
    else ui->redoButton->setEnabled(false);
}

void MainWindow::on_sendString_textChanged(const QString &arg1)
{
    if(!arg1.isEmpty())
    {
        ui->sendButton->setEnabled(true);
    }
    else
    {
        ui->sendButton->setEnabled(false);
    }
}
