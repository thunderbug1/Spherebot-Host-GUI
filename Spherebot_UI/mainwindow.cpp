#include "mainwindow.h"
#include "ui_mainwindow.h"

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


    sendState = false;
    rxTimer = new QTimer(this);

    //connect( bot.port, SIGNAL(readyRead()), this, SLOT(receiveData()) );
    connect( rxTimer,SIGNAL(timeout()),this,SLOT(receiveData()));
    connect( &bot, SIGNAL(dataSent(QString)),this, SLOT(sendData(QString)));
    connect(this,SIGNAL(receivedLine(QString)),&Transceiver,SLOT(checkResponse(QString)));
    connect(&Transceiver,SIGNAL(progressChanged(int)),this,SLOT(refreshSendProgress(int)));
    connect(&Transceiver,SIGNAL(fileTransmitted()),this,SLOT(finishedTransmission()));
}

MainWindow::~MainWindow()
{
    qDebug()<<"delete main window";
    QSettings settings(nameSettingsFile, QSettings::NativeFormat);
    QString tmp = (ui->portBox->currentText());
    settings.setValue("portName", tmp);
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    statusBar()->showMessage(tr("File loaded"), 2000);
    ui->fileTextEdit->setText(file.readAll());

    scene->clear();
    QString picPath = QFileInfo(fileName).absoluteFilePath();
    picPath.chop(5);
    picPath.append("svg");
    QGraphicsSvgItem *item = new QGraphicsSvgItem(picPath);
    scene->addItem(item);
    ui->graphicsView->setEnabled(true);
}

bool MainWindow::saveFile(const QString &fileName)
//! [44] //! [45]
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

void MainWindow::receiveData()
{
    if(bot.port->bytesAvailable())
    {
        //qDebug()<< "Read line";
        QString line =bot.port->readLine(1024);
        line.chop(1);
        emit receivedLine(line);
        ui->rxList->insertItem(0,line);
    }
}

void MainWindow::refreshSendProgress(int value)
{
    ui->fileSendProgressBar->setValue(value);
}

void MainWindow::finishedTransmission()
{
    ui->sendFileButton->setText("Send File");
    ui->controllBox->setEnabled(true);
    ui->fileSendProgressBar->setEnabled(false);
    statusBar()->showMessage(tr("File successfully sent"));
    sendState = false;
}

///////////////////////////////////////////////////////////////////

void MainWindow::on_connectButton_clicked()
{
    if(bot.isConnected())
    {
        //disconnect
        rxTimer->stop();
        bot.disconnectWithBot();
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
        sendState = 0;
        ui->sendFileButton->setText("Send File");
    }
    else if(bot.connectWithBot(ui->portBox->currentText()))
    {
        //successfully connected
        rxTimer->start(2);
        qDebug()<<"Start Timer";
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
    portList =serialEnumerator.getPorts();
    ui->portBox->clear();
    for(int i=0;i<portList.size();i++)
    {
        ui->portBox->addItem(portList[i].portName);
    }
}

void MainWindow::on_resetButton_clicked()
{
    resetPortList();
}

void MainWindow::sendData(QString data)
{
    ui->txList->insertItem(0,data);
}

void MainWindow::on_sendString_editingFinished()
{
    if(!bot.send(ui->sendString->text()))
    {
        //sendData(ui->sendString->text());
    }
    else
    {
        qDebug()<<bot.port->errorString();
        sendData("Error while sending Data!");
    }
}

void MainWindow::on_sendButton_clicked()
{
    if(!bot.send(ui->sendString->text()))
    {
        //sendData(ui->sendString->text());
    }
    else
    {
        qDebug()<<bot.port->errorString();
        //sendData("Error while sending Data!");
    }
}

void MainWindow::on_servoSlider_sliderMoved(int position)
{
    //ui->servospinBox->setValue(position);
    QString tmp = ("M300 S" + QString::number(position)+"\n");
    bot.send(tmp);
    //sendData(tmp);
}

void MainWindow::on_servospinBox_valueChanged(int arg1)
{
    ui->servoSlider->setValue(arg1);
    QString tmp = ("M300 S" + QString::number(arg1)+"\n");
    bot.send(tmp);
}

void MainWindow::on_penRotationBox_valueChanged(int arg1)
{
    QString tmp = ("G1 Y" + QString::number((double)arg1));
    bot.send(tmp);
    ui->penSlider->setValue(arg1);
}

void MainWindow::on_penSlider_valueChanged(int value)
{
    ui->penRotationBox->setValue(value);
}

void MainWindow::on_eggSlider_valueChanged(int value)
{
    ui->eggRotationBox->setValue(value);
}

void MainWindow::on_eggRotationBox_valueChanged(int arg1)
{
    QString tmp = ("G1 X" + QString::number((double)arg1)+"\n");
    bot.send(tmp);
    ui->eggSlider->setValue(arg1);
}

void MainWindow::on_loadFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
        loadFile(fileName);
    if(!ui->fileTextEdit->toPlainText().isEmpty())
    {
        setWindowTitle("Spherebot Controll      File: " + fileName);
        ui->fileName->setText(QFileInfo(fileName).fileName());
    }
    else ui->sendButton->setEnabled(false);
}


void MainWindow::on_saveFileButton_clicked()
{
    saveFile(curFile);
    ui->saveFileButton->setEnabled(false);
}

QString removeComments(QString input);

void MainWindow::on_fileTextEdit_textChanged()
{
    ui->saveFileButton->setEnabled(true);
    if(!ui->fileTextEdit->toPlainText().isEmpty())
    {
        setWindowTitle("Spherebot Controll");
        ui->fileName->setText("");
        if(bot.isConnected()) ui->sendFileButton->setEnabled(true);
        else ui->sendButton->setEnabled(false);
    }
}


void MainWindow::on_sendFileButton_clicked()
{
    QScrollBar *vScrollBar = ui->fileTextEdit->verticalScrollBar();
    qDebug()<<"enter button code";
    switch(sendState)
    {
    case 0:         //start to send
        qDebug()<<"start sending";
        sendState = 1;
        ui->controllBox->setEnabled(false);
        ui->fileSendProgressBar->setEnabled(true);
        ui->sendFileButton->setText("Stop");
        ui->controllBox->setEnabled(false);
        ui->sendButton->setEnabled(false);
        Transceiver.set(ui->fileTextEdit->toPlainText(),this->bot);
        qDebug()<<"tx is set";
        Transceiver.run();
        statusBar()->showMessage(tr("Sending File"));
        break;
    case 1:       //stop the print
        qDebug()<< "You have stoped sending";
        sendState = 2;
        ui->restartButton->setEnabled(true);
        ui->sendFileButton->setText("Continue");
        ui->controllBox->setEnabled(true);
        ui->sendButton->setEnabled(true);
        vScrollBar->setValue(Transceiver.getLineCounter());
        Transceiver.checkSendBufferTimer->stop();
        break;
    case 2:      //continue
        sendState = 1;
        Transceiver.checkSendBufferTimer->start(SENDBUFFERINTERVAL);
        ui->restartButton->setEnabled(false);
        ui->sendFileButton->setText("Stop");
        ui->controllBox->setEnabled(false);
        ui->sendButton->setEnabled(false);
        break;
    }

    qDebug()<<"leave button code";
}

void MainWindow::on_restartButton_clicked()
{
    sendState = 1;
    ui->controllBox->setEnabled(false);
    ui->fileSendProgressBar->setEnabled(true);
    ui->sendFileButton->setText("Stop");
    ui->controllBox->setEnabled(false);
    ui->sendButton->setEnabled(false);
    Transceiver.set(ui->fileTextEdit->toPlainText(),this->bot);
    qDebug()<<"tx is set";
    Transceiver.run();
    statusBar()->showMessage(tr("Sending File"));
}

void MainWindow::on_servoFeedrateSlider_valueChanged(int value)
{
    QString tmp = ("G1 F" + QString::number(value)+"\n");
    bot.send(tmp);
}

void MainWindow::on_setDiameterButton_clicked()
{
    QString tmp = ("M400 S" + QString::number(ui->diameterSlider->value())+"\n");
    bot.send(tmp);
    tmp.clear();
    tmp = ("M401 S" + QString::number(ui->diameterSlider->value())+"\n");
    bot.send(tmp);
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
    if(b) ui->undoButton->setEnabled(true);
    else ui->undoButton->setEnabled(false);
}

void MainWindow::on_fileTextEdit_redoAvailable(bool b)
{
    if(b) ui->redoButton->setEnabled(true);
    else ui->redoButton->setEnabled(false);
}
