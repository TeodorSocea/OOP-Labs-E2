#include "Toyota.h"
#include "Weather.h"
void Toyota::SetFuelCapacity(int cap)
{
    this->fuelCapacity = cap;
}
void Toyota::SetFuelConsumption(int con)
{
    this->fuelConsumption = con;
}
void Toyota::SetAvgSpeed(int spd)
{
    this->avgSpeed = spd;
}
Toyota::Toyota()
{
    this->SetFuelCapacity(150);
    this->SetFuelConsumption(2);
    this->SetAvgSpeed(1);
    this->id = 2;
}
int Toyota::CalculateScore(int length, Weather w)
{
    int modifier;
    switch (w)
    {
    case Rain:
        modifier = 1;
        break;
    case Sunny:
        modifier = 0;
        break;
    case Snow:
        modifier = 0;
        break;
    }
    int reqSteps = length / (this->avgSpeed + modifier);
    int posSteps = this->fuelCapacity / this->fuelConsumption;
    if (posSteps >= reqSteps)
        return reqSteps;
    else
        return -1;
}