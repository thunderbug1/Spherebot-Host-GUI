/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *controllBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_15;
    QPushButton *setDiameterButton;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *verticalSpacer;
    QSlider *diameterSlider;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *diameterpinBox;
    QLabel *label_4;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *verticalSpacer_5;
    QSlider *servoFeedrateSlider;
    QSpacerItem *verticalSpacer_6;
    QSpinBox *FeedratespinBox;
    QLabel *label_5;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *verticalSpacer_7;
    QSlider *servoSlider;
    QSpacerItem *verticalSpacer_8;
    QSpinBox *servospinBox;
    QLabel *label;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSlider *penSlider;
    QHBoxLayout *horizontalLayout_5;
    QLabel *penslider;
    QSpinBox *penRotationBox;
    QSlider *eggSlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *penslider_2;
    QSpinBox *eggRotationBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_18;
    QLineEdit *sendString;
    QPushButton *sendButton;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QPushButton *connectButton;
    QComboBox *portBox;
    QPushButton *resetButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_9;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_10;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *txList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *rxList;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *fileName;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QTextEdit *fileTextEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *loadFileButton;
    QPushButton *saveFileButton;
    QPushButton *sendFileButton;
    QPushButton *restartButton;
    QProgressBar *fileSendProgressBar;
    QGraphicsView *graphicsView;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_14;
    QWidget *layoutWidget8;
    QVBoxLayout *verticalLayout_16;
    QWidget *layoutWidget9;
    QVBoxLayout *verticalLayout_17;
    QWidget *layoutWidget10;
    QHBoxLayout *horizontalLayout_15;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 550);
        MainWindow->setMinimumSize(QSize(1500, 550));
        MainWindow->setMaximumSize(QSize(1500, 550));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        controllBox = new QGroupBox(centralWidget);
        controllBox->setObjectName(QStringLiteral("controllBox"));
        controllBox->setEnabled(false);
        controllBox->setGeometry(QRect(20, 60, 531, 241));
        controllBox->setCheckable(false);
        controllBox->setChecked(false);
        layoutWidget = new QWidget(controllBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(8, 0, 499, 186));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        setDiameterButton = new QPushButton(layoutWidget);
        setDiameterButton->setObjectName(QStringLiteral("setDiameterButton"));

        verticalLayout_15->addWidget(setDiameterButton);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_9->addItem(verticalSpacer);

        diameterSlider = new QSlider(layoutWidget);
        diameterSlider->setObjectName(QStringLiteral("diameterSlider"));
        diameterSlider->setLayoutDirection(Qt::LeftToRight);
        diameterSlider->setMinimum(5);
        diameterSlider->setMaximum(120);
        diameterSlider->setValue(20);
        diameterSlider->setOrientation(Qt::Vertical);
        diameterSlider->setInvertedAppearance(false);

        horizontalLayout_9->addWidget(diameterSlider);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_9->addItem(verticalSpacer_2);


        verticalLayout_15->addLayout(horizontalLayout_9);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        diameterpinBox = new QSpinBox(layoutWidget);
        diameterpinBox->setObjectName(QStringLiteral("diameterpinBox"));
        diameterpinBox->setMinimum(5);
        diameterpinBox->setMaximum(120);
        diameterpinBox->setSingleStep(1);
        diameterpinBox->setValue(20);

        verticalLayout_7->addWidget(diameterpinBox);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_7->addWidget(label_4);


        verticalLayout_15->addLayout(verticalLayout_7);


        horizontalLayout_6->addLayout(verticalLayout_15);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_2);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_11->addItem(verticalSpacer_5);

        servoFeedrateSlider = new QSlider(layoutWidget);
        servoFeedrateSlider->setObjectName(QStringLiteral("servoFeedrateSlider"));
        servoFeedrateSlider->setLayoutDirection(Qt::LeftToRight);
        servoFeedrateSlider->setMinimum(10);
        servoFeedrateSlider->setMaximum(6000);
        servoFeedrateSlider->setValue(3000);
        servoFeedrateSlider->setOrientation(Qt::Vertical);
        servoFeedrateSlider->setInvertedAppearance(false);

        horizontalLayout_11->addWidget(servoFeedrateSlider);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_11->addItem(verticalSpacer_6);


        verticalLayout_13->addLayout(horizontalLayout_11);

        FeedratespinBox = new QSpinBox(layoutWidget);
        FeedratespinBox->setObjectName(QStringLiteral("FeedratespinBox"));
        FeedratespinBox->setMinimum(10);
        FeedratespinBox->setMaximum(6000);
        FeedratespinBox->setValue(3000);

        verticalLayout_13->addWidget(FeedratespinBox);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_13->addWidget(label_5);


        horizontalLayout_6->addLayout(verticalLayout_13);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_12->addItem(verticalSpacer_7);

        servoSlider = new QSlider(layoutWidget);
        servoSlider->setObjectName(QStringLiteral("servoSlider"));
        servoSlider->setLayoutDirection(Qt::LeftToRight);
        servoSlider->setMinimum(23);
        servoSlider->setMaximum(120);
        servoSlider->setValue(35);
        servoSlider->setOrientation(Qt::Vertical);
        servoSlider->setInvertedAppearance(true);

        horizontalLayout_12->addWidget(servoSlider);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_12->addItem(verticalSpacer_8);


        verticalLayout_3->addLayout(horizontalLayout_12);

        servospinBox = new QSpinBox(layoutWidget);
        servospinBox->setObjectName(QStringLiteral("servospinBox"));
        servospinBox->setMinimum(23);
        servospinBox->setMaximum(120);
        servospinBox->setValue(35);

        verticalLayout_3->addWidget(servospinBox);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        penSlider = new QSlider(layoutWidget);
        penSlider->setObjectName(QStringLiteral("penSlider"));
        penSlider->setMinimum(-112);
        penSlider->setMaximum(112);
        penSlider->setSingleStep(1);
        penSlider->setValue(0);
        penSlider->setSliderPosition(0);
        penSlider->setOrientation(Qt::Horizontal);
        penSlider->setInvertedAppearance(true);

        verticalLayout_4->addWidget(penSlider);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        penslider = new QLabel(layoutWidget);
        penslider->setObjectName(QStringLiteral("penslider"));

        horizontalLayout_5->addWidget(penslider);

        penRotationBox = new QSpinBox(layoutWidget);
        penRotationBox->setObjectName(QStringLiteral("penRotationBox"));
        penRotationBox->setMinimum(-112);
        penRotationBox->setMaximum(112);
        penRotationBox->setSingleStep(1);

        horizontalLayout_5->addWidget(penRotationBox);


        verticalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_4);

        eggSlider = new QSlider(layoutWidget);
        eggSlider->setObjectName(QStringLiteral("eggSlider"));
        eggSlider->setMinimum(-450);
        eggSlider->setMaximum(450);
        eggSlider->setValue(0);
        eggSlider->setSliderPosition(0);
        eggSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(eggSlider);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        penslider_2 = new QLabel(layoutWidget);
        penslider_2->setObjectName(QStringLiteral("penslider_2"));

        horizontalLayout_4->addWidget(penslider_2);

        eggRotationBox = new QSpinBox(layoutWidget);
        eggRotationBox->setObjectName(QStringLiteral("eggRotationBox"));
        eggRotationBox->setMinimum(-450);
        eggRotationBox->setMaximum(450);

        horizontalLayout_4->addWidget(eggRotationBox);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_6);

        layoutWidget1 = new QWidget(controllBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 200, 501, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));

        horizontalLayout_3->addLayout(verticalLayout_18);

        sendString = new QLineEdit(layoutWidget1);
        sendString->setObjectName(QStringLiteral("sendString"));

        horizontalLayout_3->addWidget(sendString);

        sendButton = new QPushButton(layoutWidget1);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_3->addWidget(sendButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 20, 531, 32));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget2);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setCheckable(false);

        gridLayout->addWidget(connectButton, 0, 0, 1, 1);

        portBox = new QComboBox(layoutWidget2);
        portBox->setObjectName(QStringLiteral("portBox"));

        gridLayout->addWidget(portBox, 0, 1, 1, 1);

        resetButton = new QPushButton(layoutWidget2);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        gridLayout->addWidget(resetButton, 0, 2, 1, 1);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_9 = new QVBoxLayout(layoutWidget3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_10 = new QVBoxLayout(layoutWidget4);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 310, 530, 201));
        gridLayout_3 = new QGridLayout(layoutWidget5);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(layoutWidget5);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        txList = new QListWidget(layoutWidget5);
        txList->setObjectName(QStringLiteral("txList"));
        txList->setAutoScroll(true);
        txList->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(txList);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget5);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        rxList = new QListWidget(layoutWidget5);
        rxList->setObjectName(QStringLiteral("rxList"));

        verticalLayout_2->addWidget(rxList);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(590, 20, 411, 491));
        gridLayout_2 = new QGridLayout(layoutWidget6);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_8->addLayout(horizontalLayout_8);

        fileName = new QLabel(layoutWidget6);
        fileName->setObjectName(QStringLiteral("fileName"));

        verticalLayout_8->addWidget(fileName);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        undoButton = new QPushButton(layoutWidget6);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setEnabled(false);

        horizontalLayout_10->addWidget(undoButton);

        redoButton = new QPushButton(layoutWidget6);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setEnabled(false);

        horizontalLayout_10->addWidget(redoButton);


        verticalLayout_8->addLayout(horizontalLayout_10);

        fileTextEdit = new QTextEdit(layoutWidget6);
        fileTextEdit->setObjectName(QStringLiteral("fileTextEdit"));

        verticalLayout_8->addWidget(fileTextEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        loadFileButton = new QPushButton(layoutWidget6);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));

        horizontalLayout_7->addWidget(loadFileButton);

        saveFileButton = new QPushButton(layoutWidget6);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setEnabled(false);

        horizontalLayout_7->addWidget(saveFileButton);

        sendFileButton = new QPushButton(layoutWidget6);
        sendFileButton->setObjectName(QStringLiteral("sendFileButton"));
        sendFileButton->setEnabled(false);

        horizontalLayout_7->addWidget(sendFileButton);

        restartButton = new QPushButton(layoutWidget6);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setEnabled(false);

        horizontalLayout_7->addWidget(restartButton);


        verticalLayout_8->addLayout(horizontalLayout_7);


        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);

        fileSendProgressBar = new QProgressBar(layoutWidget6);
        fileSendProgressBar->setObjectName(QStringLiteral("fileSendProgressBar"));
        fileSendProgressBar->setEnabled(false);
        fileSendProgressBar->setValue(0);

        gridLayout_2->addWidget(fileSendProgressBar, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setGeometry(QRect(1020, 20, 461, 491));
        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_14 = new QVBoxLayout(layoutWidget7);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        layoutWidget8 = new QWidget(centralWidget);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_16 = new QVBoxLayout(layoutWidget8);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        layoutWidget9 = new QWidget(centralWidget);
        layoutWidget9->setObjectName(QStringLiteral("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_17 = new QVBoxLayout(layoutWidget9);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        layoutWidget10 = new QWidget(centralWidget);
        layoutWidget10->setObjectName(QStringLiteral("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget10);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        controllBox->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        graphicsView->raise();
        layoutWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(diameterSlider, SIGNAL(valueChanged(int)), diameterpinBox, SLOT(setValue(int)));
        QObject::connect(diameterpinBox, SIGNAL(valueChanged(int)), diameterSlider, SLOT(setValue(int)));
        QObject::connect(servospinBox, SIGNAL(valueChanged(int)), servoSlider, SLOT(setValue(int)));
        QObject::connect(servoSlider, SIGNAL(valueChanged(int)), servospinBox, SLOT(setValue(int)));
        QObject::connect(penRotationBox, SIGNAL(valueChanged(int)), penSlider, SLOT(setValue(int)));
        QObject::connect(penSlider, SIGNAL(valueChanged(int)), penRotationBox, SLOT(setValue(int)));
        QObject::connect(eggRotationBox, SIGNAL(valueChanged(int)), eggSlider, SLOT(setValue(int)));
        QObject::connect(eggSlider, SIGNAL(valueChanged(int)), eggRotationBox, SLOT(setValue(int)));
        QObject::connect(servoFeedrateSlider, SIGNAL(valueChanged(int)), FeedratespinBox, SLOT(setValue(int)));
        QObject::connect(FeedratespinBox, SIGNAL(valueChanged(int)), servoFeedrateSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        controllBox->setTitle(QString());
        setDiameterButton->setText(QApplication::translate("MainWindow", "set Diameter", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Obj. Diameter", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Feedrate", nullptr));
        label->setText(QApplication::translate("MainWindow", "Servo", nullptr));
        penslider->setText(QApplication::translate("MainWindow", "Pen Rotation", nullptr));
        penslider_2->setText(QApplication::translate("MainWindow", "Egg Rotation", nullptr));
        sendButton->setText(QApplication::translate("MainWindow", "Send", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        resetButton->setText(QApplication::translate("MainWindow", "Reset portlist", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Sent Data", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Received Data", nullptr));
        fileName->setText(QString());
        undoButton->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        redoButton->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        loadFileButton->setText(QApplication::translate("MainWindow", "Load File", nullptr));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", nullptr));
        sendFileButton->setText(QApplication::translate("MainWindow", "Send File", nullptr));
        restartButton->setText(QApplication::translate("MainWindow", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
