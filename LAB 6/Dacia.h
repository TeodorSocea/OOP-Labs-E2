#ifndef DACIA_H
#define DACIA_H

#include "Car.h"

class Dacia : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    char *name;

public:
    Dacia();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif