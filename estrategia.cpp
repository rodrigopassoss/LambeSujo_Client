#include "estrategia.h"

estrategia::estrategia(int time)
{

    this->nossaCor = time;


    qtdRobos = 3;
    // Constantes de Modelo
    L = 3.75e-2; //Distância entre roda e centro
    R = 3.035e-2; /*3.035e-2 m*/
    vrMax = 40.0;  // rad/s
    Vmax = ((40.0*R)/2.0); // 1.31 m/s
    Wmax = (40.0*(R/L))/7.0; // 35.0 rad/s

    for(int i=0;i<qtdRobos;i++)
    {
        this->vL[i]=0;
        this->vR[i]=0;
    }

    flag_atacante1 = true; flag_atacante2 = false; flag_atacante3 = true;

    //Flags de seleção dos jogadores e estratégia
    sel_atacante = PARADO; sel_zagueiro = PARADO; sel_goleiro = PARADO;
    sel_estrategia  = PARADOS;

    //Abtitro
    arbitro_comandos = -1;

    //Inicialização do vetor de preditor
    int N = 5;
    ballPredPos temp;
    temp.x = 0;
    temp.y = 0;

    for(int i = 0; i < N; i++)
    {
        ballPredMemory.push_back(temp);
    }

    predictedBall = temp;


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


//    / vai_para(0, this->ball_pos.x(), this->ball_pos.y());
    //goleiro_01(1,AMARELO);
    //atacante_01(0,AZUL);
    //atacante_01(1,AZUL);
    //vai_para(0, this->ball_pos.x(), this->ball_pos.y());
    //vai_para(1, this->ball_pos.x(), this->ball_pos.y());

    //Goleiro - 0
    //Zagueiro - 1
    //Atacante - 2
 // Posisionamento automáticco
    switch (arbitro_comandos) {
    case VSSRef::Foul::STOP:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - STOP!") + '\n';
        estrategias(PARADOS);
        break;
    case VSSRef::Foul::FREE_KICK:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - FREE_KICK!") + '\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {
            if(arbitro_comandos_cor==VSSRef::Color::BLUE)
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(-0.1);
                repo_x[id_atacante] = AZUL*(0.425);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = 0.0;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(-0.45);
                repo_x[id_atacante] = AZUL*(-0.45);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }else
        {
            if(arbitro_comandos_cor==VSSRef::Color::YELLOW)
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(-0.1);
                repo_x[id_atacante] = AMARELO*(0.425);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = 0.0;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(-0.45);
                repo_x[id_atacante] = AMARELO*(-0.45);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::PENALTY_KICK:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - PENALTY_KICK!") + '\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {
            if(arbitro_comandos_cor==VSSRef::Color::BLUE)
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(-0.1);
                repo_x[id_atacante] = AZUL*(0.20);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = 0.0;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(0.1);
                repo_x[id_atacante] = AZUL*(0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }else
        {
            if(arbitro_comandos_cor==VSSRef::Color::YELLOW)
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(-0.1);
                repo_x[id_atacante] = AMARELO*(0.20);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = 0.0;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(0.1);
                repo_x[id_atacante] = AMARELO*(0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::GOAL_KICK:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - GOAL_KICK!") + '\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {
            if(arbitro_comandos_cor==VSSRef::Color::BLUE)
            {
                repo_x[id_goleiro] = AZUL*(-0.65);
                repo_x[id_zagueiro] = AZUL*(-0.35);
                repo_x[id_atacante] = AZUL*(-0.3);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = -0.2;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(0.1);
                repo_x[id_atacante] = AZUL*(-0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }else
        {
            if(arbitro_comandos_cor==VSSRef::Color::BLUE)
            {
                repo_x[id_goleiro] = AMARELO*(-0.65);
                repo_x[id_zagueiro] = AMARELO*(-0.35);
                repo_x[id_atacante] = AMARELO*(-0.3);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.2;
                repo_y[id_atacante] = -0.2;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;

            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(0.1);
                repo_x[id_atacante] = AMARELO*(-0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
                repo_theta[id_goleiro] = M_PI/2;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::FREE_BALL:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - FREE_BALL!") + '\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {
            if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_1)
            {
                repo_x[id_atacante] = AZUL*(0.18);
                repo_y[id_atacante] = 0.4;
                repo_x[id_zagueiro] = AZUL*(0.18);
                repo_y[id_zagueiro] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_4)
            {
                repo_x[id_atacante] = AZUL*(0.18);
                repo_y[id_atacante] = -0.4;
                repo_x[id_zagueiro] = AZUL*(0.18);
                repo_y[id_zagueiro] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_2)
            {
                repo_x[id_zagueiro] = AZUL*(-0.59);
                repo_y[id_zagueiro] = 0.45;
                repo_x[id_atacante] = AZUL*(-0.59);
                repo_y[id_atacante] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_3)
            {
                repo_x[id_zagueiro] = AZUL*(-0.59);
                repo_y[id_zagueiro] = -0.45;
                repo_x[id_atacante] = AZUL*(-0.59);
                repo_y[id_atacante] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;            }
        }else
        {
            if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_1)
            {
                repo_x[id_zagueiro] = AMARELO*(-0.59);
                repo_y[id_zagueiro] = 0.4;
                repo_x[id_atacante] = AMARELO*(-0.59);
                repo_y[id_atacante] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_4)
            {
                repo_x[id_zagueiro] = AMARELO*(-0.59);
                repo_y[id_zagueiro] = -0.4;
                repo_x[id_atacante] = AMARELO*(-0.59);
                repo_y[id_atacante] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_2)
            {

                repo_x[id_atacante] = AMARELO*(0.18);
                repo_y[id_atacante] = 0.45;
                repo_x[id_zagueiro] = AMARELO*(0.18);
                repo_y[id_zagueiro] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_3)
            {
                repo_x[id_atacante] = AMARELO*(0.18);
                repo_y[id_atacante] = -0.45;
                repo_x[id_zagueiro] = AMARELO*(0.18);
                repo_y[id_zagueiro] = 0.0;
                repo_theta[id_zagueiro] = 0.0;
                repo_theta[id_atacante] = 0.0;
            }
        }
        estrategias(REPOSICIONAR2);
        break;
    case VSSRef::Foul::GAME_ON:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - GAME_ON!") + '\n';
        estrategias(sel_estrategia);

        //atacante_01(1,AZUL);
        break;
    case VSSRef::Foul::KICKOFF:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - KICKOFF!") + '\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {

            //std::cout << "----- BLUE -----" <<"\n";
            repo_x[id_goleiro] = AZUL*(-0.7);
            repo_x[id_zagueiro] = AZUL*(-0.4);
            repo_x[id_atacante] = AZUL*(-0.2);
            repo_y[id_goleiro] = 0.0;
            repo_y[id_zagueiro] = 0.0;
            repo_y[id_atacante] = -0.0;

        }else
        {
            //std::cout << "----- YELLOW -----" <<"\n";


            repo_x[id_goleiro] = AMARELO*(-0.7);
            repo_x[id_zagueiro] = AMARELO*(-0.4);
            repo_x[id_atacante] = AMARELO*(-0.2);
            repo_y[id_goleiro] = 0.0;
            repo_y[id_zagueiro] = 0.0;
            repo_y[id_atacante] = -0.0;

        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::HALT:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Referee - HALT!") + '\n';
        estrategias(PARADOS);
        break;
    default:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Sem Arbitro!") + '\n';
        estrategias(sel_estrategia);

        break;
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
    //Saturação da posição, vulgo sair parede!
    float _pos[] = {x_des, y_des};
    saturacao(_pos);
    x_des=_pos[0];
    y_des=_pos[1];
    //Calculos dos erros
    float d = sqrt(pow(x_des-meu_time_pos[id].x(),2)+pow(y_des-meu_time_pos[id].y(),2));
    std::cout << "Distância: "<< d << "\n";
        angle_err err = olhar(id,x_des,y_des);
    std::cout << "Erro angular: "<< err.fi << "\n";

    //constantes do controle
    float kv = 4.5; float kw = 0.66;
    //Controle linear
    float V = Vmax*tanh(kv*d*err.flag);
    //Controle angular
    //float W = Wmax*tanh(kw*(cos(theta_e)>=0?theta_e:(theta_e<0?(-M_PI)-theta_e:M_PI-theta_e)));
    float W = Wmax*tanh(kw*err.fi);

    //Calculo das Velocidas das Rodas
    std::cout << "V: "<< V << "\n";
    std::cout << "W: "<< W << "\n";

    float v_R = ((V+W*L)/R)/vrMax;
    float v_L = ((V-W*L)/R)/vrMax;
 //   float v_R = 0.05;
 //   float v_L = 0.05;

    vR[id] = fabs(v_R) > 1 ? sgn(v_R) : v_R;
    vL[id] = fabs(v_L) > 1 ? sgn(v_L) : v_L;
}

void estrategia::olhar_para(int id, float theta)
{
    float x_des = meu_time_pos[id].x() + cos(theta);
    float y_des = meu_time_pos[id].y() + sin(theta);
    angle_err err = olhar(id,x_des,y_des);
    std::cout << "Erro angular: "<< err.fi << "\n";

    //Controle linear
    float V = 0;
    //Controle angular
    float kw = 0.66;
    float W = Wmax*tanh(kw*err.fi);

    //Calculo das Velocidas das Rodas
    std::cout << "V: "<< V << "\n";
    std::cout << "W: "<< W << "\n";

    float v_R = ((V+W*L)/R)/vrMax;
    float v_L = ((V-W*L)/R)/vrMax;
    //   float v_R = 0.05;
    //   float v_L = 0.05;

    vR[id] = fabs(v_R) > 1 ? sgn(v_R) : v_R;
    vL[id] = fabs(v_L) > 1 ? sgn(v_L) : v_L;
}

angle_err estrategia::olhar(int id, float x_des, float y_des)
{
    float theta_e = atan2(meu_time_pos[id].y()-y_des,
                          meu_time_pos[id].x()-x_des)-meu_time_ori[id];
    // Coloca o erro de -Pi a Pi para "tirar" a discontinuidade
    if(theta_e>M_PI)
    {
        theta_e = theta_e - 2*M_PI;
    }
    else if(theta_e<-M_PI)
    {
        theta_e = theta_e + 2*M_PI;
    };

    int sentido = -1;
    if(theta_e>(M_PI/2.0))
    {
        theta_e = theta_e-M_PI;
        sentido = 1;
    }else if(theta_e<-(M_PI/2.0))
    {
        theta_e = theta_e+M_PI;
        sentido = 1;
    }

    angle_err err;
    err.fi = theta_e;
    err.flag = sentido;
    return err;
}

float estrategia::distancia(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

float estrategia::menor_distancia(float x, float y)
{
    float d = 1e10;
    for(int i=0;i<qtdRobos;i++)
    {
        auto aux = distancia(adversario_pos[i].x(),adversario_pos[i].y(),x,y);
        if(d > aux)
            d = aux;
    }
    return d;
}

float estrategia::menor_distancia2(int id, float x, float y)
{
    float d = 1e10;
    for(int i=0;i<qtdRobos;i++)
    {
        if(i!=id)
        {
            auto aux = distancia(meu_time_pos[i].x(),meu_time_pos[i].y(),x,y);
            if(d > aux)
                d = aux;
        }
    }
    return d;
}

int estrategia::sgn(float valor)
{
    return valor!=0 ? valor/fabs(valor) : 0;
}

float estrategia::diff_angular(float ang1, float ang2)
{
    auto aux = ang2-ang1;
    if(aux>M_PI)
    {
        aux = aux - 2*M_PI;
    }
    else if(aux<-M_PI)
    {
        aux = aux + 2*M_PI;
    };
    return aux;
}

void estrategia::posicionamento(int id, float x_des, float y_des)
{

    float V[2] = {x_des - meu_time_pos[id].x(),y_des - meu_time_pos[id].y()};

    float F[2] = {0,0};

    calc_repulsao(id,F);

    float ka = 1;
    float kr = 1;

    converte_vetor(V,0.1);
    converte_vetor(F,0.2);

    float new_des[] = {(meu_time_pos[id].x() + ka*V[0] + kr*F[0]), (meu_time_pos[id].y() + ka*V[1] + kr*F[1])};

    saturacao(new_des);

    vai_para(id,new_des[0],new_des[1]);
}

void estrategia::posicionamento2(int id, float x_des, float y_des)
{
    float V[2] = {x_des - meu_time_pos[id].x(),y_des - meu_time_pos[id].y()};

    float F[2] = {0,0};

    calc_repulsao2(id,F,!passagem_limpa(id,x_des,y_des));

    float ka = 1;
    float kr = 1;

    converte_vetor(V,0.5);
    converte_vetor(F,0.2);

    float new_des[] = {(meu_time_pos[id].x() + ka*V[0] + kr*F[0]), (meu_time_pos[id].y() + ka*V[1] + kr*F[1])};

    saturacao(new_des);

    vai_para(id,new_des[0],new_des[1]);
}

void estrategia::andarFrente(int id, int V)
{
    vR[id] = (fabs(V/R) > vrMax ? vrMax*sgn(V/R) : (V/R))/vrMax;
    vL[id] = (fabs(V/R) > vrMax ? vrMax*sgn(V/R) : (V/R))/vrMax;
}

void estrategia::girar(int id, int W)
{
    vR[id] = (fabs(-W*L/R) > vrMax ? vrMax*sgn(-W*L/R) : (-W*L/R))/vrMax;
    vL[id] = (fabs(W*L/R) > vrMax ? vrMax*sgn(W*L/R) : (W*L/R))/vrMax;
}

void estrategia::calc_repulsao(int id, float F[]){

    float raio_adversario = 0.2;  //raio de detecção do adversario

    float dist_adversario;

    for(int i = 0 ; i < qtdRobos ; i++){

        dist_adversario = sqrt(pow((meu_time_pos[id].x() - adversario_pos[i].x()),2)
                               + pow((meu_time_pos[id].y() - adversario_pos[i].y()),2));

        if (dist_adversario <= raio_adversario && dist_adversario > 0.01){
            float dist_x = meu_time_pos[id].x() - adversario_pos[i].x();
            float dist_y = meu_time_pos[id].y() - adversario_pos[i].y();

            F[0] += raio_adversario*dist_x/dist_adversario - dist_x;
            F[1] += raio_adversario*dist_y/dist_adversario - dist_y;
        }

    }
}

void estrategia::calc_repulsao2(int id, float F[], bool flag){

    float raio_adversario = 0.2;  //raio de detecção do adversario
    float raio_parceiros = 0.2;  //raio de detecção dos parceiros
    float raio_bola = 0.2;

    float dist_adversario,dist_parceiro,dist_bola;
    if(flag)
    {
        for(int i = 0 ; i < qtdRobos ; i++){

            dist_adversario = sqrt(pow((meu_time_pos[id].x() - adversario_pos[i].x()),2)
                                   + pow((meu_time_pos[id].y() - adversario_pos[i].y()),2));

            if (dist_adversario <= raio_adversario && dist_adversario > 0.01){
                float dist_x = meu_time_pos[id].x() - adversario_pos[i].x();
                float dist_y = meu_time_pos[id].y() - adversario_pos[i].y();

                F[0] += raio_adversario*dist_x/dist_adversario - dist_x;
                F[1] += raio_adversario*dist_y/dist_adversario - dist_y;
            }

        }
        for(int i = 0 ; i < qtdRobos ; i++){ // robos amigos

            if(id!=i)
            {
                dist_parceiro = sqrt(pow((meu_time_pos[id].x() - meu_time_pos[i].x()),2)
                                     + pow((meu_time_pos[id].y() - meu_time_pos[i].y()),2));

                if (dist_parceiro <= raio_parceiros && dist_parceiro > 0.01){
                    float dist_x = meu_time_pos[id].x() - meu_time_pos[i].x();
                    float dist_y = meu_time_pos[id].y() - meu_time_pos[i].y();

                    F[0] += raio_parceiros*dist_x/dist_parceiro - dist_x;
                    F[1] += raio_parceiros*dist_y/dist_parceiro - dist_y;
                }
            }

        }
    }
    //calculo de repusão da bola
    dist_bola = sqrt(pow((ball_pos.x() - meu_time_pos[id].x()),2)
                     + pow((ball_pos.y() - meu_time_pos[id].y()),2));
    if (dist_bola <= raio_bola && dist_bola > 0.01){
        float dist_x = meu_time_pos[id].x()-ball_pos.x();
        float dist_y = meu_time_pos[id].y()-ball_pos.y();

        F[0] += raio_bola*dist_x/dist_bola - dist_x;
        F[1] += raio_bola*dist_y/dist_bola - dist_y;
    }
}

void estrategia::saturacao(vector <double> *V){
    //limites de x e y
    double lim_x = 0.68;
    double lim_y = 0.58;

    //Satura as posições enviadas
    if (V->at(0) > lim_x)
        V->at(0) = lim_x;

    if (V->at(0) < -lim_x)
        V->at(0) = -lim_x;

    if (V->at(1) > lim_y)
        V->at(1) = lim_y;

    if (V->at(1) < -lim_y)
        V->at(1) = -lim_y;
}


void estrategia::saturacao(float _pos[]){
    //limites de x e y
    float lim_x = 0.68;
    float lim_y = 0.58;

    //Satura as posições enviadas
    if (_pos[0] > lim_x)
        _pos[0] = lim_x;

    if (_pos[0] < -lim_x)
        _pos[0] = -lim_x;

    if (_pos[1] > lim_y)
        _pos[1] = lim_y;

    if (_pos[1] < -lim_y)
        _pos[1] = -lim_y;

}

void estrategia::converte_vetor(float V[],float raio){

    float dist = sqrt(pow(V[0],2) + pow(V[1],2));

    if (dist > raio){
        V[0] = raio*V[0]/dist;
        V[1] = raio*V[1]/dist;
    }

}

bool estrategia::passagem_limpa(int id, float x_des, float y_des)
{
    float passo = 0.01;
    float dist = distancia(x_des,y_des,meu_time_pos[id].x(),meu_time_pos[id].y());
    float v[] = {(x_des-meu_time_pos[id].x())/dist,(y_des-meu_time_pos[id].y())/dist};

    int K = int(dist/passo);
    float u[] = {meu_time_pos[id].x(),meu_time_pos[id].y()};
    for(int i=0;i<K;i++)
    {
        u[0] = u[0] + v[0]*passo;
        u[1] = u[1] + v[1]*passo;

        if(menor_distancia(u[0],u[1])<0.06)
            return false;
        if(menor_distancia2(id,u[0],u[1])<0.06)
            return false;
    }
    return true;
}

void estrategia::fire_kick(int id,int _time)
{
    double lim_x = 0.8; //Posicao x do centro do gol
    double lim_y = 0.17; //Define a localização do gol em y
    double distancia_posse = 0.1; //Distância que o robô considera que ele tem posse da bola
    double lim_ang = 0.1; //Pra quando a bola estiver longe
    double lim_ang_perto = 0.78; //Pra quando a bola estiver perto
    double dist_ball_rb[2] = {ball_pos.x() - meu_time_pos[id].x(),ball_pos.y() - meu_time_pos[id].y()}; //0 é x, 1 é y
    double dist_gol_rb[2] = {_time*lim_x - meu_time_pos[id].x(),lim_y - meu_time_pos[id].y()};
    double Y = dist_gol_rb[0]*tan(meu_time_ori[id]) + meu_time_pos[id].y();
    double alvo_projetado[2] = {lim_x,Y};
    //posicao alvo: [lim_x, Y] -> a projeção de onde o robô tá olhando

    double ang_rb_bola = atan2(dist_ball_rb[1],dist_ball_rb[0]);
    angle_err angulo = olhar(id, ball_pos.x(), ball_pos.y()); //Angulo pra bola
    angle_err angulo_alvo = olhar(id,alvo_projetado[0],alvo_projetado[1]);

    bool flag = true;
    bool flag_lateral = false;
    flag_lateral = (((_time==-1)&&(meu_time_pos[id].x()>ball_pos.x()))||(meu_time_pos[id].x()<ball_pos.x()));
    double x = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(), ball_pos.x(), ball_pos.y());

    lim_ang = cos(x)*atan2(sqrt(0.04*(1-(x*x/4))),x); //elipse era 0.06
    //lim_ang = 1.57-1.47*x;
    //cout << "ID: "<< id << "lim_ang: "<<lim_ang <<endl;

    /*if (distancia(rb,ball.x(),ball.y()) < distancia_posse) {
        //Se a bola tiver muito perto, é importante aumentar o angulo
        lim_ang = lim_ang_perto;
    }*/

    /*cout << "Orientacao: " << rb.orientation() << "Angulo pra bola: " << angulo.fi << endl;
    cout << "Y de projecao: " << Y << endl;*/

    //Se o robô estiver olhando pro gol
    if (Y >= -lim_y && Y<= lim_y){
        //cout<<"Olhando pro gol"<<endl;
        //Se o robo estiver olhando pra bola
        if( (flag_lateral) && (fabs(angulo.fi*M_PI/180) <= lim_ang)){
            //cout<<"FIRE!"<<endl;
            vR[id] = angulo.flag*150;
            vL[id]  = angulo.flag*150;
            bandeira = false;
            flag = false;
        }else{
            //cout<<"Olhando pro gol mas não pra bola"<<endl;
            bandeira = true;
        }
    }else{
        //cout<<"Não estou olhando pro gol"<<endl;
        bandeira = true;
    }
    if(flag){
        //andarFrente(0,id);
    }
}

void estrategia::predict_ball(int futureTime)
{

    // Depende de quantas foram inicializadas no construtor
    // Retornarei um vetor de 3 pontos, tais que os primeiros elementos são futuros mais próximos
    int N = 0;
    float a = 0;     // Começo da pseudoinversão (A'A)^(-1)
    float theta = 0; //Guarda o termo do preditor
    float temp = 0;

    //Representa quantas iterações no futuro o robô vai predizer a bola
    //Atenção: quanto mais no futuro, mais errado, então imagine esse valor como um ganho de preditor
    //tal que MAIOR = mais pra frente, MENOR = menos pra frente no tempo.

    N = this->ballPredMemory.size()-1; // indice do ultimo elemento

    ballPredPos result; //Resultado será guardado aqui.

    //Atualização do vetor de memória
    ballPredPos ballUpdate;
    ballUpdate.x = ball_pos.x();
    ballUpdate.y = ball_pos.y();

    std::cout << "xy: "<< ballUpdate.x << "\n";
    ballPredMemory.push_back(ballUpdate); //Adicionando novo elemento à memória
    ballPredMemory.erase(ballPredMemory.begin()+0); //Removendo último valor da memória

    //Primeiro para a posição x.
    for (int m = 0; m < (N-1);m++)
        a = a + pow(this->ballPredMemory[m].x,2);
    a = 1/(a + 0.001);

    for(int m = 0; m < (N-1);m++)
        theta = theta + a * this->ballPredMemory[m].x * this->ballPredMemory[m+1].x;
    theta = pow(theta,futureTime);
    result.x = theta * ball_pos.x();

    //Agora pra posicao y.
    a = 0;
    theta = 0;

    for (int m = 0; m < (N-1);m++)
        a = a + pow(this->ballPredMemory[m].y,2);
    a = 1/(a + 0.001);

    for(int m = 0; m < (N-1);m++)
        theta = theta + a * this->ballPredMemory[m].y * this->ballPredMemory[m+1].y;
    theta = pow(theta,futureTime);
    result.y = theta * ball_pos.y();

    //"Retorno" da função.
    this->predictedBall = result;
}



void estrategia::atacante_01(int id, int _time)
{
    float x_des,y_des;
    float x_goal = _time*0.77; float y_goal = -sgn(meu_time_pos[id].y())*0.14;
    float p = 0.5;
    if((p<rand()) && (flag_atacante1))
    {
        y_goal = 0;
        flag_atacante1 = false;
    }else
        flag_atacante1 = false;


    float d_bg = distancia(x_goal,y_goal,ball_pos.x(),ball_pos.y());
    float vec[] = {(x_goal - ball_pos.x())/d_bg,(y_goal - ball_pos.y())/d_bg};
    float passo1 = 0.3; float passo2 = 0.1; float delta = 0.07;

    float d_ball = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y());
    if( (d_ball > (passo2+delta)) || flag_atacante3 )
    {

        x_des = -vec[0]*passo2 + ball_pos.x();
        y_des = -vec[1]*passo2 + ball_pos.y();

        //---Saturação
        if((abs(ball_pos.x())>0.5)&(abs(ball_pos.y())<0.35))
        {
            x_des = abs(x_des) > 0.5? 0.5*sgn(x_des):x_des;
            y_des = abs(y_des) < 0.35? 0.35*sgn(y_des):y_des;
        }
        //---
        float dist_ = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),x_des,y_des);
        if(!passagem_limpa(id,x_des,y_des)&(dist_<2*delta)&(ball_pos.x()>meu_time_pos[id].y()))
            posicionamento(id,x_des,y_des);
        else
            vai_para(id,ball_pos.x(),ball_pos.y());


        if(flag_atacante2 == true)
        {
            flag_atacante1 = true;
            flag_atacante2 == false;
        }
        if(distancia(x_des,y_des,meu_time_pos[id].x(),meu_time_pos[id].y()) < (delta+0.01))
            flag_atacante3 = false;


        std::cout << "Posicionando!" << "\n";

    }
    else if((d_ball < delta))
    {
        x_des = vec[0]*passo1 + ball_pos.x();
        y_des = vec[1]*passo1 + ball_pos.y();
        //---Saturação
        if((abs(ball_pos.x())>0.5)&(abs(ball_pos.y())<0.35))
        {
            x_des = abs(x_des) > 0.5? 0.5*sgn(x_des):x_des;
            y_des = abs(y_des) < 0.35? 0.35*sgn(y_des):y_des;
        }
        //---
        vai_para(id,x_des,y_des);
        flag_atacante2 = true;
        std::cout << "Conduzindo a bola!" << "\n";
    }
    else
    {
        x_des = ball_pos.x();
        y_des = ball_pos.y();
        //---Saturação
        if((abs(ball_pos.x())>0.5)&(abs(ball_pos.y())<0.35))
        {
            x_des = abs(x_des) > 0.5? 0.5*sgn(x_des):x_des;
            y_des = abs(y_des) < 0.35? 0.35*sgn(y_des):y_des;
        }
        //---
        vai_para(id,x_des,y_des);
        if (x_des*_time < meu_time_pos[id].x()*_time)
            flag_atacante3 = true;
        std::cout << "Indo para a bola!" << "\n";
    }

    if((d_ball > (passo2+delta)) || (_time*ball_pos.x()<_time*meu_time_pos[id].x())) // Condição que indica a perda de condução
    {
        flag_atacante3 = true;
    }

    if(ball_pos.x()>0)
    {
        vai_para(id,0.0,ball_pos.y()-0.15*sgn(ball_pos.y()));
    }
    fire_kick(id, _time);


}

void estrategia::goleiro_01(int id, int _time, float x_, float topl)
{
    float top_limit = topl; //largura do gol/2
    float x_desejado = x_*_time;

    float dist = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y());
    float new_pos[] = {0,0};

    //se a bola estiver longe utiliza o preditor
    if ( dist > 0.3){
        new_pos[0] = ball_pos.x();
        new_pos[1] = (fabs(ball_pos.y())<fabs(topl))?ball_pos.y():-topl*sgn(ball_pos.y());
    }else{
        new_pos[0] = ball_pos.x();
        new_pos[1] = (fabs(ball_pos.y())<fabs(topl))?ball_pos.y():-topl*sgn(ball_pos.y());
    }

    if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),x_desejado,meu_time_pos[id].y()) >= 0.02){ //se o robô está dentro do retângulo

        if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),x_desejado,meu_time_pos[id].y()) >= 0.3){
            posicionamento(id,x_desejado,new_pos[1]);
        }else{
            vai_para(id,x_desejado,new_pos[1]);
        }

    }else{

        if(meu_time_pos[id].y() < top_limit && meu_time_pos[id].y() < new_pos[1]){ //robô abaixo da bola
            vai_para(id,x_desejado,new_pos[1]);
        }
        else if(meu_time_pos[id].y() > -top_limit && meu_time_pos[id].y() > new_pos[1]){ //robô acima da bola
            vai_para(id,x_desejado,new_pos[1]);
        }
        else{
            andarFrente(id,0.0);
        }
        //gira se a bola estiver muito perto
        if (distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y()) < 0.08){
            if((ball_pos.y() < 0 && _time == 1)){
                girar(id,0.5*Wmax);
            }
            if((ball_pos.y() > 0 && _time == -1)){
                girar(id,-0.5*Wmax);
            }
            if((ball_pos.y() > 0 && _time == 1)){
                girar(id,-0.5*Wmax);
            }
            if((ball_pos.y() < 0 && _time == -1)){
                girar(id,0.5*Wmax);
            }
        }
        // Se a bola tiver acima ou abaixo da trave
        if(fabs(ball_pos.y())>top_limit)
            vai_para(id,x_desejado,sgn(ball_pos.y())*(top_limit+0.03));

    }
}


void estrategia::zagueiro_01(int id, int _time)
{

    int timeScale = 35 + 20*tanh(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())-0.3);

    predict_ball(timeScale);

    double x_des;
    double y_des;
    // _time se a gente for o lado direito, vai retornar -1
    // _time se a gente for o lado esquerdo, vai retornar 1
    // FALTA ESPELHAR
    if(0 > ball_pos.x()*_time && ball_pos.x()*_time >= -0.50){  // região que o zagueiro vai atuar
        double anguloBolaRobo = atan2(ball_pos.y()-meu_time_pos[id].y(),ball_pos.x()-meu_time_pos[id].x()); // angulo da (posiçao da bola - posiçao do robo)

        double anguloBolaRobo2 = cos(anguloBolaRobo);

        double anguloBolaRobo3  = (sgn(anguloBolaRobo2))*_time; // vai pegar o sinal do valor do cosseno do anguloBolaRobo2, se for positivo quer dizer que a bola está atrás do zagueiro,
            // tem risco de gol contra, se for negativo a bola está na frente do zagueiro, o robô pode ir com tudo
        if(anguloBolaRobo3<0){ // o sgn so nao entra se for 0 entao a condicao de chutar a bola nunca chega, mas é muito difícil ficar exatamente 0
            // se for positivo significa que a bola está atrás do robô (risco de gol contra), a ideia é que o robô vá para trás da bola

            x_des = ball_pos.x()-0.2*_time; // para que consiga chegar antes da bola tem que ir pra antes

            if(x_des*_time < -0.5){ // saturar para que o robô não entre na região do goleiro na tentativa de ir para trás da bola
                x_des = -0.5*_time;
            }

            if(ball_pos.y() >= 0.3){ // se tiver maior que 0.3m, o robô precisa ir em um y < 0.3 para deixar uma margem de segurança para ir atrás da bola
                y_des = ball_pos.y()-0.1; // a ideia é fazer com que o robô fique rondando a bola até que ela fique na frente do robô
            }
            else if(0 < ball_pos.y() && ball_pos.y() < 0.3){ // aqui vai por cima
                y_des = ball_pos.y()+0.1;
            }
            else if(ball_pos.y() <= -0.3){ // aqui vai por cima quando y < 0
                y_des = ball_pos.y()+0.1;
            }
            else if(0 > ball_pos.y() && ball_pos.y() > -0.3){ // aqui vai por baixo quando y < 0
                y_des = ball_pos.y()-0.1;
            }

            vai_para(id,x_des,y_des);
        }
        else{  // se for negativo significa que a bola está na frente do robô (pode ir com tudo)
            x_des = ball_pos.x();
            y_des = ball_pos.y();


            if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.05){ // se o robo estiver perto da bola ele gira pra chutar a bola
                if(ball_pos.y() >= 0)
                    girar(id,-Wmax*_time);// a rotacao de giro muda pra jogar a bola pro meio do campo
                else{
                    girar(id,Wmax*_time);
                }

                //cout << anguloBolaRobo2 <<endl;
            }
            else{
                vai_para(id,x_des,y_des);// se a dsitancia tier longe vai pra perto da bola
                //cout << anguloBolaRobo3 <<endl;
            }
        }

    }
    /*
        else if(ball_pos.x() > 0.40 && ball_pos.x() < 0.55){ // nunca entra nessa condicao pq nao tem como ser maior que 40 e menor que
            vai_para(id,x_des,y_des);
            girar(id,0.6);
        }
        */
    else if(ball_pos.x()*_time > 0){  // a bola está na regiao do outro time
        //manter a posição x no meio que seria +- 25cm e ficar variando o y de acordo com o predict da bola essa ...

        vai_para(id,-0.25*_time,predictedBall.y);
    }
    else{   // a bola está no nosso time na regiao do goleiro
        //x_des = 0.25;

        // COMENTARIO VISTO
        // mudar a condicao ele tem que ir pros cantos
        // COMENTARIO VISTO

        if(ball_pos.y() > 0.38){ // se a bola tiver no canto superior
            if(meu_time_pos[id].y() < 0.38){ // se o robô tiver abaixo do canto superior
                if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.07){
                    girar(id,-Wmax*_time); // se a bola tiver perto do robo ele gira na direcao de tirar a bola do gol
                }else if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.3){
                    vai_para(id,-0.5*_time,ball_pos.y()); // subir primeiro o robo vai subir no y para não entrar na regiao do gol
                    // se tiver longe vai pra bola

                }else{
                    vai_para(id,-0.5*_time,ball_pos.y());
                }
            }
            else{
                if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.07){
                    girar(id,-Wmax*_time);// se a bola tiver perto do robo ele gira na direcao de tirar a bola do gol
                }else if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.3){
                    vai_para(id,ball_pos.x()-0.5*_time,ball_pos.y()-0.05); // subir primeiro o robo vai subir no y para não entrar na regiao do gol
                    // se tiver longe vai pra bola
                }
                else{
                    vai_para(id,-0.5*_time,ball_pos.y());
                }

                //girar(id,0.6);
            }
            //cout << 4 <<endl;
        }
        else if(ball_pos.y() < -0.38){ // se a bola tiver no canto inferior
            if(meu_time_pos[id].y() > -0.38){ // se o robô tiver fora da região do canto inferior
                if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.1){
                    girar(id,Wmax*_time);// se a bola tiver perto do robo ele gira na direcao de tirar a bola do gol
                }else{
                    vai_para(id,-0.5*_time,ball_pos.y()); // subir primeiro o robo vai subir no y para não entrar na regiao do gol
                    // se tiver longe vai pra bola
                }
            }
            else{
                if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())<0.1){
                    girar(id,Wmax*_time);// se a bola tiver perto do robo ele gira na direcao de tirar a bola do gol
                }else{
                    vai_para(id,ball_pos.x(),ball_pos.y()); // subir primeiro o robo vai subir no y para não entrar na regiao do gol
                    // se tiver longe vai pra bola
                }
            }
        }
    }
    fire_kick(id,_time);
}
void estrategia::goleiro_02(int id, int _time){
    // Atualização do GoleiroPetersson2 para evitar o penalty com a bola parada dentro da área
    double top_limit = 0.17; //largura do gol/2
    double x_desejado = -0.7*_time;
    double delta = 0.01; // pra impedir que ele fique sambando parado no gol
    double velocidade = 2.5;
    double dist = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y());
    std::vector <double> new_pos = {0,0};

    int timeScale = 55;

    predict_ball(timeScale);

    //se a bola estiver longe do goleiro utiliza o preditor para ajeitar sua posição
    if ( dist > 0.3){  // diatancia para bola
        new_pos = {predictedBall.x,predictedBall.y};
        //new_pos = {ball_pos.x(),ball_pos.y()};
    }else{
        new_pos = {ball_pos.x(),ball_pos.y()};
    }

    double dist_ball = distancia(x_desejado,top_limit,-0.63*_time,0.36); // distancia para quina da area

    //se a bola estiver estiver nos cantos ele avanca nela
    if(dist < dist_ball && ball_pos.x() > meu_time_pos[id].x() && meu_time_pos[id].x() < -0.63 && (ball_pos.y() > top_limit || ball_pos.y() < -top_limit) && _time == 1){
        vai_para(id,new_pos[0],new_pos[1]);
    }
    else if(dist < dist_ball && ball_pos.x() < meu_time_pos[id].x() && meu_time_pos[id].x() > 0.63 && (ball_pos.y() > top_limit || ball_pos.y() < -top_limit) && _time == -1){
        vai_para(id,new_pos[0],new_pos[1]);
    }
    else{

        //Verifica se o robô está perto do centro do gol
        /*if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),x_desejado,meu_time_pos[id].y())>= 0.02 ){
            cout << "ENTREIIIIII 3 " << endl;
            double teste = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),x_desejado,meu_time_pos[id].y());
            cout << teste <<endl;
            vai_para(id,x_desejado,((top_limit*1.5)*ball_pos.y())/abs(ball_pos.y())); // vai para o canto do gol

        }*/


        //else{ //organiza a orientacao e movimentacao do goleiro sob a linha de gol

        //condicao para corrigir orientacao
        //if(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())>= 0.2){
        //olhar(id,x_desejado,0.18*_time);
        //    cout << "OI " << endl;
        //    vai_para(id,x_desejado,ball_pos.y());
        //    olhar(id,x_desejado,(meu_time_pos[id].y()+0.1)*_time);

        //}
        /*
            angle_err angulo = olhar(id,meu_time_pos[id].x(),top_limit + 0); // calcula diferença entre angulo atual e angulo desejado
            if(angulo.fi >= 0.5 || angulo.fi<= -0.5){ //se o robô não está aproximadamente 90 graus
                //andarFrente(id,0);
                olhar_para(id,angulo.fi);
                cout << "ENTREIIIIII 4a " << endl;
            }

            else if(meu_time_pos[id].y() < top_limit && meu_time_pos[id].y() + delta < new_pos[1]){ //robô abaixo da bola
                cout << "ENTREIIIIII 4b " << endl;
                if(angulo.flag == 1){
                    andarFrente(id,Vmax);
                }
                else{
                    andarFrente(id,-Vmax);
                }
            }
            else if(meu_time_pos[id].y() > -top_limit && meu_time_pos[id].y() - delta > new_pos[1]){ //robô acima da bola
                cout << "ENTREIIIIII 4c " << endl;
                if(angulo.flag == 1){
                    andarFrente(id,-Vmax);
                }
                else{
                    andarFrente(id,Vmax);
                }
            }
            else{
                cout << "ENTREIIIIII 4d " << endl;
                andarFrente(id,0);
            }
            */
        //*
        if(meu_time_pos[id].y() < top_limit && meu_time_pos[id].y() < new_pos[1]){ //robô abaixo da bola
            vai_para(id,x_desejado,new_pos[1]);
            olhar(id,x_desejado,0.18);
        }
        else if(meu_time_pos[id].y() > -top_limit && meu_time_pos[id].y() > new_pos[1]){ //robô acima da bola
            vai_para(id,x_desejado,new_pos[1]);
            olhar(id,x_desejado,0.18);
        }
        else{
            //andarFrente(id,0.0);
            vai_para(id,x_desejado,((top_limit*1.5)*ball_pos.y())/abs(ball_pos.y())); // vai para o canto do gol
        }



        //*/
        //gira se a bola estiver muito perto do goleiro
        if (distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),new_pos[0],new_pos[1]) < 0.06){  //0.07
            //cout << "ENTREIIIIII 5 " << endl;
            if (((meu_time_pos[id].y()>0)&&(predictedBall.y>meu_time_pos[id].y()+0.01))||((meu_time_pos[id].y()<0)&&(predictedBall.y<meu_time_pos[id].y()-0.01)))
            { //Só chuta se a bola não tiver a caminho de entrar no gol (condicao nova pos unball)
                //cout << "ENTREIIIIII 5a " << endl;
                if((ball_pos.y() < meu_time_pos[id].y() && _time == 1)){ // Azul
                    girar(id,Wmax);
                }
                if((ball_pos.y() > meu_time_pos[id].y() && _time == -1)){ // Amarelo
                    girar(id,Wmax);
                }
                if((ball_pos.y() > meu_time_pos[id].y() && _time == 1)){ // Azul
                    girar(id,-Wmax);
                }
                if((ball_pos.y() < meu_time_pos[id].y() && _time == -1)){ // Amarelo
                    girar(id,-Wmax);
                }
            }
        }
        //}


    }

}

void estrategia::atacante_02(int id, int idzag, int _time)
{

    int timeScale = 35 + 20*tanh(distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y())-0.3);

    predict_ball(timeScale);

    double alpha = M_PI/8;
    double meioGolx = 0.75*_time;
    double golSup = 0.17;
    double goalInf = -0.17;
    double beta  = atan2(meu_time_pos[id].x() - meioGolx , meu_time_pos[id].y());
    double gamma = atan2(meu_time_pos[id].x() - ball_pos.x() , meu_time_pos[id].y() - ball_pos.y());
    double roh   = atan2(golSup - meu_time_pos[id].x(), golSup - meu_time_pos[id].y());
    double omega = atan2(goalInf - meu_time_pos[id].x(), goalInf - meu_time_pos[id].y());
    int K = round(beta/alpha);
    double gain;
    //double resultante_2 = {0,0};

    if(K<2)
        gain = 0.4;
    else if(K>=2 && K <= 3)
        gain = 0.35;
    else if(K>3 && K < 5)
        gain = 0.4;
    else if(K>=5 && K < 7)
        gain = 0.35;
    else
        gain = 0.4;

    delete resultante_2;
    resultante_2 = new vector<double>();

    //Determinação da origem do vetor resultante
    resultante_2->push_back(meu_time_pos[id].x());
    resultante_2->push_back(meu_time_pos[id].y());

    //distância atacante-bola
    double dist =  sqrt(pow(ball_pos.x()-meu_time_pos[id].x(),2.0)+pow( ball_pos.y()-meu_time_pos[id].y(),2.0));
    //Distancia do zagueiro até a bola
    double zag_dist = sqrt(pow(ball_pos.x()-meu_time_pos[idzag].x(),2.0)+pow( ball_pos.y()-meu_time_pos[idzag].y(),2.0));

    double componenteX;
    double componenteY;

    double k = dist;
    if(dist < 0.2)
        k  = 0.2;

    (*resultante_2)[0]+=-k*sin(gamma);
    (*resultante_2)[1]+=-k*cos(gamma);


    if(_time == 1){//azul


        if(ball_pos.x() < meu_time_pos[id].x())
        {
            int a = 0;
            //Consideração do vetor de predição
            if(abs(ball_pos.y()-meu_time_pos[id].y()) > 0.3)
                a = 1;
            else if(abs(ball_pos.y()-meu_time_pos[id].y()) < 0.06 && dist < 0.2)
            {
                (*resultante_2)[0]=meu_time_pos[id].x();
                (*resultante_2)[1]=meu_time_pos[id].y();
            }

            int c = 0;
            if((ball_pos.x()/meu_time_pos[id].x()<1 && ball_pos.x()/meu_time_pos[id].x()>0.8) && abs(ball_pos.y()-meu_time_pos[id].y()) > 0.1)
                c = 1;


            double repulsivoX;
            double repulsivoY;

            if(ball_pos.y() > meu_time_pos[id].y())
            {
                repulsivoX = (c*0.1 + 0.1)*sin(0 + (c*0.5*M_PI));
                repulsivoY = (c*0.1 + 0.1)*cos(0 + (c*0.5*M_PI));
            }else
            {
                repulsivoX = (c*0.1+0.1)*sin(M_PI-(c*0.5*M_PI));
                repulsivoY = (c*0.1+0.1)*cos(M_PI-(c*0.5*M_PI));
            }
            //Componentes do Vetor direção
            double angle = atan2(ball_pos.x()-predictedBall.x,ball_pos.y()-predictedBall.y);
            componenteX = /*-c*ball_pos.x()*/ -  a*0.1*sin(angle) - repulsivoX;
            componenteY = /*-c*ball_pos.y()*/ -  a*0.1*cos(angle) - repulsivoY;

            (*resultante_2)[0]+= componenteX;
            (*resultante_2)[1]+= componenteY;

        }else
        {

            if(dist < 0.08)
            {
                (*resultante_2)[0]+=-gain*sin(beta+M_PI);
                (*resultante_2)[1]+=-gain*cos(beta+M_PI);
            }

            else{
                if((ball_pos.x() < 0.6 && ball_pos.y() < -0.2)&& (meu_time_pos[id].y() > ball_pos.y())/*&&(abs(ball_pos.y()-blue[id].x())>0.07)*/)
                {
                    //Vetor de corrção
                    componenteX = /*ball_pos.x()*/ -  0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);
                    componenteY = /*ball_pos.y()*/ -  0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);

                    (*resultante_2)[0]+=componenteX;
                    (*resultante_2)[1]+=componenteY;

                }
                else if((ball_pos.x() < 0.6 && ball_pos.y() > 0.2)&&(meu_time_pos[id].y() < ball_pos.y())/*&&(abs(ball_pos.y()-blue[id].x())>0.07)*/)
                {
                    //Vetor de corrção
                    componenteX = /*ball_pos.x()*/ -  0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);
                    componenteY = /*ball_pos.y()*/ -  0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);

                    (*resultante_2)[0]+=componenteX;
                    (*resultante_2)[1]+=componenteY;

                }
                else if(dist > 0.2)
                {
                    (*resultante_2)[0]+= -0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0));
                    (*resultante_2)[1]+= -0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0));
                }
                //atualização
                if(((ball_pos.y()>0.25 && ball_pos.y()<0.6) && ball_pos.x() > 0.6 && meu_time_pos[id].x() >= ball_pos.x() && meu_time_pos[id].y()>0.25 && meu_time_pos[id].y()<ball_pos.y())
                    ||( (ball_pos.y()<-0.25 && ball_pos.y()>-0.6) && ball_pos.x() > 0.6 && meu_time_pos[id].x() >= ball_pos.x() && meu_time_pos[id].y()<-0.25 && meu_time_pos[id].y()>ball_pos.y()))
                {
                    (*resultante_2)[0]+= -0.1*sin(M_PI/2);
                    (*resultante_2)[1]+= -0.1*cos(M_PI/2);
                }//
            }

        }

        saturacao(resultante_2);

        if(ball_pos.x()==0)
        {
            vai_para(id,ball_pos.x(),ball_pos.y());
        }
        else
        {
            if(ball_pos.x()<=0)
            {

                if(zag_dist/dist < 0.9)
                {
                    //Comportamento sem bola : Defensivo

                    /* dist_target = distância do alvo para a bola;
                     * target = alvo da marcação;
                     * (zag_dist/dist) = razão entre as distâcias do zagueiro para
                     o atacante;
                     */

                    //Calculo do alvo de marcação
                    double dist_target = 0.0;
                    int target = 0;
                    for(int player = 0; player < 3; player++)
                    {
                        double dist_adv = sqrt(pow(ball_pos.x()-adversario_pos[player].x(),2.0)+pow( ball_pos.y()-adversario_pos[player].y(),2.0));
                        if(!(adversario_pos[player].x() > 0.65 || adversario_pos[player].x() < -0.65) && (dist_adv > dist_target))
                        {
                            dist_target = dist_adv;
                            target = player;
                        }
                    }

                    //Pos com relação ball-alvo
                    double attachX = ball_pos.x() - (0.8*dist_target)*sin(atan2(ball_pos.x() - adversario_pos[target].x(),ball_pos.y() - adversario_pos[target].y()));
                    double attachY = ball_pos.y() - (0.8*dist_target)*cos(atan2(ball_pos.x() - adversario_pos[target].x(),ball_pos.y() - adversario_pos[target].y()));

                    vai_para(id,attachX,attachY);
                }
                else
                    vai_para(id,0.10,(*resultante_2)[1]-0.1);

            }else
            {
                //Comportamento Ofensivo - Posicionamento

                //Cálculo da posição
                double attachX =  ball_pos.x() + 0.45*sin(atan2(ball_pos.x() - meu_time_pos[idzag].x(),ball_pos.y() - meu_time_pos[idzag].y()));
                //double attachY =  ball_pos.y() + 0.45*cos(atan2(ball_pos.x() - rb[1].x(),ball_pos.y() - rb[1].y()));
                int c;
                if(meu_time_pos[idzag].y()>0)
                    c = -1;
                else
                    c = 1;

                if(zag_dist/dist < 0.3)
                    vai_para(id,attachX-0.1,c*0.25);
                else
                    vai_para(id,(*resultante_2)[0],(*resultante_2)[1]);

                /*double distToGoal = sqrt(pow(meu_time_pos[id].x()-meioGolx,2.0)+pow(meu_time_pos[id].y()-0,2.0));
                if(distToGoal < 0.5 && ball_pos.x()>meu_time_pos[id].x() && (ball_pos.y() < 0.20 && ball_pos.y()>-0.20) )
                    vai_para(rb[id],ball_pos.x(),ball_pos.y(),id);*/


                /*if(abs(rb[id].orientation()-gamma)<0.4 && (omega < gamma && gamma < roh))
                {
                    FIRE_KICK(id);
                    bandeira = false;
                }else
                {
                    bandeira = true;
                }*/

                if(ball_pos.x() > 0.65 && meu_time_pos[id].x() > 0.65 && dist < 0.08 && (ball_pos.y() < 0.18 && ball_pos.y() > -0.18)&& meu_time_pos[id].y()>ball_pos.y())
                {
                    //vai_para(rb[id],(*resultante_2)[0],(*resultante_2)[1],id);
                    girar(id,0.25*Wmax);

                }else if(ball_pos.x() > 0.65 && meu_time_pos[id].x() > 0.65 && dist < 0.08 && (ball_pos.y() < 0.18 && ball_pos.y() > -0.18)&& meu_time_pos[id].y()<ball_pos.y())
                {
                    girar(id,-0.25*Wmax);
                }
                else if((ball_pos.y()>0.55 && ball_pos.x()>0.65) && (dist < 0.08))
                {
                    girar(id,-0.25*Wmax);
                }else if((ball_pos.y()<-0.55 && ball_pos.x()>0.65) && (dist < 0.08))
                {
                    girar(id,0.25*Wmax);
                }

            }
        }

    }else{ //Amarelo

        if((ball_pos.x() > meu_time_pos[id].x()))
        {
            int a = 0;
            //Consideração do vetor de predição
            if(abs(ball_pos.y()-meu_time_pos[id].y()) > 0.3)
                a = 1;
            else if(abs(ball_pos.y()-meu_time_pos[id].y()) < 0.06 && dist < 0.2)
            {
                (*resultante_2)[0]=meu_time_pos[id].x();
                (*resultante_2)[1]=meu_time_pos[id].y();
            }


            int c = 0;
            if((ball_pos.x()/meu_time_pos[id].x()<1.1 && ball_pos.x()/meu_time_pos[id].x()>1)&&abs(ball_pos.y()-meu_time_pos[id].y()) > 0.1)
                c = 1;

            double repulsivoX;
            double repulsivoY;

            if(ball_pos.y() > meu_time_pos[id].y())
            {
                repulsivoX = (c*0.1+0.1)*sin(0+(c*0.5*M_PI));
                repulsivoY = (c*0.1+0.1)*cos(0+(c*0.5*M_PI));
            }else
            {
                repulsivoX = (c*0.1+0.1)*sin(M_PI-(c*0.5*M_PI));
                repulsivoY = (c*0.1+0.1)*cos(M_PI-(c*0.5*M_PI));
            }

            //Componentes do Vetor direção
            double angle = atan2(ball_pos.x()-predictedBall.x,ball_pos.y()-predictedBall.y);
            componenteX = /*-c*ball_pos.x()*/ -  a*0.1*sin(angle) - repulsivoX;
            componenteY = /*-c*ball_pos.y()*/ -  a*0.1*cos(angle) - repulsivoY;

            (*resultante_2)[0]+= componenteX;
            (*resultante_2)[1]+= componenteY;

        }else
        {
            if(dist < 0.08)
            {
                (*resultante_2)[0]+=-gain*sin(beta+M_PI);
                (*resultante_2)[1]+=-gain*cos(beta+M_PI);
            }
            else
            {
                if((ball_pos.x() > -0.6 && ball_pos.y() < -0.2)&& (meu_time_pos[id].y() > ball_pos.y())/*&&(abs(ball_pos.y()-blue[id].x())>0.07)*/)
                {
                    //Vetor de corrção
                    componenteX = /*ball_pos.x()*/ -  0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);
                    componenteY = /*ball_pos.y()*/ -  0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);

                    (*resultante_2)[0]+=componenteX;
                    (*resultante_2)[1]+=componenteY;
                }else if((ball_pos.x() > -0.6 && ball_pos.y() > 0.2)&&(meu_time_pos[id].y() < ball_pos.y())/*&&(abs(ball_pos.y()-blue[id].x())>0.07)*/)
                {
                    //Vetor de corrção
                    componenteX = /*ball_pos.x()*/ -  0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);
                    componenteY = /*ball_pos.y()*/ -  0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0)/*+M_PI*/);

                    (*resultante_2)[0]+=componenteX;
                    (*resultante_2)[1]+=componenteY;

                }else if(dist > 0.2)
                {
                    (*resultante_2)[0]+= -0.1*sin(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0));
                    (*resultante_2)[1]+= -0.1*cos(atan2(ball_pos.x() - meioGolx,ball_pos.y() - 0.0));
                }
                //atualização
                if(((ball_pos.y()>0.25 && ball_pos.y()<0.6) && ball_pos.x() < -0.6 && meu_time_pos[id].x() <= ball_pos.x() && meu_time_pos[id].y()>0.25 && meu_time_pos[id].y()<ball_pos.y())
                    ||( (ball_pos.y()<-0.25 && ball_pos.y()>-0.6) && ball_pos.x() < -0.6 && meu_time_pos[id].x() <= ball_pos.x() && meu_time_pos[id].y()<-0.25 && meu_time_pos[id].y()>ball_pos.y()))
                {
                    (*resultante_2)[0]+= -0.1*sin(M_PI/2);
                    (*resultante_2)[1]+= -0.1*cos(M_PI/2);
                }//
            }

        }

        saturacao(resultante_2);

        if(ball_pos.x()==0)
        {
            vai_para(id,ball_pos.x(),ball_pos.y());
        }
        else
        {
            if(ball_pos.x()>=0)
            {

                if(zag_dist/dist < 0.9)
                {
                    //Comportamento sem bola : Defensivo

                    /* dist_target = distância do alvo para a bola;
                     * target = alvo da marcação;
                     * (zag_dist/dist) = razão entre as distâcias do zagueiro para
                     o atacante;
                     */

                    //Calculo do alvo de marcação
                    double dist_target = 0.0;
                    int target = 0;
                    for(int player = 0; player < 3; player++)
                    {
                        double dist_adv = sqrt(pow(ball_pos.x()-adversario_pos[player].x(),2.0)+pow( ball_pos.y()-adversario_pos[player].y(),2.0));
                        if(!(adversario_pos[player].x() > 0.65 || adversario_pos[player].x() < -0.65) && (dist_adv > dist_target))
                        {
                            dist_target = dist_adv;
                            target = player;
                        }
                    }

                    //Pos com relação ball-alvo
                    double attachX = ball_pos.x() - (0.8*dist_target)*sin(atan2(ball_pos.x() - adversario_pos[target].x(),ball_pos.y() - adversario_pos[target].y()));
                    double attachY = ball_pos.y() - (0.8*dist_target)*cos(atan2(ball_pos.x() - adversario_pos[target].x(),ball_pos.y() - adversario_pos[target].y()));

                    vai_para(id,attachX,attachY);
                }
                else
                    vai_para(id,-0.10,(*resultante_2)[1]);

            }else
            {
                //Comportamento Ofensivo - Posicionamento

                //Cálculo da posição
                double attachX =  ball_pos.x() + 0.45*sin(atan2(ball_pos.x() - meu_time_pos[idzag].x(),ball_pos.y() - meu_time_pos[idzag].y()));
                //double attachY =  ball_pos.y() + 0.45*cos(atan2(ball_pos.x() - rb[1].x(),ball_pos.y() - rb[1].y()));
                int c;
                if(meu_time_pos[idzag].y()>0)
                    c = -1;
                else
                    c = 1;

                if(zag_dist/dist < 0.3)
                    vai_para(id,attachX-0.1,c*0.25);
                else
                    vai_para(id,(*resultante_2)[0],(*resultante_2)[1]);

                if(ball_pos.x() < -0.65 && meu_time_pos[id].x() < -0.65 && dist < 0.08 && (ball_pos.y() < 0.18 && ball_pos.y() > -0.18)&& meu_time_pos[id].y()>ball_pos.y())
                {
                    //vai_para(rb[id],(*resultante_2)[0],(*resultante_2)[1],id);
                    girar(id,-0.25*Wmax);

                }else if(ball_pos.x() < -0.65 && meu_time_pos[id].x() < -0.65 && dist < 0.08 && (ball_pos.y() < 0.18 && ball_pos.y() > -0.18)&& meu_time_pos[id].y()<ball_pos.y())
                {
                    girar(id,0.25*Wmax);
                }
                else if((ball_pos.y()>0.55 && ball_pos.x()<-0.65) && (dist < 0.08))
                {
                    girar(id,0.25*Wmax);
                }else if((ball_pos.y()<-0.55 && ball_pos.x()<-0.65) && (dist < 0.08))
                {
                    girar(id,-0.25*Wmax);
                }

            }

        }
    }
    //se tiver uma reta clara pro gol, ele vai chutar
    // FIRE_KICK_old(rb[id],ball,id);
    fire_kick(id,_time);
}


void estrategia::estrategias(int t_estrategia)
{
    switch (t_estrategia) {
    case PARADOS:
        atacantes(PARADO);
        zagueiros(PARADO);
        goleiros(PARADO);
        break;
    case DIA_09:
        std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Estratŕgia de 09/10") + '\n';
        goleiros(sel_goleiro);
        atacantes(sel_atacante);
        zagueiros(sel_zagueiro);
        break;
    case REPOSICIONAR:
        for(int i=0;i<3;i++)
        {
            float d = distancia(meu_time_pos[i].x(),meu_time_pos[i].y(),
                                repo_x[i], repo_y[i]);
            if(d > 0.05)
                vai_para(i,repo_x[i],repo_y[i]);
            else
                olhar_para(i,repo_theta[i]);
        };
        break;
    case REPOSICIONAR2:
        goleiros(PARADO);
        {
            float d = distancia(meu_time_pos[id_atacante].x(),meu_time_pos[id_atacante].y(),
                                repo_x[id_atacante], repo_y[id_atacante]);
            if(d > 0.05)
                vai_para(id_atacante,repo_x[id_atacante],repo_y[id_atacante]);
            else
                olhar_para(id_atacante,repo_theta[id_atacante]);
        }
        {
            float d = distancia(meu_time_pos[id_zagueiro].x(),meu_time_pos[id_zagueiro].y(),
                                repo_x[id_zagueiro], repo_y[id_zagueiro]);
            if(d > 0.05)
                vai_para(id_zagueiro,repo_x[id_zagueiro],repo_y[id_zagueiro]);
            else
                olhar_para(id_zagueiro,repo_theta[id_zagueiro]);
        }
        break;
    default:
        atacantes(VAI_PARA);
        zagueiros(VAI_PARA);
        goleiros(GOLEIRO_01);
        break;
    }

}

void estrategia::atacantes(int t_atacante)
{
    switch (t_atacante) {
    case ATACANTE_01:
        if(nossaCor==VSSRef::YELLOW)
            atacante_01(id_atacante,AMARELO);
        else
            atacante_01(id_atacante,AZUL);
        break;
    case ATACANTE_02:
        if(nossaCor==VSSRef::YELLOW)
            atacante_02(id_atacante,id_zagueiro,AMARELO);
        else
            atacante_02(id_atacante,id_zagueiro,AZUL);
        break;
    case VAI_PARA:
        vai_para(id_atacante,this->ball_pos.x(),this->ball_pos.y());
        break;
    case PARADO:
        this->vL[id_atacante]=0;
        this->vR[id_atacante]=0;
    default:
        break;
    }

}

void estrategia::zagueiros(int t_zagueiro)
{
    switch (t_zagueiro) {
    case PARADO:
        this->vL[id_zagueiro]=0;
        this->vR[id_zagueiro]=0;
        break;
    case VAI_PARA:
        vai_para(id_zagueiro,this->ball_pos.x(),this->ball_pos.y());
        break;
    case ZAG_ATACANTE_01:
        if(nossaCor==VSSRef::Color::YELLOW)
            atacante_01(id_zagueiro,AMARELO);
        else
            atacante_01(id_zagueiro,AZUL);

        break;
    case ZAG_ATACANTE_02:
        if(nossaCor==VSSRef::Color::YELLOW)
            atacante_02(id_zagueiro,id_atacante,AMARELO);
        else
            atacante_02(id_zagueiro,id_atacante,AZUL);

        break;
    case ZAGUEIRO_01:
        std::cout << "Zagueiro 01" << "\n";
        if(nossaCor==VSSRef::Color::YELLOW)
            zagueiro_01(id_zagueiro,AMARELO);
        else
            zagueiro_01(id_zagueiro,AZUL);

        break;
    default:
        break;
    }
}

void estrategia::goleiros(int t_goleiro)
{
    switch (t_goleiro) {
    case GOLEIRO_01:
        if(nossaCor==VSSRef::YELLOW)
            goleiro_01(id_goleiro,AMARELO);
        else
            goleiro_01(id_goleiro,AZUL);
        break;
    case GOLEIRO_02:
        if(nossaCor==VSSRef::YELLOW)
            goleiro_02(id_goleiro,AMARELO);
        else
            goleiro_02(id_goleiro,AZUL);
        break;
    case VAI_PARA:
        vai_para(id_goleiro,this->ball_pos.x(),this->ball_pos.y());
        break;
    case PARADO:
        this->vL[id_goleiro]=0;
        this->vR[id_goleiro]=0;
        break;
    default:
        break;
    }
}

QList<QString> estrategia::obter_estrategias()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADOS"));
    aux.insert(1,QString("DEFAULT"));
    aux.insert(2,QString("DIA 09"));
    return aux;
}

QList<QString> estrategia::obter_atacantes()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Atacante 01"));
    aux.insert(3,QString("Atacante 02"));
    return aux;
}

QList<QString> estrategia::obter_zagueiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Atacante 01"));
    aux.insert(3,QString("Zagueiro 01"));
    aux.insert(4,QString("Atacante 02"));

    return aux;
}

QList<QString> estrategia::obter_goleiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Goleiro 01"));
    aux.insert(3,QString("Goleiro 02"));
    return aux;
}


