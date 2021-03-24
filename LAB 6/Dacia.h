#ifndef DACIA_H
#define DACIA_H

#include "Car.h"
#include <cstring>
class Dacia : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    Dacia();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif