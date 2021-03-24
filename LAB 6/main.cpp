#include "Circuit.h"
#include "Car.h"
#include "Dacia.h"
#include "Toyota.h"
#include "Mercedes.h"
#include "Ford.h"
#include "Mazda.h"
#include <stdio.h>
#include "Weather.h"
int main()
{
    Circuit c;

    Dacia *ca = new Dacia;
    printf("%d", ca->getId());

    c.SetLength(100);

    c.SetWeather(Weather::Rain);

    c.AddCar(new Dacia());

    //c.ShowCars();

    c.AddCar(new Toyota());

    c.AddCar(new Mercedes());

    c.AddCar(new Ford());

    c.AddCar(new Mazda());
    c.ShowNrCars();

    //c.Race();

    c.ShowCars();

    //c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.

    //c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit

    return 0;
}