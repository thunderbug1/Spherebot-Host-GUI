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
#include "txthread.h"
#include "rxthread.h"
#include <QScrollBar>
#include <QTextCursor>
#include <QGraphicsSvgItem>
#include <QMessageBox>


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

    enum SendStates{Idle=0,Sending=1,Stoped=2};
    
public:
    void send_data();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectTranceiver();
    void disconnectTranceiver();
    bool LoadSettings();
    void SaveSettings();
    void initUI();
    void setState(SendStates state);
public slots:
    void processReceivedData(QString line);
    void sendDataUI(QString data);
    void finishedTransmission();
    void refreshSendProgress(int value);
    void fitgraphicsView();
    void finishedLayer();

private slots:
    void on_connectButton_clicked();
    void resetPortList();
    void on_sendButton_clicked();
    void on_resetButton_clicked();
    void on_sendString_editingFinished();
    void on_servoSlider_sliderMoved(int position);
    void on_servospinBox_valueChanged(int arg1);
    void on_penSlider_valueChanged(int value);
    void on_eggSlider_valueChanged(int value);
    void on_penRotationBox_valueChanged(int arg1);
    void on_eggRotationBox_valueChanged(int arg1);
    void on_loadFileButton_clicked();
    void on_saveFileButton_clicked();
    void on_fileTextEdit_textChanged();
    void on_sendFileButton_clicked();
    void on_servoFeedrateSlider_valueChanged(int value);
    void on_setDiameterButton_clicked();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_fileTextEdit_undoAvailable(bool b);
    void on_fileTextEdit_redoAvailable(bool b);
    void on_restartButton_clicked();

    void interpretSentString(QString string);

    void on_sendString_textChanged(const QString &arg1);

    void on_baudBox_currentIndexChanged(int index);

private:

    void loadFile(const QString &fileName);
    void loadFileAndSubFiles(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    void interpretGcode(QString code);
    void refreshLayerNames(QString file);
    void SetBotToHomePosition();
    QString curFile;
    QDir curDir;
    SendStates sendState;

    Ui::MainWindow *ui;
    QSerialPortInfo PortInfo;
    QList<QSerialPortInfo> portList;
    spherebot *bot;
    QTimer *rxTimer;
    txThread *Transceiver;
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
};

#endif // MAINWINDOW_H
