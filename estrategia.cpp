#include "estrategia.h"

estrategia::estrategia(int time)
{

    this->nossaCor = time;


    qtdRobos = 3;
    // Constantes de Modelo
    L = 3.75e-2; //Distância entre roda e centro
    R = 3.035e-2; /*3.035e-2 m*/
    vrMax = 43.3;  // rad/s
    Vmax = (1.31)/2.0; // 1.31 m/s
    Wmax = (35.0)/8.0; // 35.0 rad/s

    for(int i=0;i<qtdRobos;i++)
    {
        this->vL.insert(i,0);
        this->vR.insert(i,0);
    }

    if(time==VSSRef::BLUE)
    {
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Estratégia para o time azul criada!") + '\n';
    }else
    {
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Estratégia para o time amarelo criada!") + '\n';
    }

}

void estrategia::controle_e_navegacao()
{
    // Bola como Ponto de destino
    double x_des = this->ball_pos.x();
    double y_des = this->ball_pos.y();

    //Distância do Robô 0 para o destino
    double d = sqrt(pow((meu_time_pos[0].x()-x_des),2)
                +  pow((meu_time_pos[0].y()-y_des),2));
    std::cout << "Distância: "<< d << "\n";

    //Erro angular do Robô 0 para o destino
    double err = atan2(y_des-meu_time_pos[0].y(),
                      x_des-meu_time_pos[0].x())-meu_time_ori[0];
    // Coloca o erro de -Pi a Pi para "tirar" a discontinuidade
    if(err>M_PI)
    {
        err = err - 2*M_PI;
    }
    else if(err<-M_PI)
    {
        err = err + 2*M_PI;
    };
    std::cout << "Erro angular: "<< err << "\n";

    //Calculo de V e W
    double kv2 = 2.1;
    double V = (Vmax*tanh(kv2*d))*(cos(err)==0?1:(cos(err)/abs(cos(err))));
    //double V = 0.25*tanh(kv2*d);
    double kw2 = 0.67;
    double W = Wmax*tanh(kw2*err)*abs(sin(err));



    //double W = 0.1*tanh(kw2*err);
    std::cout << "Velocidade Linear: "<< V << "\n";
    std::cout << "Velocidade Angular: "<< W << "\n";

    //Modelo cinemático das rodas
    //double f_norm = Vmax/R;
    vR.insert(0,((V-W*L)/R)/vrMax);
    vL.insert(0,((V+W*L)/R)/vrMax);
    //vR.insert(0,(V-W));
    //vL.insert(0,(V+W));
}

void estrategia::atualiza_posicoes(QVector<int> _indice, Position *_rblue_pos, double *_rblue_ori, Velocity *_rblue_vel,
                                                         Position *_ryellow_pos, double *_ryellow_ori, Velocity *_ryellow_vel,
                                                         Position _ball_pos, Velocity _ball_vel)
{
    this->indice = _indice;

    if(this->nossaCor==VSSRef::BLUE)
    {
        for(int i=0;i<this->qtdRobos;i++)
        {
            this->meu_time_pos[i] = _rblue_pos[i];
            this->meu_time_ori[i] = _rblue_ori[i];
            this->meu_time_vel[i] = _rblue_vel[i];
            this->adversario_pos[i] = _ryellow_pos[i];
            this->adversario_ori[i] = _ryellow_ori[i];
            this->adversario_vel[i] = _ryellow_vel[i];
        }
    }else
    {
        for(int i=0;i<this->qtdRobos;i++)
        {
            this->meu_time_pos[i] = _ryellow_pos[i];
            this->meu_time_ori[i] = _ryellow_ori[i];
            this->meu_time_vel[i] = _ryellow_vel[i];
            this->adversario_pos[i] = _rblue_pos[i];
            this->adversario_ori[i] = _rblue_ori[i];
            this->adversario_vel[i] = _rblue_vel[i];
        }
    }
    this->ball_pos = _ball_pos;
    this->ball_vel = _ball_vel;
}


