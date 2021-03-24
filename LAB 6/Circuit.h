#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Weather.h"
#include "Car.h"
class Circuit
{
    int length, nr_cars, nr_winners, nr_losers, cars_size, winners_size, losers_size;
    Weather weather;
    Car **cars;
    Car **winners;
    Car **losers;

public:
    Circuit();
    void SetLength(int);
    void SetWeather(Weather);
    void AddCar(Car *);
    void AddWinner(Car *);
    void AddLoser(Car *);
    void Race();
    void ShowCars();
    void ShowNrCars();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};

int CompareScores(int, int);

#endif