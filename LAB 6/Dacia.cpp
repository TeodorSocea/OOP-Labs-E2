#include "Dacia.h"
#include "Weather.h"
void Dacia::SetFuelCapacity(int cap)
{
    this->fuelCapacity = cap;
}
void Dacia::SetFuelConsumption(int con)
{
    this->fuelConsumption = con;
}
void Dacia::SetAvgSpeed(int spd)
{
    this->avgSpeed = spd;
}
Dacia::Dacia()
{
    this->SetFuelCapacity(100);
    this->SetFuelConsumption(2);
    this->SetAvgSpeed(2);
    this->id = 1;
}
int Dacia::CalculateScore(int length, Weather w)
{
    int modifier;
    switch (w)
    {
    case Rain:
        modifier = 0;
        break;
    case Sunny:
        modifier = 1;
        break;
    case Snow:
        modifier = -1;
        break;
    }
    int reqSteps = length / (this->avgSpeed + modifier);
    int posSteps = this->fuelCapacity / this->fuelConsumption;
    if (posSteps >= reqSteps)
        return reqSteps;
    else
        return -1;
}