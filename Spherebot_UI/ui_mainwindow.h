/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
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
#include <QtWidgets/QToolBar>
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
    QHBoxLayout *horizontalLayout;
    QPushButton *connectButton;
    QComboBox *portBox;
    QPushButton *resetButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_9;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_10;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *sendString;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *txList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *rxList;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_12;
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
    QWidget *widget;
    QVBoxLayout *verticalLayout_14;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_16;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_17;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_15;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1492, 484);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        controllBox = new QGroupBox(centralWidget);
        controllBox->setObjectName(QStringLiteral("controllBox"));
        controllBox->setEnabled(false);
        controllBox->setGeometry(QRect(10, 60, 551, 231));
        controllBox->setCheckable(false);
        controllBox->setChecked(false);
        layoutWidget = new QWidget(controllBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(8, 0, 541, 221));
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
        servoFeedrateSlider->setValue(2000);
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
        FeedratespinBox->setValue(2000);

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

        layoutWidget->raise();
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 20, 275, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connectButton = new QPushButton(layoutWidget1);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setCheckable(false);

        horizontalLayout->addWidget(connectButton);

        portBox = new QComboBox(layoutWidget1);
        portBox->setObjectName(QStringLiteral("portBox"));

        horizontalLayout->addWidget(portBox);

        resetButton = new QPushButton(layoutWidget1);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_9 = new QVBoxLayout(layoutWidget2);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_10 = new QVBoxLayout(layoutWidget3);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 290, 541, 155));
        verticalLayout_11 = new QVBoxLayout(layoutWidget4);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sendString = new QLineEdit(layoutWidget4);
        sendString->setObjectName(QStringLiteral("sendString"));

        horizontalLayout_3->addWidget(sendString);

        sendButton = new QPushButton(layoutWidget4);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout_3->addWidget(sendButton);


        verticalLayout_11->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        txList = new QListWidget(layoutWidget4);
        txList->setObjectName(QStringLiteral("txList"));
        txList->setAutoScroll(false);
        txList->setSelectionMode(QAbstractItemView::NoSelection);

        verticalLayout->addWidget(txList);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        rxList = new QListWidget(layoutWidget4);
        rxList->setObjectName(QStringLiteral("rxList"));

        verticalLayout_2->addWidget(rxList);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_11->addLayout(horizontalLayout_2);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(570, 10, 461, 431));
        verticalLayout_12 = new QVBoxLayout(layoutWidget5);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));

        verticalLayout_8->addLayout(horizontalLayout_8);

        fileName = new QLabel(layoutWidget5);
        fileName->setObjectName(QStringLiteral("fileName"));

        verticalLayout_8->addWidget(fileName);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        undoButton = new QPushButton(layoutWidget5);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setEnabled(false);

        horizontalLayout_10->addWidget(undoButton);

        redoButton = new QPushButton(layoutWidget5);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setEnabled(false);

        horizontalLayout_10->addWidget(redoButton);


        verticalLayout_8->addLayout(horizontalLayout_10);

        fileTextEdit = new QTextEdit(layoutWidget5);
        fileTextEdit->setObjectName(QStringLiteral("fileTextEdit"));

        verticalLayout_8->addWidget(fileTextEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        loadFileButton = new QPushButton(layoutWidget5);
        loadFileButton->setObjectName(QStringLiteral("loadFileButton"));

        horizontalLayout_7->addWidget(loadFileButton);

        saveFileButton = new QPushButton(layoutWidget5);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setEnabled(false);

        horizontalLayout_7->addWidget(saveFileButton);

        sendFileButton = new QPushButton(layoutWidget5);
        sendFileButton->setObjectName(QStringLiteral("sendFileButton"));
        sendFileButton->setEnabled(false);

        horizontalLayout_7->addWidget(sendFileButton);

        restartButton = new QPushButton(layoutWidget5);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setEnabled(false);

        horizontalLayout_7->addWidget(restartButton);


        verticalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_12->addLayout(verticalLayout_8);

        fileSendProgressBar = new QProgressBar(layoutWidget5);
        fileSendProgressBar->setObjectName(QStringLiteral("fileSendProgressBar"));
        fileSendProgressBar->setEnabled(false);
        fileSendProgressBar->setValue(0);

        verticalLayout_12->addWidget(fileSendProgressBar);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(false);
        graphicsView->setGeometry(QRect(1040, 10, 441, 431));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_14 = new QVBoxLayout(widget);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_16 = new QVBoxLayout(widget1);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        widget2 = new QWidget(centralWidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_17 = new QVBoxLayout(widget2);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        widget3 = new QWidget(centralWidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_15 = new QHBoxLayout(widget3);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralWidget);
        controllBox->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        graphicsView->raise();
        layoutWidget->raise();
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        controllBox->setTitle(QString());
        setDiameterButton->setText(QApplication::translate("MainWindow", "set Diameter", 0));
        label_4->setText(QApplication::translate("MainWindow", "Obj. Diameter", 0));
        label_5->setText(QApplication::translate("MainWindow", "Feedrate", 0));
        label->setText(QApplication::translate("MainWindow", "Servo", 0));
        penslider->setText(QApplication::translate("MainWindow", "Pen Rotation", 0));
        penslider_2->setText(QApplication::translate("MainWindow", "Egg Rotation", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        resetButton->setText(QApplication::translate("MainWindow", "R", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        label_2->setText(QApplication::translate("MainWindow", "Tranceived Data", 0));
        label_3->setText(QApplication::translate("MainWindow", "Received Data", 0));
        fileName->setText(QString());
        undoButton->setText(QApplication::translate("MainWindow", "Undo", 0));
        redoButton->setText(QApplication::translate("MainWindow", "Redo", 0));
        loadFileButton->setText(QApplication::translate("MainWindow", "Load File", 0));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save File", 0));
        sendFileButton->setText(QApplication::translate("MainWindow", "Send File", 0));
        restartButton->setText(QApplication::translate("MainWindow", "Restart", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
