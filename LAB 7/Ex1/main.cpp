#include <stdlib.h>
#include <stdio.h>
float operator""_Kelvin(const char *val)
{
    return val[0] == '-' ? -atof(val) : atof(val) + 273.15;
}
float operator""_Fahrenheit(const char *val)
{
    return (val[0] == '-' ? -atof(val) : atof(val) * 1.8) + 32;
}

int main()
{
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    float c = -100_Kelvin; //unfortunately this doesn't work because literals can't take negative values
    float d = -100_Fahrenheit;

    printf("%f %f %f %f\n", a, b, c, d);

    return 0;
}