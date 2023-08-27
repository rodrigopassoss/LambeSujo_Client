#ifndef REFEREECLIENT_H
#define REFEREECLIENT_H

#include <utils/types/object/object.h>
#include <proto/vssref_common.pb.h>
#include <proto/vssref_command.pb.h>
#include <proto/wrapper.pb.h>
#include <constants/constants.h>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QReadWriteLock>
#include "constants/constants.h"

class RefereeClient : public QObject
{
    Q_OBJECT
public:

    RefereeClient(Constants *constants);

    RefereeClient(QString _serverAddress, quint16 _serverPort);

    // Network data
    QUdpSocket *_clientSocket;
    QString _serverAddress;
    quint16 _serverPort;

    // Internal management
    bool _isConnected;

    // Internal getters
    VSSRef::Foul getLastFoul();
    VSSRef::Color getLastFoulColor();
    VSSRef::Quadrant getLastFoulQuadrant();

private:
    // Constants
    Constants *_constants;
    Constants* getConstants();
    // Environment management
    std::tuple<VSSRef::Foul, VSSRef::Color, VSSRef::Quadrant> _lastFoulData;
    QReadWriteLock _foulMutex;

private slots:

    // Network management
    void connectToNetwork();
    void disconnectFromNetwork();
    // Internal run
    void runClient();
signals:
    void new_command();
};

#endif // REFEREECLIENT_H
