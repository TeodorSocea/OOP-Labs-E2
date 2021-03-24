#include "Ford.h"
#include "Weather.h"
void Ford::SetFuelCapacity(int cap)
{
    this->fuelCapacity = cap;
}
void Ford::SetFuelConsumption(int con)
{
    this->fuelConsumption = con;
}
void Ford::SetAvgSpeed(int spd)
{
    this->avgSpeed = spd;
}
Ford::Ford()
{
    this->SetFuelCapacity(200);
    this->SetFuelConsumption(3);
    this->SetAvgSpeed(3);
    this->id = 4;
}
int Ford::CalculateScore(int length, Weather w)
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