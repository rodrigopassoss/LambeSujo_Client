#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace VSSRef;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fps = 0;

    // Initializing constants
    constants = new Constants("/home/rodrigopassos/Documentos/vsss_ws/LambeSujo_Client/constants/constants.json");

    cronometro = new QTimer(this);
    cronometro2 = new QTimer(this);
    visionClient = new Vision(constants);
    refereeClient = new RefereeClient(constants);

   //cout << constants->visionAddress().toStdString() << endl;

   // Configura botões de inicialização da comunicação com o vss-vision
   connect(ui->iniciar,SIGNAL(clicked(bool)),visionClient,SLOT(initialization()));
   connect(ui->finalizar,SIGNAL(clicked(bool)),visionClient,SLOT(finalization()));
   // Detector de recebimento de dados da visão (pode ser o mesmo frame)
   connect(visionClient,SIGNAL(visionUpdated()),this,SLOT(updateData()));
   //Atualização da informação do FPS (Opicional)
   connect(cronometro2,SIGNAL(timeout()),this,SLOT(updateFPS()));
   cronometro2->start(1e2);


   //Configura os botões da comunicação com o árbitro
   connect(ui->iniciar_2,SIGNAL(clicked(bool)),refereeClient,SLOT(connectToNetwork()));
   connect(ui->finalizar_2,SIGNAL(clicked(bool)),refereeClient,SLOT(disconnectFromNetwork()));
   //Configura conexão para recebimento de comando do árbitro
   connect(refereeClient,SIGNAL(new_command()),this,SLOT(updateReferee()));

   //Cria o objeto para comunicação
   SerialComm = new communication();
   info_ports();
   // Define as configurações de plot
   Defplot();
   tipo_plot = 0;objeto_plot = 0;cor_plot = 0;

   //Cria os objetos para estratégia
   azul = new estrategia(VSSRef::BLUE);
   amarelo = new estrategia(VSSRef::YELLOW);
   time_estrategia = VSSRef::YELLOW; //Configurável via interface

   //Atuliza menu da estratégia
   for(int i=0;i<amarelo->obter_estrategias().size();i++)
   {
       ui->sel_estrategia->addItem(amarelo->obter_estrategias().at(i));
   }
   for(int i=0;i<amarelo->obter_atacantes().size();i++)
   {
       ui->sel_atacante->addItem(amarelo->obter_atacantes().at(i));
   }
   for(int i=0;i<amarelo->obter_zagueiros().size();i++)
   {
       ui->sel_zagueiro->addItem(amarelo->obter_zagueiros().at(i));
   }
   for(int i=0;i<amarelo->obter_goleiros().size();i++)
   {
       ui->sel_goleiro->addItem(amarelo->obter_goleiros().at(i));
   }


}

MainWindow::~MainWindow()
{
   delete constants;
   delete cronometro;
   delete cronometro2;
   delete visionClient;
   delete SerialComm;
   delete refereeClient;
   delete azul;
   delete amarelo;
   delete ui;
}

Constants *MainWindow::getConstants()
{
    if(constants == nullptr) {
        std::cout << Text::red("[ERROR] ", true) << Text::bold("Constants with nullptr value at MainWindow") + '\n';
    }
    else {
        std::cout << Text::green("[OK] ", true) << Text::bold("Constants loaded at MainWindow") + '\n';
        return constants;
    }

    return nullptr;
}

void MainWindow::updateData()
{
    fim = clock();
    fps = 1e3*10*(fim-start)/CLOCKS_PER_SEC; // ms
    start = clock();
    // Atualiza as variáveis
    ball_pos = visionClient->getBallPosition();
    ball_vel = visionClient->getBallVelocity();
    QList<quint8> blue_robots = visionClient->getAvailablePlayers(VSSRef::BLUE);
    QList<quint8> yellow_robots = visionClient->getAvailablePlayers(VSSRef::YELLOW);

    QVector<int> azul_robots;
    for(int i = 0; i < blue_robots.size();i++)
    {
        rblue_pos[i] = visionClient->getPlayerPosition(VSSRef::BLUE,blue_robots.at(i));
        auto angle = visionClient->getPlayerOrientation(VSSRef::BLUE,blue_robots.at(i));
        rblue_ori[i] = (double)angle.value();
        rblue_vel[i] = visionClient->getPlayerVelocity(VSSRef::BLUE,blue_robots.at(i));
        azul_robots.append(i);
    }
    QVector<int> amarelo_robots;
    for(int i = 0; i < yellow_robots.size();i++)
    {
        ryellow_pos[i] = visionClient->getPlayerPosition(VSSRef::YELLOW,yellow_robots.at(i));
        auto angle = visionClient->getPlayerOrientation(VSSRef::YELLOW,yellow_robots.at(i));
        ryellow_ori[i] = (double)angle.value();
        ryellow_vel[i] = visionClient->getPlayerVelocity(VSSRef::YELLOW,yellow_robots.at(i));
        amarelo_robots.append(1);
    }

    if(time_estrategia==VSSRef::YELLOW)
    {
        amarelo->atualiza_posicoes(amarelo_robots,rblue_pos,rblue_ori,rblue_vel,
                                               ryellow_pos,ryellow_ori,ryellow_vel,
                                               ball_pos,ball_vel);
        amarelo->controle_e_navegacao();

        this->sendCommand(amarelo_robots,amarelo->vL,amarelo->vR);
    }else //Caso nosso time seja o azul
    {
        azul->atualiza_posicoes(azul_robots,rblue_pos,rblue_ori,rblue_vel,
                                   ryellow_pos,ryellow_ori,ryellow_vel,
                                   ball_pos,ball_vel);
        azul->controle_e_navegacao();

        this->sendCommand(azul_robots,azul->vL,azul->vR);
    }



    if(ui->habilita_plot->isChecked())
    {
        plot();
    }

}

void MainWindow::updateFPS()
{
    ui->fps_medidor->setText(QString::number(fps));
}

void MainWindow::updateReferee()
{
    QString comando;
    switch(refereeClient->getLastFoul()) {
    case FREE_KICK:
        comando = QString("FREE_KICK");
        break;
    case PENALTY_KICK:
        comando = QString("PENALTY_KICK");
        break;
    case GOAL_KICK:
        comando = QString("GOAL_KICK");
        break;
    case FREE_BALL:
        comando = QString("FREE_BALL");
        break;
    case KICKOFF:
        comando = QString("KICKOFF");
        break;
    case STOP:
        comando = QString("STOP");
        break;
    case GAME_ON:
        comando = QString("GAME_ON");
        break;
    case HALT:
        comando = QString("HALT");
        break;
    default:
        break;
    }

    ui->referee_comando->setText(comando);
}

void MainWindow::Defplot()
{
    // generate some data:
    t_data = new QVector<double>(501);
    x1_data = new QVector<double>(501);
    y1_data = new QVector<double>(501);
    x2_data = new QVector<double>(501);
    y2_data = new QVector<double>(501);
    x3_data = new QVector<double>(501);
    y3_data = new QVector<double>(501);

    for (int i=0; i<500; ++i)
    {
        (*t_data)[i] = i;
        (*x1_data)[i] = NAN;
        (*y1_data)[i] = NAN;
        (*x2_data)[i] = NAN;
        (*y2_data)[i] = NAN;
        (*x3_data)[i] = NAN;
        (*y3_data)[i] = NAN;
    }
    // create graph and assign data to it:
    ui->plot1->addGraph();ui->plot1->addGraph();ui->plot1->addGraph();
    ui->plot2->addGraph();ui->plot2->addGraph();ui->plot2->addGraph();
    //ui->widget->graph(1)->setData(x, x);
    ui->plot1->graph(0)->setPen(QPen(Qt::red));
    ui->plot1->graph(1)->setPen(QPen(Qt::green));
    ui->plot1->graph(2)->setPen(QPen(Qt::blue));
    //ui->widget->graph(1)->setData(x, x);
    ui->plot2->graph(0)->setPen(QPen(Qt::red));
    ui->plot2->graph(1)->setPen(QPen(Qt::green));
    ui->plot2->graph(2)->setPen(QPen(Qt::blue));
    // give the axes some labels:
    label_x = QString("x");label_y = QString("y");
    ui->plot1->yAxis->setLabel(label_x);
    ui->plot2->yAxis->setLabel(label_y);
    // set axes ranges, so we see all data:
    ui->plot1->xAxis->setRange(0, 500);
    ui->plot1->yAxis->setRange(-1, 1);
    ui->plot2->xAxis->setRange(0, 500);
    ui->plot2->yAxis->setRange(-1, 1);
    //tirando o label inferior
    ui->plot1->xAxis->setVisible(false);
    ui->plot2->xAxis->setVisible(false);

    ui->plot1->replot(); ui->plot2->replot();
}

void MainWindow::limpar_plots()
{
    for (int i=0; i<500; ++i)
    {
        (*t_data)[i] = i;
        (*x1_data)[i] = NAN;
        (*y1_data)[i] = NAN;
        (*x2_data)[i] = NAN;
        (*y2_data)[i] = NAN;
        (*x3_data)[i] = NAN;
        (*y3_data)[i] = NAN;
    }
    ui->plot1->yAxis->setLabel(label_x);
    ui->plot2->yAxis->setLabel(label_y);
    ui->plot1->graph(0)->setData((*t_data), (*x1_data));
    ui->plot1->graph(1)->setData((*t_data), (*x1_data));
    ui->plot1->graph(2)->setData((*t_data), (*x1_data));
    ui->plot2->graph(0)->setData((*t_data), (*x1_data));
    ui->plot2->graph(1)->setData((*t_data), (*x1_data));
    ui->plot2->graph(2)->setData((*t_data), (*x1_data));
    ui->plot1->replot();
    ui->plot2->replot();
}

void MainWindow::sendCommand(QVector<int> index, float vL[], float vR[])
{
    // A ideia é que vL e vR sejam comandos de -1 a 1
    SerialComm->write_buf[0]=255;
    std::cout << "\n===== VELOCITIES =====\n";
    for(int i=0; i < index.size(); i++)
    {
        SerialComm->write_buf[2*index.at(i)-1]=SerialComm->converter_write(int(vL[i]*1e2));
        SerialComm->write_buf[2*index.at(i)]=SerialComm->converter_write(int(vR[i]*1e2));
        QString robotDebugStr = QString("Robo %1  -> vR: %2 vL: %3 ")
                                                .arg(i)
                                                .arg(int(vR[i]*1e2))
                                                .arg(int(vL[i]*1e2));
        std::cout << robotDebugStr.toStdString() + '\n';
    }
    SerialComm->writeData();
    //std::cout << Text::cyan("[Estratégia] ", true) << Text::bold("Comando foi enviado!") + '\n';




}

void MainWindow::plot()
{
    get_data_plot();
    if (objeto_plot==4)
    {
        ui->plot1->graph(0)->setData((*t_data), (*x1_data));
        ui->plot2->graph(0)->setData((*t_data), (*y1_data));
        ui->plot1->replot();
        ui->plot2->replot();
        ui->plot1->graph(1)->setData((*t_data), (*x2_data));
        ui->plot2->graph(1)->setData((*t_data), (*y2_data));
        ui->plot1->replot();
        ui->plot2->replot();
        ui->plot1->graph(2)->setData((*t_data), (*x3_data));
        ui->plot2->graph(2)->setData((*t_data), (*y3_data));
        ui->plot1->replot();
        ui->plot2->replot();
    } else
    {
        ui->plot1->graph(0)->setData((*t_data), (*x1_data));
        ui->plot2->graph(0)->setData((*t_data), (*y1_data));
    }
    ui->plot1->replot();
    ui->plot2->replot();
}

void MainWindow::get_data_plot()
{
    switch (objeto_plot) {
    case 0:
        if(tipo_plot==0)
        {
            x1_data->pop_front();
            x1_data->push_back(ball_pos.x());
            y1_data->pop_front();
            y1_data->push_back(ball_pos.y());
        }else
        {
            x1_data->pop_front();
            x1_data->push_back(ball_vel.vx());
            y1_data->pop_front();
            y1_data->push_back(ball_vel.vy());
        }
        break;
    case 1:
        if(tipo_plot==0)
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_pos[0].x());
                y1_data->pop_front();
                y1_data->push_back(rblue_pos[0].y());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_pos[0].x());
                y1_data->pop_front();
                y1_data->push_back(ryellow_pos[0].y());
            }
        }else
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_vel[0].vx());
                y1_data->pop_front();
                y1_data->push_back(rblue_vel[0].vy());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_vel[0].vx());
                y1_data->pop_front();
                y1_data->push_back(ryellow_vel[0].vy());
            }
        }
        break;
    case 2:
        if(tipo_plot==0)
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_pos[1].x());
                y1_data->pop_front();
                y1_data->push_back(rblue_pos[1].y());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_pos[1].x());
                y1_data->pop_front();
                y1_data->push_back(ryellow_pos[1].y());
            }
        }else
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_vel[1].vx());
                y1_data->pop_front();
                y1_data->push_back(rblue_vel[1].vy());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_vel[1].vx());
                y1_data->pop_front();
                y1_data->push_back(ryellow_vel[1].vy());
            }
        }
        break;
    case 3:
        if(tipo_plot==0)
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_pos[2].x());
                y1_data->pop_front();
                y1_data->push_back(rblue_pos[2].y());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_pos[2].x());
                y1_data->pop_front();
                y1_data->push_back(ryellow_pos[2].y());
            }
        }else
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_vel[2].vx());
                y1_data->pop_front();
                y1_data->push_back(rblue_vel[2].vy());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_vel[2].vx());
                y1_data->pop_front();
                y1_data->push_back(ryellow_vel[2].vy());
            }
        }
        break;
    case 4:
        if(tipo_plot==0)
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_pos[0].x());
                y1_data->pop_front();
                y1_data->push_back(rblue_pos[0].y());
                x2_data->pop_front();
                x2_data->push_back(rblue_pos[1].x());
                y2_data->pop_front();
                y2_data->push_back(rblue_pos[1].y());
                x3_data->pop_front();
                x3_data->push_back(rblue_pos[2].x());
                y3_data->pop_front();
                y3_data->push_back(rblue_pos[2].y());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_pos[0].x());
                y1_data->pop_front();
                y1_data->push_back(ryellow_pos[0].y());
                x2_data->pop_front();
                x2_data->push_back(ryellow_pos[1].x());
                y2_data->pop_front();
                y2_data->push_back(ryellow_pos[1].y());
                x3_data->pop_front();
                x3_data->push_back(ryellow_pos[2].x());
                y3_data->pop_front();
                y3_data->push_back(ryellow_pos[2].y());
            }
        }else
        {
            if(cor_plot==0)
            {
                x1_data->pop_front();
                x1_data->push_back(rblue_vel[0].vx());
                y1_data->pop_front();
                y1_data->push_back(rblue_vel[0].vy());
                x2_data->pop_front();
                x2_data->push_back(rblue_vel[1].vx());
                y2_data->pop_front();
                y2_data->push_back(rblue_vel[1].vy());
                x3_data->pop_front();
                x3_data->push_back(rblue_vel[2].vx());
                y3_data->pop_front();
                y3_data->push_back(rblue_vel[2].vy());
            }else
            {
                x1_data->pop_front();
                x1_data->push_back(ryellow_vel[0].vx());
                y1_data->pop_front();
                y1_data->push_back(ryellow_vel[0].vy());
                x2_data->pop_front();
                x2_data->push_back(ryellow_vel[1].vx());
                y2_data->pop_front();
                y2_data->push_back(ryellow_vel[1].vy());
                x3_data->pop_front();
                x3_data->push_back(ryellow_vel[2].vx());
                y3_data->pop_front();
                y3_data->push_back(ryellow_vel[2].vy());
            }
        }
        break;
    }
}

void MainWindow::info_ports()
{
    ui->portas_usb->insertItems(0,SerialComm->list_port);
    ui->status->setText(SerialComm->status);
    //ui->monitor->setText(SerialComm->baund_rate);
    ui->conectar_serial->setText(SerialComm->button_status);
}

void MainWindow::on_iniciar_clicked()
{
    connect(cronometro,SIGNAL(timeout()),visionClient,SLOT(loop()));
    cronometro->start(25);
    start = clock();
}


void MainWindow::on_iniciar_2_clicked()
{
    connect(cronometro,SIGNAL(timeout()),refereeClient,SLOT(runClient()));
    cronometro->start(25);
}


void MainWindow::on_conectar_serial_clicked()
{
    std::cout << Text::yellow("[Comunicação] ", true) << Text::bold("Porta: " + ui->portas_usb->currentText().toStdString()) + '\n';
    SerialComm->def_port(ui->portas_usb->currentText());
    SerialComm->connectToSerial();
    info_ports();
}


void MainWindow::on_atualiza_serial_clicked()
{
    std::cout << Text::yellow("[Comunicação] ", true) << Text::bold("Atualiza Portas") + '\n';
    SerialComm->checkSerial();
    ui->portas_usb->clear();
    info_ports();
}


void MainWindow::on_tipos_variaveis_currentIndexChanged(int index)
{
    this->tipo_plot = index;
    if(index == 0)
    {
        label_x = QString("x");
        label_y = QString("y");
    }else
    {
        label_x = QString("vx");
        label_y = QString("vy");
    }
    limpar_plots();
}


void MainWindow::on_objetos_currentIndexChanged(int index)
{
    this->objeto_plot = index;
    limpar_plots();
}

void MainWindow::on_time_currentIndexChanged(int index)
{
    this->cor_plot = index;
    limpar_plots();
}



void MainWindow::on_slider_vl_valueChanged(int value)
{
    int index = ui->selRobo->currentIndex();
    if(index == 0)
    {
        for(int i = 1; i<10 ;i+=2)
        {
            SerialComm->write_buf[i]=SerialComm->converter_write(value);
        }
    }
    else
    {
        for(int i = 1; i<10 ;i+=2)
        {
            SerialComm->write_buf[i]=0;
        }
        SerialComm->write_buf[2*index-1]=SerialComm->converter_write(value);
    }
    SerialComm->write_buf[0]=255;

    SerialComm->writeData();

}


void MainWindow::on_slider_vr_valueChanged(int value)
{
    int index = ui->selRobo->currentIndex();
    if(index == 0)
    {
        for(int i = 2; i<=10 ;i+=2)
        {
            SerialComm->write_buf[i]=SerialComm->converter_write(value);
        }
    }
    else
    {
        for(int i = 2; i<=10 ;i+=2)
        {
            SerialComm->write_buf[i]=0;
        }
        SerialComm->write_buf[2*index]=SerialComm->converter_write(value);
    }
    SerialComm->write_buf[0]=255;

    SerialComm->writeData();
}


void MainWindow::on_finalizar_clicked()
{
    disconnect(cronometro,SIGNAL(timeout()),visionClient,SLOT(loop()));

    QVector<int> indices;
    float zeros[3];
    for(int i=0;i<3;i++)
    {
        zeros[i];
        indices.insert(i,i);
    }
    this->sendCommand(indices,zeros,zeros);
}


void MainWindow::on_finalizar_2_clicked()
{
    disconnect(cronometro,SIGNAL(timeout()),refereeClient,SLOT(runClient()));
}


void MainWindow::on_iniciar_3_clicked()
{
    azul->sel_atacante = ui->sel_atacante->currentIndex();
    azul->sel_zagueiro = ui->sel_zagueiro->currentIndex();
    azul->sel_goleiro = ui->sel_goleiro->currentIndex();
    azul->sel_estrategia = ui->sel_estrategia->currentIndex();

    amarelo->sel_atacante = ui->sel_atacante->currentIndex();
    amarelo->sel_zagueiro = ui->sel_zagueiro->currentIndex();
    amarelo->sel_goleiro = ui->sel_goleiro->currentIndex();
    amarelo->sel_estrategia = ui->sel_estrategia->currentIndex();
}


void MainWindow::on_finalizar_3_clicked()
{
    disconnect(cronometro,SIGNAL(timeout()),visionClient,SLOT(loop()));

    QVector<int> indices;
    float zeros[3];
    for(int i=0;i<3;i++)
    {
        zeros[i];
        indices.insert(i,i);
    }
    this->sendCommand(indices,zeros,zeros);
}

