#ifndef TOYOTA_H
#define TOYOTA_H

#include "Car.h"

class Toyota : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    Toyota();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif