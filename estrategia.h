#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "vision.h"
#include "time.h"
#include "refereeclient.h"
#include <math.h>


class estrategia
{
private:

    //Informações
    Position ball_pos; Velocity ball_vel;
    Position meu_time_pos[3];double meu_time_ori[3];Velocity meu_time_vel[3];
    Position adversario_pos[3];double adversario_ori[3];Velocity adversario_vel[3];

    int nossaCor,qtdRobos;
    double L,R;
    double vrMax,Vmax,Wmax;

public:
    estrategia(int time);

    void controle_e_navegacao();
    void atualiza_posicoes(QVector<int> _indice, Position *_rblue_pos, double *_rblue_ori,Velocity *_rblue_vel,
                           Position *_ryellow_pos, double *_ryellow_ori,Velocity *_ryellow_vel,
                           Position _ball_pos, Velocity _ball_vel);

    //Velocidades das rodas de cada robô
    QVector<int> indice;
    QVector<double> vL;
    QVector<double> vR;

};

#endif // ESTRATEGIA_H
