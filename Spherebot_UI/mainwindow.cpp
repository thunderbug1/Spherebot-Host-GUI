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

    this->bot = new spherebot();
    Receiver = new rxThread(this->bot);

    penDownAngle = DEFAULTPENDOWN;
    penUpAngle = DEFAULTPENUP;

    layerIndex = 0;

    connect(bot->port,  SIGNAL(readyRead()), Receiver,      SLOT(receiveData()));
    connect(bot,        SIGNAL(dataSent(QString)),this,     SLOT(sendDataUI(QString)));
    connect(bot,        SIGNAL(progressChanged(int)),this,  SLOT(refreshSendProgress(int)));
    //connect(bot,        SIGNAL(fileTransmitted()),this,     SLOT(finishedTransmission()));
    connect(Receiver,   SIGNAL(lineReceived(QString)),this, SLOT(processReceivedData(QString)));
    connect(Receiver,   SIGNAL(lineReceived(QString)),this->bot,  SLOT(processAnswer(QString)));

    initUI();
    initSateMachine();

    if(LoadSettings())
    {
        FitInTimer.setInterval(10);
        FitInTimer.setSingleShot(true);
        connect(&FitInTimer,SIGNAL(timeout()),this,SLOT(fitgraphicsView()));
        FitInTimer.start();
    }

    setWindowTitle("Spherebot Controll");

    qDebug()<<"mainwindow initialised: ";
    connect(restartLayerMsgBox,SIGNAL(accepted()),this,SLOT(hey()));
}

void MainWindow::fitgraphicsView()      ////function to trigger the fitIn function for the graphics view. Actually this shouldn´t be necessary!
{
    QGraphicsItem *item = ui->graphicsView->items().first();
    ui->graphicsView->fitInView(item);

    ui->graphicsView->ensureVisible(item);
    qDebug()<<"fit in";
}

void MainWindow::entry_connected()
{
    //successfully connected
    qDebug()<< "entry_connected"<< endl;
    Receiver->run();
    ui->connectButton->setChecked(true);
    ui->controllBox->setEnabled(true);
    ui->portBox->setEnabled(false);
    ui->resetButton->setEnabled(false);
    ui->connectButton->setText("Disconnect");
    if(!ui->fileTextEdit->toPlainText().isEmpty()) ui->sendFileButton->setEnabled(true);
    statusBar()->showMessage(tr("Successfully connected to bot!"),4000);
}

void MainWindow::entry_try_connect()
{
    qDebug()<< "entry try_connect"<< endl;
    if(bot->connectWithBot(ui->portBox->currentText()))
    {
        emit successfully_connected();
    }
    else
    {
        emit not_successfully_connected();
        statusBar()->showMessage(tr("Could not connect to bot!"),4000);
    }
}

void MainWindow::entry_disconnected()
{
    //disconnect
    qDebug()<< "disconnect"<< endl;
    bot->disconnectWithBot();
    ui->connectButton->setChecked(false);
    ui->connectButton->setText("Connect");
    ui->loadFileButton->setText("Load File");
    ui->sendFileButton->setText("Send File");

    ui->controllBox->setEnabled(false);
    ui->portBox->setEnabled(true);
    ui->sendFileButton->setEnabled(false);
    ui->loadFileButton->setEnabled(false);
    ui->restartButton->setEnabled(false);
    ui->resetButton->setEnabled(true);

    Receiver->exit();

    ui->eggSlider->setValue(0);
    ui->diameterSlider->setValue(DEFAULTDIAMETER);
    ui->penSlider->setValue(0);
    ui->servoSlider->setValue(DEFAULTPENUP);
    ui->FeedratespinBox->setValue(DEFAULTFEEDRATE);
    ui->fileSendProgressBar->setValue(0);
}

void MainWindow::entry_transmitting()
{
    qDebug()<< "entry_transmitting"<< endl;
    ui->loadFileButton->setText("Abort");   //used as Abort button
    ui->fileSendProgressBar->setEnabled(true);
    ui->restartButton->setEnabled(true);
    ui->loadFileButton->setEnabled(true);   //=abort button
}

void MainWindow::entry_sending()    //substate of transmitting
{
    qDebug()<< "entry sending"<< endl;
    connect(this->bot,  SIGNAL(dataSent(QString)),this,         SLOT(interpretSentString(QString)));
    ui->controllBox->setEnabled(false);
    ui->sendFileButton->setText("Stop");
    bot->sendingFile = true;
    statusBar()->showMessage(tr("Sending File"));
}

void MainWindow::entry_start_sending()    //substate of transmitting
{
    qDebug()<< "entry_start_sending"<< endl;
    bot->resetState();
    bot->set(ui->fileTextEdit->toPlainText());
    bot->sendNext();
}

void MainWindow::leave_sending()    //substate of transmitting
{
    qDebug()<< "leave sending"<< endl;
    disconnect(this->bot,SIGNAL(dataSent(QString)),this,SLOT(interpretSentString(QString)));
    bot->sendingFile = false;
}

void MainWindow::entry_stopped()    //substate of transmitting
{
    qDebug()<< "entry_stopped"<< endl;
    ui->sendFileButton->setText("Continue");
    statusBar()->showMessage(tr("Stoped sending File"));
}

void MainWindow::entry_idle()
{
    qDebug()<< "entry_idle"<< endl;
    ui->fileSendProgressBar->setValue(0);
    ui->sendFileButton->setText("Send File");
    ui->loadFileButton->setText("Load File");

    ui->controllBox->setEnabled(true);
    ui->restartButton->setEnabled(false);
    ui->loadFileButton->setEnabled(true);
    ui->fileSendProgressBar->setEnabled(false);

    bot->send("M 18");      //disable motors
}

void MainWindow::entry_abort()
{
    qDebug()<< "entry_abort"<< endl;
}

void MainWindow::entry_restart()
{
    qDebug()<< "entry restart"<< endl;
    layerIndex = 0;
}

void MainWindow::entry_ask_for_restart()
{
    qDebug()<< "entry_ask_for_restart"<< endl;
    statusBar()->showMessage(tr("File successfully sent"));
    SetBotToHomePosition();
    if(restartLayerMsgBox->exec() == QMessageBox::Ok)   //workaround cause the signals don´t fire
        emit restartLayerMsgBox->accept();
    else
        emit restartLayerMsgBox->reject();
}

void MainWindow::entry_ask_for_next_layer()
{
    qDebug()<< "entry_ask_for_next_layer"<< endl;
    if(layerNames.size() > 1) layerIndex++;

    qDebug()<<"layerIndex: "<<layerIndex;
    qDebug()<<"layerNames: "<<layerNames;
    qDebug()<<"layerNames.size(): "<<layerNames.size();
    if(layerIndex < layerNames.size())      //next layer
    {
        nextLayerMsgBox->setText("Please change the tool for layer: " + layerNames[layerIndex]);
        SetBotToHomePosition();
        nextLayerMsgBox->exec();
    }
}

void MainWindow::entry_load_file_dialog()
{
    QString fileName;
    if(!curDir.absolutePath().isEmpty())
    {
        fileName = QFileDialog::getOpenFileName(this,"",curDir.absolutePath());
        ui->saveFileButton->setEnabled(false);
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

void MainWindow::initSateMachine()
{
    connected = new QState();
    try_connect = new QState();
    disconnected = new QState();

    transmitting = new QState(connected);   //transmitting means sending or stopped
    sending =      new QState(transmitting);
    stopped =      new QState(transmitting);

    idle =             new QState(connected);
    abort =            new QState(connected);
    ask_for_restart =  new QState(connected);
    restart =          new QState(connected);
    ask_for_next_layer=new QState(connected);
    load_file_dialog = new QState(connected);
    start_sending =    new QState(connected);

    /////////////////////////////////////////////////// Transitions

    connected->addTransition(ui->connectButton,     SIGNAL(clicked()),disconnected);
    disconnected->addTransition(ui->connectButton,  SIGNAL(clicked()),try_connect);
    try_connect->addTransition(this,         SIGNAL(successfully_connected()),connected);
    try_connect->addTransition(this,         SIGNAL(not_successfully_connected()),disconnected);

    connected->setInitialState(idle);

    idle->addTransition(ui->sendFileButton,SIGNAL(clicked()),start_sending);
    idle->addTransition(ui->loadFileButton,SIGNAL(clicked()),load_file_dialog);

    transmitting->addTransition(ui->loadFileButton, SIGNAL(clicked()),abort);
    transmitting->addTransition(ui->restartButton,  SIGNAL(clicked()),restart);
    //
    sending->addTransition(ui->sendFileButton,SIGNAL(clicked()),stopped);
    sending->addTransition(this->bot,         SIGNAL(fileTransmitted()),ask_for_restart);
    sending->addTransition(this->bot,         SIGNAL(layerTransmitted()),ask_for_next_layer);

    stopped->addTransition(ui->sendFileButton,SIGNAL(clicked()),start_sending);
    //
    start_sending->addTransition(start_sending,SIGNAL(entered()),sending);

    ask_for_restart->addTransition(restartLayerMsgBox,SIGNAL(accepted()),restart);
    ask_for_restart->addTransition(restartLayerMsgBox,SIGNAL(rejected()),idle);
    connect(ask_for_restart,SIGNAL(exited()),this,SLOT(hey()));

    ask_for_next_layer->addTransition(nextLayerMsgBox,SIGNAL(accepted()),sending);

    load_file_dialog->addTransition(load_file_dialog,SIGNAL(entered()),idle);

    abort->addTransition(abort,SIGNAL(entered()),idle);

    restart->addTransition(restart,SIGNAL(entered()),start_sending);

    /////////////////////////////////////////////////// Functions executed in states

    connect(connected,      SIGNAL(entered()),this,SLOT(entry_connected()));
    connect(try_connect,    SIGNAL(entered()),this,SLOT(entry_try_connect()));
    connect(disconnected,   SIGNAL(entered()),this,SLOT(entry_disconnected()));
    connect(transmitting,   SIGNAL(entered()),this,SLOT(entry_transmitting()));
    connect(idle,           SIGNAL(entered()),this,SLOT(entry_idle()));
    connect(sending,        SIGNAL(entered()),this,SLOT(entry_sending()));
    connect(start_sending,  SIGNAL(entered()),this,SLOT(entry_start_sending()));
    connect(stopped,        SIGNAL(entered()),this,SLOT(entry_stopped()));
    connect(restart,        SIGNAL(entered()),this,SLOT(entry_restart()));
    connect(ask_for_restart,SIGNAL(entered()),this,SLOT(entry_ask_for_restart()));
    connect(ask_for_next_layer,SIGNAL(entered()),this,SLOT(entry_ask_for_next_layer()));
    connect(load_file_dialog,SIGNAL(entered()),this,SLOT(entry_load_file_dialog()));

    connect(sending,        SIGNAL(exited()), this,SLOT(leave_sending()));

    ///////////////////////////////////////////////////

    machine.addState(connected);
    machine.addState(disconnected);
    machine.addState(try_connect);

    machine.setInitialState(disconnected);
    machine.start();
}

void MainWindow::initUI()
{
    nextLayerMsgBox = new QMessageBox(QMessageBox::Information,
                                      "Next Layer",
                                      "The Layer has been finished!\nplease insert the tool for the layer: " + QString::number(layerIndex),
                                      QMessageBox::Ok|QMessageBox::No);
    nextLayerMsgBox->setButtonText(QMessageBox::Ok,"OK");
    nextLayerMsgBox->setButtonText(QMessageBox::No,"Abort");

    restartLayerMsgBox = new QMessageBox(QMessageBox::Information,
                                         "Restart?",
                                         "Do you want to restart the print?",
                                         QMessageBox::Ok|QMessageBox::No);

    connect(ui->undoButton,SIGNAL(clicked()),ui->fileTextEdit,SLOT(undo()));
    connect(ui->redoButton,SIGNAL(clicked()),ui->fileTextEdit,SLOT(redo()));

    connect(ui->fileTextEdit,SIGNAL(undoAvailable(bool)),ui->saveFileButton,SLOT(setEnabled(bool)));
    connect(ui->fileTextEdit,SIGNAL(undoAvailable(bool)),ui->undoButton,SLOT(setEnabled(bool)));
    connect(ui->fileTextEdit,SIGNAL(redoAvailable(bool)),ui->redoButton,SLOT(setEnabled(bool)));

    connect(ui->eggSlider,SIGNAL(valueChanged(int)),ui->eggRotationBox,SLOT(setValue(int)));
    connect(ui->penSlider,SIGNAL(valueChanged(int)),ui->penRotationBox,SLOT(setValue(int)));

    //ui->baudBox->setEnabled(true);

    //init the baudBox
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
            bot->connectWithBot(SavedPortName);
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

void MainWindow::processReceivedData(QString line)
{
    if(line != "")
    {
        ui->rxList->insertItem(0,line);
        delete ui->rxList->item(MAXLISTITEMS);
    }
}

void MainWindow::refreshSendProgress(int value)
{
    ui->fileSendProgressBar->setValue(value);
}

void MainWindow::interpretSentString(QString string)
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
///////////////////////////////////////////////////////////////////

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
    while(data.endsWith('\n')) data.chop(1);

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
    bot->send("M300 S" + QString::number(position));
}

void MainWindow::on_servospinBox_valueChanged(int arg1)
{
    ui->servoSlider->setValue(arg1);
    bot->send("M300 S" + QString::number(arg1));
}

void MainWindow::on_penRotationBox_valueChanged(int arg1)
{
    bot->send("G1 Y" + QString::number((double)arg1));
    ui->penSlider->setValue(arg1);
}

void MainWindow::on_eggRotationBox_valueChanged(int arg1)
{
    bot->send("G1 X" + QString::number((double)arg1));
    ui->eggSlider->setValue(arg1);
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
        ui->fileName->setText("");
        if(bot->isConnected()) ui->sendFileButton->setEnabled(true);
        else ui->sendButton->setEnabled(false);
    }
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
    bot->send("G1 F" + QString::number(value));
}

void MainWindow::on_setDiameterButton_clicked()
{
    bot->send("M400 S" + QString::number(ui->diameterSlider->value()));
    bot->send("M401 S" + QString::number(ui->diameterSlider->value()));
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
