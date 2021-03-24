#ifndef MERCEDES_H
#define MERCEDES_H

#include "Car.h"

class Mercedes : public Car
{
    int fuelCapacity, fuelConsumption, avgSpeed;
    int id;

public:
    Mercedes();
    void SetFuelCapacity(int);
    void SetFuelConsumption(int);
    void SetAvgSpeed(int);
    int CalculateScore(int, Weather);
};
#endif