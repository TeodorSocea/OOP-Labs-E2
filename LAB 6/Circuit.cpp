#include "Circuit.h"
#include "Weather.h"
#include <cstring>
#include <stdio.h>
#include <utility>
int CompareScores(int s1, int s2)
{
    if (s1 > s2)
        return 1;
    else
        return -1;
}

Circuit::Circuit()
{
    this->nr_cars = 0;
    this->nr_winners = 0;
    this->nr_losers = 0;
    this->cars_size = 1;
    this->cars = new Car *[cars_size];
    this->winners_size = 1;
    this->winners = new Car *[winners_size];
    this->losers_size = 1;
    this->losers = new Car *[losers_size];
}

void Circuit::SetLength(int len)
{
    this->length = len;
}

void Circuit::SetWeather(Weather w)
{
    this->weather = w;
}

void Circuit::AddCar(Car *car)
{
    if (nr_cars >= cars_size)
    {
        //resize it
        size_t newSize = cars_size * 2;
        Car **newArr = new Car *[newSize];
        std::memcpy(newArr, cars, cars_size * sizeof(Car *));
        cars_size = newSize;
        delete[] cars;
        cars = newArr;
    }
    this->cars[nr_cars] = car;
    nr_cars++;
}

void Circuit::AddWinner(Car *car)
{
    if (nr_winners >= winners_size)
    {
        //resize it
        size_t newSize = winners_size * 2;
        Car **newArr = new Car *[newSize];
        std::memcpy(newArr, winners, winners_size * sizeof(Car *));
        winners_size = newSize;
        delete[] winners;
        winners = newArr;
    }
    this->winners[nr_winners] = car;
    nr_winners++;
}

void Circuit::AddLoser(Car *car)
{
    if (nr_losers >= losers_size)
    {
        //resize it
        size_t newSize = losers_size * 2;
        Car **newArr = new Car *[newSize];
        std::memcpy(newArr, losers, losers_size * sizeof(Car *));
        losers_size = newSize;
        delete[] losers;
        losers = newArr;
    }
    this->losers[nr_losers] = car;
    nr_losers++;
}

void Circuit::Race()
{
    for (int i = 0; i < nr_cars; i++)
    {
        if (this->cars[i]->CalculateScore(this->length, this->weather) >= 0)
        {
            AddWinner(cars[i]);
        }
        else
        {
            AddLoser(cars[i]);
        }
    }
    for (int i = 0; i < nr_winners - 1; i++)
    {
        for (int j = i + 1; j < nr_winners; j++)
        {
            if (CompareScores(this->winners[i]->CalculateScore(this->length, this->weather), this->winners[j]->CalculateScore(this->length, this->weather)) == -1)
            {
                std::swap(this->winners[i], this->winners[j]);
            }
        }
    }
}

void Circuit::ShowCars()
{
    for (int i = 0; i < nr_cars; i++)
    {
        printf("%d. %d\n", i, cars[i]->getId());
    }
}

void Circuit::ShowNrCars()
{
    printf("%d\n", cars_size);
}

void Circuit::ShowFinalRanks()
{
    for (int i = 0; i < nr_losers; i++)
    {
        printf("%d. %d\n", i, this->winners[i]->getId());
    }
}
void Circuit::ShowWhoDidNotFinish()
{
    for (int i = 0; i < nr_losers; i++)
    {
        printf("%d. %d\n", i, this->losers[i]->getId());
    }
}
