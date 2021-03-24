#ifndef MAZDA_H
#define MAZDA_H

#include "Car.h"

class Mazda : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    Mazda();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif