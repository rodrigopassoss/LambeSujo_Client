#ifndef VISION_H
#define VISION_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QReadWriteLock>

#include <utils/types/object/object.h>
#include <proto/vssref_common.pb.h>
#include <proto/wrapper.pb.h>
#include <constants/constants.h>

class Vision : public QObject
{
    Q_OBJECT
public:

    Vision(Constants *constants);

    Vision(QString visionAddress, quint16 visionPort);

    ~Vision();

    // Getters
    QList<quint8> getAvailablePlayers(VSSRef::Color teamColor);
    Position getPlayerPosition(VSSRef::Color teamColor, quint8 playerId);
    Velocity getPlayerVelocity(VSSRef::Color teamColor, quint8 playerId);
    Angle getPlayerOrientation(VSSRef::Color teamColor, quint8 playerId);
    Position getBallPosition();
    Velocity getBallVelocity();


private slots:
    // Entity inherited methods
    void initialization();
    void loop();
    void finalization();

private:


    // Constants
    Constants *_constants;
    Constants* getConstants();

    // Socket to receive vision data
    QUdpSocket *_visionClient;
    void bindAndConnect();

    // Network
    QString _visionAddress;
    quint16 _visionPort;

    // Objects
    Object *_ballObject;
    QMap<VSSRef::Color, QHash<quint8, Object*>*> _objects;
    QMap<VSSRef::Color, QHash<quint8, bool>*> _objectsControl;
    void initObjects();
    void deleteObjects();
    void clearObjectsControl();

    // Data management
    QReadWriteLock _dataMutex;

signals:
    void visionUpdated();
};

#endif // VISION_H
