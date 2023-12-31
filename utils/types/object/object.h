#ifndef OBJECT_H
#define OBJECT_H

#include <utils/types/angle/angle.h>
#include <filters/loss/lossfilter.h>
#include <filters/noise/noisefilter.h>
#include <filters/kalman/kalmanfilter.h>

class Object
{
public:
    Object(bool useKalman);
    ~Object();

    // Getters
    Position getPosition();
    Velocity getVelocity();
    Angle getOrientation();

    // Filtering
    bool isObjectSafe();
    bool isObjectLoss();

    // Update
    void updateObject(float confidence, Position pos, Angle orientation = Angle(false, 0.0));
    void setInvalid();

private:
    // Object params
    Position _position;
    Velocity _velocity;
    Angle _orientation;
    float _confidence;

    // Object filters
    LossFilter _lossFilter;
    NoiseFilter _noiseFilter;
    KalmanFilter _kalmanFilter;

    // Use kalman control
    bool _useKalman;
};

#endif // OBJECT_H
