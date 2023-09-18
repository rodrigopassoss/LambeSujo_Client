/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <utils/qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_27;
    QComboBox *tipo_plot_2;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_31;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_29;
    QGridLayout *gridLayout_26;
    QLabel *label_16;
    QLCDNumber *leitura_vl;
    QGridLayout *gridLayout_28;
    QLabel *label_17;
    QLCDNumber *leitura_vr;
    QCheckBox *habilita_leitura;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_19;
    QGridLayout *gridLayout_17;
    QSlider *slider_vl;
    QLabel *label_7;
    QLabel *label_9;
    QSlider *slider_vr;
    QSpinBox *spin_vl;
    QSpinBox *spin_vr;
    QGridLayout *gridLayout_18;
    QLabel *label_10;
    QComboBox *selRobo;
    QCheckBox *habilita_plot_3;
    QCustomPlot *plot3;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_13;
    QCustomPlot *plot1;
    QCustomPlot *plot2;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_10;
    QLabel *label_4;
    QComboBox *tipos_variaveis;
    QLabel *label_5;
    QComboBox *time;
    QGridLayout *gridLayout_11;
    QLabel *label_6;
    QComboBox *objetos;
    QCheckBox *habilita_plot;
    QCheckBox *salvar_em_txt;
    QWidget *tab_2;
    QGridLayout *gridLayout_35;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_34;
    QGridLayout *gridLayout_33;
    QGridLayout *gridLayout_32;
    QGridLayout *gridLayout_25;
    QGridLayout *gridLayout_22;
    QLabel *label_12;
    QComboBox *sel_estrategia;
    QSpacerItem *horizontalSpacer_9;
    QFrame *line;
    QGridLayout *gridLayout_21;
    QLabel *label_13;
    QComboBox *sel_atacante;
    QLabel *label_14;
    QComboBox *sel_zagueiro;
    QLabel *label_15;
    QComboBox *sel_goleiro;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_2;
    QGridLayout *gridLayout_24;
    QPushButton *iniciar_3;
    QPushButton *finalizar_3;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_20;
    QLabel *label_11;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *fps_medidor;
    QLabel *label;
    QPushButton *iniciar;
    QSpacerItem *horizontalSpacer;
    QPushButton *finalizar;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *finalizar_2;
    QLabel *referee_comando;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *iniciar_2;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_16;
    QGridLayout *gridLayout_15;
    QGridLayout *gridLayout_5;
    QPushButton *conectar_serial;
    QLabel *label_3;
    QComboBox *portas_usb;
    QPushButton *atualiza_serial;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QLabel *status;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(668, 481);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icone/gpr.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_6 = new QGridLayout(centralwidget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabBarAutoHide(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_27 = new QGridLayout(tab_3);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        tipo_plot_2 = new QComboBox(tab_3);
        tipo_plot_2->addItem(QString());
        tipo_plot_2->addItem(QString());
        tipo_plot_2->addItem(QString());
        tipo_plot_2->setObjectName(QString::fromUtf8("tipo_plot_2"));

        gridLayout_27->addWidget(tipo_plot_2, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_31 = new QGridLayout(groupBox_6);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout_30 = new QGridLayout();
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_29 = new QGridLayout();
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_26 = new QGridLayout();
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        label_16 = new QLabel(groupBox_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_26->addWidget(label_16, 0, 0, 1, 1);

        leitura_vl = new QLCDNumber(groupBox_6);
        leitura_vl->setObjectName(QString::fromUtf8("leitura_vl"));

        gridLayout_26->addWidget(leitura_vl, 0, 1, 1, 1);


        gridLayout_29->addLayout(gridLayout_26, 0, 0, 1, 1);

        gridLayout_28 = new QGridLayout();
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_28->addWidget(label_17, 0, 0, 1, 1);

        leitura_vr = new QLCDNumber(groupBox_6);
        leitura_vr->setObjectName(QString::fromUtf8("leitura_vr"));

        gridLayout_28->addWidget(leitura_vr, 0, 1, 1, 1);


        gridLayout_29->addLayout(gridLayout_28, 0, 1, 1, 1);


        gridLayout_30->addLayout(gridLayout_29, 0, 0, 1, 1);

        habilita_leitura = new QCheckBox(groupBox_6);
        habilita_leitura->setObjectName(QString::fromUtf8("habilita_leitura"));

        gridLayout_30->addWidget(habilita_leitura, 1, 0, 1, 1);


        gridLayout_31->addLayout(gridLayout_30, 0, 0, 1, 1);


        gridLayout_27->addWidget(groupBox_6, 3, 0, 1, 4);

        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_19 = new QGridLayout(groupBox_4);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_17 = new QGridLayout();
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        slider_vl = new QSlider(groupBox_4);
        slider_vl->setObjectName(QString::fromUtf8("slider_vl"));
        slider_vl->setMinimum(-100);
        slider_vl->setMaximum(100);
        slider_vl->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_vl, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_17->addWidget(label_7, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_17->addWidget(label_9, 1, 0, 1, 1);

        slider_vr = new QSlider(groupBox_4);
        slider_vr->setObjectName(QString::fromUtf8("slider_vr"));
        slider_vr->setMinimum(-100);
        slider_vr->setMaximum(100);
        slider_vr->setOrientation(Qt::Horizontal);

        gridLayout_17->addWidget(slider_vr, 1, 1, 1, 1);

        spin_vl = new QSpinBox(groupBox_4);
        spin_vl->setObjectName(QString::fromUtf8("spin_vl"));
        spin_vl->setMinimum(-100);
        spin_vl->setMaximum(100);

        gridLayout_17->addWidget(spin_vl, 0, 2, 1, 1);

        spin_vr = new QSpinBox(groupBox_4);
        spin_vr->setObjectName(QString::fromUtf8("spin_vr"));
        spin_vr->setMinimum(-100);
        spin_vr->setMaximum(100);

        gridLayout_17->addWidget(spin_vr, 1, 2, 1, 1);


        gridLayout_19->addLayout(gridLayout_17, 0, 0, 1, 1);

        gridLayout_18 = new QGridLayout();
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_18->addWidget(label_10, 0, 0, 1, 1);

        selRobo = new QComboBox(groupBox_4);
        selRobo->addItem(QString());
        selRobo->addItem(QString());
        selRobo->addItem(QString());
        selRobo->addItem(QString());
        selRobo->setObjectName(QString::fromUtf8("selRobo"));

        gridLayout_18->addWidget(selRobo, 1, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_18, 0, 1, 1, 1);


        gridLayout_27->addWidget(groupBox_4, 2, 0, 1, 4);

        habilita_plot_3 = new QCheckBox(tab_3);
        habilita_plot_3->setObjectName(QString::fromUtf8("habilita_plot_3"));

        gridLayout_27->addWidget(habilita_plot_3, 1, 3, 1, 1);

        plot3 = new QCustomPlot(tab_3);
        plot3->setObjectName(QString::fromUtf8("plot3"));

        gridLayout_27->addWidget(plot3, 0, 0, 1, 4);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_27->addWidget(label_8, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_27->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_14 = new QGridLayout(tab);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        plot1 = new QCustomPlot(tab);
        plot1->setObjectName(QString::fromUtf8("plot1"));

        gridLayout_13->addWidget(plot1, 0, 0, 1, 1);

        plot2 = new QCustomPlot(tab);
        plot2->setObjectName(QString::fromUtf8("plot2"));

        gridLayout_13->addWidget(plot2, 1, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_10->addWidget(label_4, 0, 0, 1, 1);

        tipos_variaveis = new QComboBox(tab);
        tipos_variaveis->addItem(QString());
        tipos_variaveis->addItem(QString());
        tipos_variaveis->setObjectName(QString::fromUtf8("tipos_variaveis"));

        gridLayout_10->addWidget(tipos_variaveis, 0, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_10->addWidget(label_5, 1, 0, 1, 1);

        time = new QComboBox(tab);
        time->addItem(QString());
        time->addItem(QString());
        time->setObjectName(QString::fromUtf8("time"));

        gridLayout_10->addWidget(time, 1, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_10, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_11->addWidget(label_6, 0, 0, 1, 1);

        objetos = new QComboBox(tab);
        objetos->addItem(QString());
        objetos->addItem(QString());
        objetos->addItem(QString());
        objetos->addItem(QString());
        objetos->addItem(QString());
        objetos->setObjectName(QString::fromUtf8("objetos"));

        gridLayout_11->addWidget(objetos, 0, 1, 1, 1);

        habilita_plot = new QCheckBox(tab);
        habilita_plot->setObjectName(QString::fromUtf8("habilita_plot"));

        gridLayout_11->addWidget(habilita_plot, 1, 0, 1, 2);


        gridLayout_12->addLayout(gridLayout_11, 0, 1, 1, 1);

        salvar_em_txt = new QCheckBox(tab);
        salvar_em_txt->setObjectName(QString::fromUtf8("salvar_em_txt"));

        gridLayout_12->addWidget(salvar_em_txt, 1, 0, 1, 2);


        gridLayout_13->addLayout(gridLayout_12, 2, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_35 = new QGridLayout(tab_2);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_34 = new QGridLayout(groupBox_5);
        gridLayout_34->setObjectName(QString::fromUtf8("gridLayout_34"));
        gridLayout_33 = new QGridLayout();
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_32 = new QGridLayout();
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_25 = new QGridLayout();
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_22 = new QGridLayout();
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        label_12 = new QLabel(groupBox_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_22->addWidget(label_12, 0, 0, 1, 1);

        sel_estrategia = new QComboBox(groupBox_5);
        sel_estrategia->setObjectName(QString::fromUtf8("sel_estrategia"));

        gridLayout_22->addWidget(sel_estrategia, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(186, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_22->addItem(horizontalSpacer_9, 1, 1, 1, 1);


        gridLayout_25->addLayout(gridLayout_22, 0, 0, 1, 1);

        line = new QFrame(groupBox_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_25->addWidget(line, 1, 0, 1, 1);


        gridLayout_32->addLayout(gridLayout_25, 0, 0, 1, 1);

        gridLayout_21 = new QGridLayout();
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_21->addWidget(label_13, 0, 0, 1, 1);

        sel_atacante = new QComboBox(groupBox_5);
        sel_atacante->setObjectName(QString::fromUtf8("sel_atacante"));

        gridLayout_21->addWidget(sel_atacante, 0, 1, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_21->addWidget(label_14, 1, 0, 1, 1);

        sel_zagueiro = new QComboBox(groupBox_5);
        sel_zagueiro->setObjectName(QString::fromUtf8("sel_zagueiro"));

        gridLayout_21->addWidget(sel_zagueiro, 1, 1, 1, 1);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_21->addWidget(label_15, 2, 0, 1, 1);

        sel_goleiro = new QComboBox(groupBox_5);
        sel_goleiro->setObjectName(QString::fromUtf8("sel_goleiro"));

        gridLayout_21->addWidget(sel_goleiro, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(186, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_5, 3, 1, 1, 1);


        gridLayout_32->addLayout(gridLayout_21, 1, 0, 1, 1);


        gridLayout_33->addLayout(gridLayout_32, 0, 0, 1, 1);

        line_2 = new QFrame(groupBox_5);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_33->addWidget(line_2, 1, 0, 1, 1);

        gridLayout_24 = new QGridLayout();
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        iniciar_3 = new QPushButton(groupBox_5);
        iniciar_3->setObjectName(QString::fromUtf8("iniciar_3"));

        gridLayout_24->addWidget(iniciar_3, 0, 0, 1, 1);

        finalizar_3 = new QPushButton(groupBox_5);
        finalizar_3->setObjectName(QString::fromUtf8("finalizar_3"));

        gridLayout_24->addWidget(finalizar_3, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_24->addItem(horizontalSpacer_8, 0, 2, 1, 1);

        gridLayout_20 = new QGridLayout();
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_20->addWidget(label_11, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox_5);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_20->addWidget(comboBox, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(183, 14, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_20->addItem(horizontalSpacer_7, 1, 1, 1, 1);


        gridLayout_24->addLayout(gridLayout_20, 1, 0, 1, 3);


        gridLayout_33->addLayout(gridLayout_24, 2, 0, 1, 1);


        gridLayout_34->addLayout(gridLayout_33, 0, 0, 1, 1);


        gridLayout_35->addWidget(groupBox_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 668, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_9 = new QGridLayout(dockWidgetContents_2);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        groupBox = new QGroupBox(dockWidgetContents_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        fps_medidor = new QLabel(groupBox);
        fps_medidor->setObjectName(QString::fromUtf8("fps_medidor"));
        fps_medidor->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(fps_medidor, 1, 2, 1, 2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 2);

        iniciar = new QPushButton(groupBox);
        iniciar->setObjectName(QString::fromUtf8("iniciar"));

        gridLayout->addWidget(iniciar, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 2);

        finalizar = new QPushButton(groupBox);
        finalizar->setObjectName(QString::fromUtf8("finalizar"));

        gridLayout->addWidget(finalizar, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(dockWidgetContents_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(13, 30, 221, 91));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        finalizar_2 = new QPushButton(layoutWidget);
        finalizar_2->setObjectName(QString::fromUtf8("finalizar_2"));

        gridLayout_4->addWidget(finalizar_2, 0, 3, 1, 2);

        referee_comando = new QLabel(layoutWidget);
        referee_comando->setObjectName(QString::fromUtf8("referee_comando"));
        referee_comando->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(referee_comando, 2, 0, 1, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(38, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        iniciar_2 = new QPushButton(layoutWidget);
        iniciar_2->setObjectName(QString::fromUtf8("iniciar_2"));

        gridLayout_4->addWidget(iniciar_2, 0, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(119, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 1, 1, 4);


        gridLayout_9->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(dockWidgetContents_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_16 = new QGridLayout(groupBox_3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        conectar_serial = new QPushButton(groupBox_3);
        conectar_serial->setObjectName(QString::fromUtf8("conectar_serial"));

        gridLayout_5->addWidget(conectar_serial, 0, 0, 1, 2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        portas_usb = new QComboBox(groupBox_3);
        portas_usb->setObjectName(QString::fromUtf8("portas_usb"));

        gridLayout_5->addWidget(portas_usb, 1, 1, 1, 1);

        atualiza_serial = new QPushButton(groupBox_3);
        atualiza_serial->setObjectName(QString::fromUtf8("atualiza_serial"));

        gridLayout_5->addWidget(atualiza_serial, 2, 0, 1, 2);


        gridLayout_15->addLayout(gridLayout_5, 0, 0, 1, 1);

        frame = new QFrame(groupBox_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        status = new QLabel(frame);
        status->setObjectName(QString::fromUtf8("status"));

        gridLayout_7->addWidget(status, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_15->addWidget(frame, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 2, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);
        QObject::connect(spin_vl, SIGNAL(valueChanged(int)), slider_vl, SLOT(setValue(int)));
        QObject::connect(spin_vr, SIGNAL(valueChanged(int)), slider_vr, SLOT(setValue(int)));
        QObject::connect(slider_vl, SIGNAL(valueChanged(int)), spin_vl, SLOT(setValue(int)));
        QObject::connect(slider_vr, SIGNAL(valueChanged(int)), spin_vr, SLOT(setValue(int)));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lambe Sujo (Client)", nullptr));
        tipo_plot_2->setItemText(0, QCoreApplication::translate("MainWindow", "VL", nullptr));
        tipo_plot_2->setItemText(1, QCoreApplication::translate("MainWindow", "VR", nullptr));
        tipo_plot_2->setItemText(2, QCoreApplication::translate("MainWindow", "Ambos", nullptr));

        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Ler velocidades", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "VL:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "VR:", nullptr));
        habilita_leitura->setText(QCoreApplication::translate("MainWindow", "Ler ", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Enviar Comandos", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "VL", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "VR", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Rob\303\264:", nullptr));
        selRobo->setItemText(0, QCoreApplication::translate("MainWindow", "Todos", nullptr));
        selRobo->setItemText(1, QCoreApplication::translate("MainWindow", "robo1", nullptr));
        selRobo->setItemText(2, QCoreApplication::translate("MainWindow", "robo2", nullptr));
        selRobo->setItemText(3, QCoreApplication::translate("MainWindow", "robo3", nullptr));

        habilita_plot_3->setText(QCoreApplication::translate("MainWindow", "Habilitar Plot", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Plot: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Comunica\303\247\303\243o", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Vari\303\241veis:", nullptr));
        tipos_variaveis->setItemText(0, QCoreApplication::translate("MainWindow", "posi\303\247\303\243o", nullptr));
        tipos_variaveis->setItemText(1, QCoreApplication::translate("MainWindow", "velocidade", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Times:", nullptr));
        time->setItemText(0, QCoreApplication::translate("MainWindow", "azul", nullptr));
        time->setItemText(1, QCoreApplication::translate("MainWindow", "amarelo", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "Objeto:", nullptr));
        objetos->setItemText(0, QCoreApplication::translate("MainWindow", "bola", nullptr));
        objetos->setItemText(1, QCoreApplication::translate("MainWindow", "robo1", nullptr));
        objetos->setItemText(2, QCoreApplication::translate("MainWindow", "robo2", nullptr));
        objetos->setItemText(3, QCoreApplication::translate("MainWindow", "robo3", nullptr));
        objetos->setItemText(4, QCoreApplication::translate("MainWindow", "Todos", nullptr));

        habilita_plot->setText(QCoreApplication::translate("MainWindow", "Habilita Plot", nullptr));
        salvar_em_txt->setText(QCoreApplication::translate("MainWindow", "Salvar experimento em txt", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Plots", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Menu ", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Estrat\303\251gia:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Atacante:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Zagueiro:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Goleiro:", nullptr));
        iniciar_3->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
        finalizar_3->setText(QCoreApplication::translate("MainWindow", "Finalizar", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Nosso time:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "azul", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "amarelo", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Estrat\303\251gia", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Interface com o vss-vision", nullptr));
        fps_medidor->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Atualiza\303\247\303\243o(ms):", nullptr));
        iniciar->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
        finalizar->setText(QCoreApplication::translate("MainWindow", "finalizar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Interface com o VSSRefree", nullptr));
        finalizar_2->setText(QCoreApplication::translate("MainWindow", "finalizar", nullptr));
        referee_comando->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Comando:", nullptr));
        iniciar_2->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Comunica\303\247\303\243o Serial", nullptr));
        conectar_serial->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Porta:", nullptr));
        atualiza_serial->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
