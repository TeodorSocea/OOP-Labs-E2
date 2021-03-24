#include "Mercedes.h"
#include "Weather.h"
void Mercedes::SetFuelCapacity(int cap)
{
    this->fuelCapacity = cap;
}
void Mercedes::SetFuelConsumption(int con)
{
    this->fuelConsumption = con;
}
void Mercedes::SetAvgSpeed(int spd)
{
    this->avgSpeed = spd;
}
Mercedes::Mercedes()
{
    this->SetFuelCapacity(200);
    this->SetFuelConsumption(1);
    this->SetAvgSpeed(3);
    this->id = 3;
}
int Mercedes::CalculateScore(int length, Weather w)
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