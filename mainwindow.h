#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QImage>
#include <QFileDialog>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "vision.h"
#include "time.h"
#include "refereeclient.h"
#include "utils/qcustomplot.h"
#include "Communication.h"
#include "math.h"
#include "estrategia.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *cronometro;
    QTimer *cronometro2;
    Vision *visionClient;
    RefereeClient *refereeClient;

    Constants *constants;
    Constants* getConstants();

    //Coisas da comunicação
    communication *SerialComm;
    void info_ports();

    //Informações
    Position ball_pos; Velocity ball_vel;
    Position rblue_pos[3];double rblue_ori[3];Velocity rblue_vel[3];
    Position ryellow_pos[3];double ryellow_ori[3];Velocity ryellow_vel[3];

    //Plot das Velocidades
    void plot();
    void get_data_plot();
    void Defplot();
    void limpar_plots();
    QString label_x,label_y;
    int tipo_plot, objeto_plot, cor_plot;
    QVector<double> *t_data;
    QVector<double> *x1_data,*x2_data,*x3_data;
    QVector<double> *y1_data,*y2_data,*y3_data;


    //Contagem de FPS
    double fps, start, fim;

    //Função para enviar comandos para as rodas
    void sendCommand(QVector<int> index,float vL[], float vR[]);

    //Estratégia
    int time_estrategia;
    estrategia *azul, *amarelo;


private slots:

    void on_iniciar_clicked();

    void updateData();

    void updateFPS();

    void updateReferee();

    void on_iniciar_2_clicked();

    void on_conectar_serial_clicked();

    void on_atualiza_serial_clicked();

    void on_tipos_variaveis_currentIndexChanged(int index);

    void on_objetos_currentIndexChanged(int index);

    void on_time_currentIndexChanged(int index);

    void on_slider_vl_valueChanged(int value);

    void on_slider_vr_valueChanged(int value);

    void on_finalizar_clicked();

    void on_finalizar_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
