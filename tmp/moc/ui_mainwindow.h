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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QPushButton *iniciar_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *finalizar_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *referee_comando;
    QSpacerItem *verticalSpacer;
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
    QLabel *monitor;
    QLabel *connect_disconect;

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
        iniciar_2 = new QPushButton(layoutWidget);
        iniciar_2->setObjectName(QString::fromUtf8("iniciar_2"));

        gridLayout_4->addWidget(iniciar_2, 0, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(38, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        finalizar_2 = new QPushButton(layoutWidget);
        finalizar_2->setObjectName(QString::fromUtf8("finalizar_2"));

        gridLayout_4->addWidget(finalizar_2, 0, 3, 1, 2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(119, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 1, 1, 1, 4);

        referee_comando = new QLabel(layoutWidget);
        referee_comando->setObjectName(QString::fromUtf8("referee_comando"));
        referee_comando->setStyleSheet(QString::fromUtf8("border: 1px solid black;\n"
"border-radius: 5px;"));

        gridLayout_4->addWidget(referee_comando, 2, 0, 1, 4);

        verticalSpacer = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 2, 4, 1, 1);


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

        monitor = new QLabel(frame);
        monitor->setObjectName(QString::fromUtf8("monitor"));

        gridLayout_7->addWidget(monitor, 1, 0, 1, 1);

        connect_disconect = new QLabel(frame);
        connect_disconect->setObjectName(QString::fromUtf8("connect_disconect"));

        gridLayout_7->addWidget(connect_disconect, 2, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_15->addWidget(frame, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 2, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Lambe Sujo (Client)", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Estrat\303\251gia", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Interface com o vss-vision", nullptr));
        fps_medidor->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Atualiza\303\247\303\243o(ms):", nullptr));
        iniciar->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
        finalizar->setText(QCoreApplication::translate("MainWindow", "finalizar", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Interface com o VSSRefree", nullptr));
        iniciar_2->setText(QCoreApplication::translate("MainWindow", "iniciar", nullptr));
        finalizar_2->setText(QCoreApplication::translate("MainWindow", "finalizar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Comando:", nullptr));
        referee_comando->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Comunica\303\247\303\243o Serial", nullptr));
        conectar_serial->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Porta:", nullptr));
        atualiza_serial->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        status->setText(QString());
        monitor->setText(QString());
        connect_disconect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
