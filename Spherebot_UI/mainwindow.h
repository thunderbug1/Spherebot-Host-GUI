#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spherebot.h"
#include "qextserialenumerator.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include "txthread.h"
#include <QScrollBar>
#include <QTextCursor>
#include <QGraphicsSvgItem>


#define DEFAULTDIAMETER 20
#define DEFAULTPENUP 35
#define DEFAULTFEEDRATE 2000

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
signals:
    void receivedLine(QString);
public slots:
    void receiveData();
    void sendData(QString data);
    void finishedTransmission();
    void refreshSendProgress(int value);

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

private:

    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString curFile;
    int sendState;

    QString nameSettingsFile;
    Ui::MainWindow *ui;
    QextSerialEnumerator serialEnumerator;
    QList<QextPortInfo> portList;
    spherebot bot;
    QTimer *rxTimer;
    txThread Transceiver;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
