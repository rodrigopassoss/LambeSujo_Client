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
  /*double x_des = this->ball_pos.x();
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
  */
    vai_para(0, this->ball_pos.x(), this->ball_pos.y());

    // Zera as velocidades dos outros robôs
    for(int i=1;i<qtdRobos;i++)
    {
        this->vL.insert(i,0);
        this->vR.insert(i,0);
    }
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

void estrategia::vai_para(int id, float x_des, float y_des)
{
    //Calculos dos erros
    float d = sqrt(pow(x_des-meu_time_pos[id].x(),2)+pow(y_des-meu_time_pos[id].y(),2));
    std::cout << "Distância: "<< d << "\n";
        angle_err err = olhar(id,x_des,y_des);
    std::cout << "Erro angular: "<< err.fi << "\n";

    //constantes do controle
    float kv = 2.1; float kw = 1.57;
    //Controle linear
    float V = Vmax*tanh(kv*d*err.flag);
    //Controle angular
    //float W = Wmax*tanh(kw*(cos(theta_e)>=0?theta_e:(theta_e<0?(-M_PI)-theta_e:M_PI-theta_e)));
    float W = Wmax*tanh(kw*err.fi);

    //Calculo das Velocidas das Rodas
    std::cout << "V: "<< V << "\n";
    std::cout << "W: "<< W << "\n";

    float v_R = ((V-W*L)/R)/vrMax;
    float v_L = ((V+W*L)/R)/vrMax;
    vR.insert(id,fabs(v_R) > 1 ? v_R/fabs(v_R) : v_R);
    vL.insert(id,fabs(v_L) > 1 ? v_L/fabs(v_L) : v_L);
}

angle_err estrategia::olhar(int id, float x_des, float y_des)
{
    float theta_e = atan2(meu_time_pos[id].y()-y_des,
                          meu_time_pos[id].x()-x_des)-meu_time_ori[id];
    int sentido = -1;
    if(abs(theta_e)>(M_PI/2.0))
    {
        theta_e = atan2(meu_time_pos[id].y()-y_des,
                        meu_time_pos[id].x()-x_des)-(meu_time_ori[id]+M_PI);
        sentido = 1;
    }
    // Coloca o erro de -Pi a Pi para "tirar" a discontinuidade
    if(theta_e>M_PI)
    {
        theta_e = theta_e - 2*M_PI;
    }
    else if(theta_e<-M_PI)
    {
        theta_e = theta_e + 2*M_PI;
    };
    angle_err err;
    err.fi = theta_e;
    err.flag = sentido;
    return err;
}

QList<QString> estrategia::obter_estrategias()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADOS"));
    return aux;
}

QList<QString> estrategia::obter_atacantes()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    return aux;
}

QList<QString> estrategia::obter_zagueiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    return aux;
}

QList<QString> estrategia::obter_goleiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    return aux;
}


