#ifndef PLACEDATA_H
#define PLACEDATA_H

#include <utils/types/position/position.h>
#include <utils/types/angle/angle.h>

class PlaceData
{
public:
    PlaceData();
    PlaceData(Position position, Angle orientation);

    Position getPosition();
    Angle getOrientation();
    void reflect();

private:
    Position _position;
    Angle _orientation;
};

#endif // PLACEDATA_H
