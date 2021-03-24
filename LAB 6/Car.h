#ifndef CAR_H
#define CAR_H
#include "Weather.h"
class Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    virtual int CalculateScore(int, Weather) = 0;
    virtual void SetFuelCapacity(int) = 0;
    virtual void SetFuelConsumption(int) = 0;
    virtual void SetAvgSpeed(int) = 0;
    int getId()
    {
        return this->id;
    }
};

#endif