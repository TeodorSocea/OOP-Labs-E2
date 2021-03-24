#ifndef FORD_H
#define FORD_H

#include "Car.h"

class Ford : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    Ford();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif