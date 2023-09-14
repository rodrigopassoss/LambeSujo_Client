#include "Communication.h"

communication::communication()
{
    this->serialPort = new QSerialPort; //instanciando porta serial
    QStringList portas; //Lista de Strings
    const auto serialPortInfos = QSerialPortInfo::availablePorts();//método estático
    int i =0;
    //Obtém informação das portas Seriais
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos){
        //Listando as portas disponíveis
        portas.insert(i, serialPortInfo.portName());
        i++;

    }
    std::cout << Text::yellow("[Comunicação] ", true) << Text::bold("Objeto Criado!") + '\n';
    status = "Desconectado";
    button_status = "Conectar";
    baund_rate.clear();
}

void communication::connectToSerial()
{
    // Se Tiver conectado, desconecta
    if(this->serialPort->isOpen())
    {
        this->serialPort->close();
        status = "Desconectado";  //Atualiza status para desconectado
        button_status = "Conectar";
        baund_rate.clear();       //limpando dados do Baud Rate
        flag_comunicacao = 0;
        return;
    }
    // Parâmetros de Abertura da Porta Serial
    if(!list_port.empty())
    {
        this->serialPort->setPortName(current_port);
        this->serialPort->setBaudRate(QSerialPort::Baud115200);
        this->serialPort->setDataBits(QSerialPort::Data8);
        this->serialPort->setParity(QSerialPort::NoParity);
        this->serialPort->setStopBits(QSerialPort::OneStop);
        this->serialPort->setFlowControl(QSerialPort::NoFlowControl);

    }
    flag_comunicacao = 0;
    if(this->serialPort->open(QIODevice::ReadWrite)){ // Verificação se a porta realmente abriu
        status = "Conectado";
        baund_rate = "Communication Paramaters\n"
                     "Baudrate: 115200\n"
                     "Data bits: 8\n"
                     "Parity: None\n"
                     "Stop bits: 1\n"
                     "Flow control: None";
        button_status = "Desconectar";

        flag_comunicacao = 1; // altera o flag de comunicação 0 - SemComunicação e 1 - ComComunicação

        std::cout << Text::yellow("[Comunicação] ", true) << Text::bold("Porta serial foi conectada!") + '\n';

        return;

    }

    std::cout << Text::yellow("[Comunicação] ", true) << Text::bold("Falha ao Conectar!") + '\n';
    status = "Falha ao tentar conectar";
    button_status = "Conectar";
    this->serialPort->close();


}

void communication::checkSerial()
{
    auto serialPortInfos = QSerialPortInfo::availablePorts();
    list_port.clear();
    int i =0;
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
    {
        list_port.insert(i, serialPortInfo.portName());
        i++;
    }
}

void communication::closeSerialPort()
{
    if (this->serialPort->isOpen()){
        this->serialPort->close();
        flag_comunicacao = 0;

    }
}

void communication::writeData()
{
    QByteArray write_buf2;
    write_buf2 = QByteArray::fromRawData((char*) write_buf,11);
    if (flag_comunicacao)
    {
        this->serialPort->write(write_buf2);
    }
    if(int(write_buf2.at(1) >= 0))
    {
        byte_escrito = (int)write_buf2.at(1);
    }
    else
    {
        byte_escrito =  -(128 + (int)write_buf2.at(1));
    }
}

void communication::readData()
{
    if (flag_comunicacao)
    {
        if(this->serialPort->bytesAvailable())
        {
            QByteArray read_buf = this->serialPort->read(11);
            const QString texto = read_buf;
            //receive_data = read_buf;
            if(int(read_buf.at(1) >= 0)){
                byte_lido[0] = (int)read_buf.at(1);
            }
            else{
                byte_lido[0] = -(128 + (int)read_buf.at(1));
            }
            if(int(read_buf.at(2) >= 0)){
                byte_lido[1] = (int)read_buf.at(2);
            }
            else{
                byte_lido[1] = -(128 + (int)read_buf.at(2));
            }
        }
    }
    //byte_lido = 10;

}

void communication::def_port(QString port)
{
    current_port = port;
}

/* CONVERSÃO DOS DADOS ENVIADOS OU RECEBIDOS  */
unsigned char communication::converter_write(int x)
{
    //OBSERVAÇÃO: SÓ FUNCIONA PRA VALORES MENORES QUE 127, MAS O PROTOCOLO É DE 0 A 100 COM BIT DE SINAL

    unsigned char c = C0; //Inicializando com zero
    if (x >= 0)
    {
        c = (unsigned char) x;
    }
    else
    {
        c = (unsigned char) (abs(x)+128); //Módulo + o bit de sinal
    }
    return c;
}

int communication::converter_read(unsigned char c)
{
    int x = 0; //Inicializando com zero
    if (((int)c) >= 128)
        x = -(((int)c) - 128);
    else
        x = (int)c;
    return x;
}
