#include "estrategia.h"

estrategia::estrategia(int time)
{

    this->nossaCor = time;


    qtdRobos = 3;
    // Constantes de Modelo
    L = 3.75e-2; //Distância entre roda e centro
    R = 3.035e-2; /*3.035e-2 m*/
    vrMax = 40.0;  // rad/s
    Vmax = ((40.0*R)/1.5); // 1.31 m/s
    Wmax = (40.0*(R/L))/6.5; // 35.0 rad/s

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
        std::cout<<"STOP"<<'\n';
        estrategias(PARADOS);
        break;
    case VSSRef::Foul::FREE_KICK:
        std::cout<<"FREE_KICK"<<'\n';
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

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(-0.45);
                repo_x[id_atacante] = AZUL*(-0.45);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
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
            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(-0.45);
                repo_x[id_atacante] = AMARELO*(-0.45);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::PENALTY_KICK:
        std::cout<<"PENALTY_KICK"<<'\n';
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

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(0.1);
                repo_x[id_atacante] = AZUL*(0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
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
            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(0.1);
                repo_x[id_atacante] = AMARELO*(0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::GOAL_KICK:
        std::cout<<"GOAL_KICK"<<'\n';
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

            } else
            {
                repo_x[id_goleiro] = AZUL*(-0.7);
                repo_x[id_zagueiro] = AZUL*(0.1);
                repo_x[id_atacante] = AZUL*(-0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
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

            } else
            {
                repo_x[id_goleiro] = AMARELO*(-0.7);
                repo_x[id_zagueiro] = AMARELO*(0.1);
                repo_x[id_atacante] = AMARELO*(-0.1);
                repo_y[id_goleiro] = 0.0;
                repo_y[id_zagueiro] = 0.25;
                repo_y[id_atacante] = -0.25;
            }
        }
        estrategias(REPOSICIONAR);
        break;
    case VSSRef::Foul::FREE_BALL:
        std::cout<<"FREE_BALL"<<'\n';
        if(nossaCor==VSSRef::Color::BLUE)
        {
            if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_1)
            {
                repo_x[id_atacante] = AZUL*(0.18);
                repo_y[id_atacante] = 0.4;
                id_robo_freeball = id_atacante;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_4)
            {
                repo_x[id_atacante] = AZUL*(0.18);
                repo_y[id_atacante] = -0.4;
                id_robo_freeball = id_atacante;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_2)
            {
                repo_x[id_zagueiro] = AZUL*(-0.59);
                repo_y[id_zagueiro] = 0.45;
                id_robo_freeball = id_zagueiro;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_3)
            {
                repo_x[id_zagueiro] = AZUL*(-0.59);
                repo_y[id_zagueiro] = -0.45;
                id_robo_freeball = id_zagueiro;
            }
        }else
        {
            if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_1)
            {
                repo_x[id_zagueiro] = AMARELO*(-0.59);
                repo_y[id_zagueiro] = 0.4;
                id_robo_freeball = id_zagueiro;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_4)
            {
                repo_x[id_zagueiro] = AMARELO*(-0.59);
                repo_y[id_zagueiro] = -0.4;
                id_robo_freeball = id_zagueiro;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_2)
            {

                repo_x[id_atacante] = AMARELO*(0.18);
                repo_y[id_atacante] = 0.45;
                id_robo_freeball = id_atacante;
            }
            else if(arbitro_comandos_freeball==VSSRef::Quadrant::QUADRANT_3)
            {
                repo_x[id_atacante] = AMARELO*(0.18);
                repo_y[id_atacante] = -0.45;
                id_robo_freeball = id_atacante;
            }
        }
        estrategias(REPOSICIONAR2);
        break;
    case VSSRef::Foul::GAME_ON:
        std::cout<<"GAME_ON"<<"\n";
        //estrategias(sel_estrategia);
        goleiro_01(id_goleiro,AZUL);
        atacante_01(id_atacante,AZUL);
        vai_para(id_zagueiro,ball_pos.x(),ball_pos.y());
        //atacante_01(1,AZUL);
        break;
    case VSSRef::Foul::KICKOFF:
        std::cout<<"KICKOFF"<<"\n";
        if(nossaCor==VSSRef::Color::BLUE)
        {

            repo_x[id_goleiro] = AZUL*(-0.7);
            repo_x[id_zagueiro] = AZUL*(-0.4);
            repo_x[id_atacante] = AZUL*(-0.2);
            repo_y[id_goleiro] = 0.0;
            repo_y[id_zagueiro] = 0.0;
            repo_y[id_atacante] = -0.0;

        }else
        {

            repo_x[id_goleiro] = AMARELO*(-0.7);
            repo_x[id_zagueiro] = AMARELO*(-0.4);
            repo_x[id_atacante] = AMARELO*(-0.2);
            repo_y[id_goleiro] = 0.0;
            repo_y[id_zagueiro] = 0.0;
            repo_y[id_atacante] = -0.0;

        }
        estrategias(REPOSICIONAR);
        break;
    default:
        std::cout<<"SEM ARBITRO!"<<"\n";
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
    //Calculos dos erros
    float d = sqrt(pow(x_des-meu_time_pos[id].x(),2)+pow(y_des-meu_time_pos[id].y(),2));
    std::cout << "Distância: "<< d << "\n";
        angle_err err = olhar(id,x_des,y_des);
    std::cout << "Erro angular: "<< err.fi << "\n";

    //constantes do controle
    float kv = 2.5; float kw = 0.66;
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

        if(menor_distancia(u[0],u[1])<0.1)
            return false;
        if(menor_distancia2(id,u[0],u[1])<0.1)
            return false;
    }
    return true;
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
    float passo1 = 0.15; float passo2 = 0.1; float delta = 0.07;

    float d_ball = distancia(meu_time_pos[id].x(),meu_time_pos[id].y(),ball_pos.x(),ball_pos.y());
    if( (d_ball > (passo2+delta)) || flag_atacante3 )
    {

        x_des = -vec[0]*passo2 + ball_pos.x();
        y_des = -vec[1]*passo2 + ball_pos.y();

        //---Saturação
        if(fabs(x_des)>0.72)
            x_des = 0.72*sgn(x_des);
        if(fabs(y_des)>0.62)
            y_des = 0.62*sgn(y_des);
        //---

        posicionamento2(id,x_des,y_des);

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
        vai_para(id,x_des,y_des);
        flag_atacante2 = true;
        std::cout << "Conduzindo a bola!" << "\n";
    }
    else
    {
        x_des = ball_pos.x();
        y_des = ball_pos.y();
        vai_para(id,x_des,y_des);
        if (x_des*_time < meu_time_pos[id].x()*_time)
            flag_atacante3 = true;
        std::cout << "Indo para a bola!" << "\n";
    }

    if((d_ball > (passo2+delta)) || (_time*ball_pos.x()<_time*meu_time_pos[id].x())) // Condição que indica a perda de condução
    {
        flag_atacante3 = true;
    }


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

void estrategia::estrategias(int t_estrategia)
{
    switch (t_estrategia) {
    case PARADOS:
        atacantes(PARADO);
        zagueiros(PARADO);
        goleiros(PARADO);
        break;
    case REPOSICIONAR:
        for(int i=0;i<3;i++){vai_para(i,repo_x[i],repo_y[i]);};
        break;
    case REPOSICIONAR2:
        atacantes(PARADO);
        zagueiros(PARADO);
        goleiros(PARADO);
        vai_para(id_robo_freeball,repo_x[id_robo_freeball],repo_y[id_robo_freeball]);
        /*for(int i=0;i<qtdRobos;i++)
        {
            if(i!=id_robo_freeball)
            {
                this->vL[i]=0;
                this->vR[i]=0;
            }
        }*/
        break;
    default:
        atacantes(sel_atacante);
        goleiros(sel_goleiro);
        zagueiros(sel_zagueiro);
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
    default:
        break;
    }
}

void estrategia::goleiros(int t_goleiro)
{
    switch (t_goleiro) {
    case GOLEIRO_01:
        if(nossaCor==VSSRef::YELLOW)
            goleiro_01(id_goleiro,AZUL);  //está trocado só para testes
        else
            goleiro_01(id_goleiro,AMARELO);
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
    return aux;
}

QList<QString> estrategia::obter_atacantes()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Atacante 01"));
    return aux;
}

QList<QString> estrategia::obter_zagueiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Zagueiro Beq"));
    return aux;
}

QList<QString> estrategia::obter_goleiros()
{
    QList<QString> aux;
    aux.insert(0,QString("PARADO"));
    aux.insert(1,QString("Vai Para"));
    aux.insert(2,QString("Goleiro 01"));
    return aux;
}


