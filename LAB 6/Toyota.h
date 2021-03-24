#ifndef TOYOTA_H
#define TOYOTA_H

#include "Car.h"

class Toyota : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;

public:
    const char *name = "Toyota";
    Toyota();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif