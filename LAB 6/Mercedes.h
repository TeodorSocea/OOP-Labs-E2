#ifndef MERCEDES_H
#define MERCEDES_H

#include "Car.h"

class Mercedes : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;

public:
    const char *name = "Mercedes";
    Mercedes();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif