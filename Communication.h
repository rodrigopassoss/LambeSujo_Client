#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QStringList>
#include <string>
//#include <QUsbDevice>
//#include <QUsbEndpoint>

#define C0 (char)0



class communication
{
public:

    QSerialPort *serialPort;
    QStringList list_port;
    QString baund_rate;
    QString status;
    QString button_status;
    QString current_port;
    QString receive_data;
    int byte_escrito;
    int byte_lido[2];


    bool flag_comunicacao = 0; // quando 1 indica comunicação ativa
    int flag_robos = 0; // 0 = nenhum, 1-5 = robô 1-5
    unsigned char write_buf[11] = {C0,C0,C0,C0,C0,C0,C0,C0,C0,C0,C0}; // buffer de escrita inicado com velocidades zero
    unsigned char read_buf[11] = {C0,C0,C0,C0,C0,C0,C0,C0,C0,C0,C0};  // buffer de leitura inicado com velocidades zero


    //Construtor
    communication();


    void connectToSerial();
    void checkSerial();
    void closeSerialPort();
    void writeData();
    void readData();
    void def_port(QString);
    unsigned char converter_write(int x);
    int converter_read(unsigned char c);

};

#endif // COMMUNICATION_H
