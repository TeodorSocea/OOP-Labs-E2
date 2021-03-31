#include <stdlib.h>
#include <stdio.h>
float operator""_Kelvin(const char *val)
{
    return val[0] == '-' ? -atof(val) : atof(val) + 273.15;
}