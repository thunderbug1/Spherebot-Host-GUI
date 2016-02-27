#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spherebot.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include "rxthread.h"
#include <QScrollBar>
#include <QTextCursor>
#include <QGraphicsSvgItem>
#include <QMessageBox>
#include <QStateMachine>
#include <QSerialPort>


#define DEFAULTDIAMETER 20
#define DEFAULTPENUP 40
#define DEFAULTPENDOWN 50
#define DEFAULTFEEDRATE 3000

#define MAXLISTITEMS 60

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void send_data();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectTranceiver();
    void disconnectTranceiver();
    bool LoadSettings();
    void SaveSettings();
    void initUI();
    void initSateMachine();
public slots:
    void processReceivedData(QString line);
    void sendDataUI(QString data);
//    void finishedTransmission();
    void refreshSendProgress(int value);
    void fitgraphicsView();
//    void finishedLayer();

//    void loadFileDialog();
private slots:
   // void hey(){qDebug()<<"hey"<<endl;}

    void resetPortList();
    void on_sendButton_released();
    void on_resetButton_clicked();
    void on_sendString_editingFinished();
    void on_servoSlider_sliderMoved(int position);
    void on_servospinBox_valueChanged(int arg1);
    void on_penRotationBox_valueChanged(int arg1);
    void on_eggRotationBox_valueChanged(int arg1);
    void on_saveFileButton_clicked();
    void on_fileTextEdit_textChanged();
    void on_servoFeedrateSlider_valueChanged(int value);
    void on_setDiameterButton_clicked();

    void interpretSentString(QString string);

    void on_sendString_textChanged(const QString &arg1);

    // state functions
    void entry_connected();
    void entry_try_connect();
    void entry_disconnected();
    void entry_transmitting();
    void entry_sending();
    void entry_start_sending();
    void entry_stopped();
    void entry_idle();
    void entry_abort();
    void entry_restart();
    void entry_ask_for_restart();
    void entry_ask_for_next_layer();
    void entry_load_file_dialog();

    void leave_sending();

    void loadFile(const QString &fileName);
//    void loadFileAndSubFiles(const QString &fileName);
    bool saveFile(const QString &fileName);

signals:
    void force_disconnect();
    void successfully_connected();
    void not_successfully_connected();

    void print_next_layer();
    void abort_print();

    void restart_print();
    void abort_restart_print();

public slots:
    void handle_port_error(QSerialPort::SerialPortError err);


private:

    void setCurrentFile(const QString &fileName);
    void interpretGcode(QString code);
    void refreshLayerNames(QString file);
    void SetBotToHomePosition();
    QString curFile;
    QDir curDir;

    Ui::MainWindow *ui;
    QSerialPortInfo PortInfo;
    QList<QSerialPortInfo> portList;
    spherebot *bot;
    rxThread *Receiver;
    QGraphicsScene *scene;
    QList<QString> layerNames;        //layerFile, layerColorString
    int layerIndex;

    QMessageBox *nextLayerMsgBox;
    QMessageBox *restartLayerMsgBox;

    int penUpAngle;
    int penDownAngle;

    QTimer FitInTimer;          //timer to trigger the fitIn function for the graphics view. Actually this shouldn´t be necessary!
    void extractOptions(QString file);

    QState *connected;
    QState *try_connect;
    QState *disconnected;
    QState *idle, *sending, *abort, *stopped, *restart, *start_sending;
    QState *ask_for_restart, *ask_for_next_layer, *load_file_dialog;
    QState *transmitting; //stopped or sending
    QStateMachine machine;
};

#endif // MAINWINDOW_H
