#include "Mazda.h"
#include "Weather.h"
void Mazda::SetFuelCapacity(int cap)
{
    this->fuelCapacity = cap;
}
void Mazda::SetFuelConsumption(int con)
{
    this->fuelConsumption = con;
}
void Mazda::SetAvgSpeed(int spd)
{
    this->avgSpeed = spd;
}
Mazda::Mazda()
{
    this->SetFuelCapacity(250);
    this->SetFuelConsumption(2);
    this->SetAvgSpeed(4);
    this->id = 5;
}
int Mazda::CalculateScore(int length, Weather w)
{
    int modifier;
    switch (w)
    {
    case Rain:
        modifier = -1;
        break;
    case Sunny:
        modifier = 0;
        break;
    case Snow:
        modifier = -2;
        break;
    }
    int reqSteps = length / (this->avgSpeed + modifier);
    int posSteps = this->fuelCapacity / this->fuelConsumption;
    if (posSteps >= reqSteps)
        return reqSteps;
    else
        return -1;
}