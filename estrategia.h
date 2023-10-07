#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include "vision.h"
#include "time.h"
#include "refereeclient.h"
#include <math.h>
#include <QList>

enum comandos {PARADOS=0,DEFAULT=1,REPOSICIONAR,REPOSICIONAR2};
enum atacante {PARADO=0, VAI_PARA=1,ATACANTE_01=2};
enum zagueiro {ZAGUEIRO_01=2};
enum goleiro {GOLEIRO_01=2};
enum time {AMARELO=-1,AZUL=1};
enum ID_JOGADORES {id_atacante=0,id_goleiro=1,id_zagueiro=2};


struct _angle_
{
    int flag;
    float fi;
}typedef angle_err;

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

    //Métodos Gerais
    void controle_e_navegacao();
    void atualiza_posicoes(QVector<int> _indice, Position *_rblue_pos, double *_rblue_ori,Velocity *_rblue_vel,
                           Position *_ryellow_pos, double *_ryellow_ori,Velocity *_ryellow_vel,
                           Position _ball_pos, Velocity _ball_vel);

    //Controle de Movimento
    void vai_para(int id, float x, float y);
    void posicionamento(int id, float x, float y); // vai_para + desvio de obstáculo
    void posicionamento2(int id, float x, float y); // esse desvia da bola e do nosso time tbm
    void andarFrente(int id,int vel);
    void girar(int id,int vel);


    //Métodos Auxiliares
    angle_err olhar(int id, float x, float y);
    float distancia(float x1, float y1, float x2, float y2);
    float menor_distancia(float x,float y);
    float menor_distancia2(int id, float x,float y); // distancias para os membros do próprio time
    int sgn(float valor);
    float diff_angular(float ang1, float ang2);
    void calc_repulsao(int id, float F[]);
    void calc_repulsao2(int id, float F[],bool flag);  // calculo de repulsao para o posicionamento2
    void converte_vetor(float V[],float raio);
    void saturacao(float _pos[]);
    bool passagem_limpa(int id,float x_des, float y_des);


    //Jogadores
    void atacante_01(int id, int _time); bool flag_atacante1; bool flag_atacante2; bool flag_atacante3;
    void goleiro_01(int id, int _time, float x = -0.7, float topl = 0.17);

    //Flags de seleção dos jogadores e estratégia
    int sel_atacante,sel_zagueiro,sel_goleiro,sel_estrategia;
    // Comandos do arbitro
    int arbitro_comandos, arbitro_comandos_freeball,id_robo_freeball,arbitro_comandos_cor;
    // Variáveis para o reposicionamento
    float repo_x[3], repo_y[3];

    //Definições da estratégia
    void estrategias(int t_estrategia);
    void atacantes(int t_atacante);
    void zagueiros(int t_zagueiro);
    void goleiros(int t_goleiro);

    //Velocidades das rodas de cada robô
    QVector<int> indice;
    float vL[3];
    float vR[3];

    //Função que retorna uma Lista com os nomes das estratégias disponiveis
    QList<QString> obter_estrategias();
    //Função que retorna uma Lista com os nomes dos atacantes disponiveis
    QList<QString> obter_atacantes();
    //Função que retorna uma Lista com os nomes dos zagueiros disponiveis
    QList<QString> obter_zagueiros();
    //Função que retorna uma Lista com os nomes dos goleiros disponiveis
    QList<QString> obter_goleiros();

};

#endif // ESTRATEGIA_H

