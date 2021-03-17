#include "Numbers.h"
#include <cstring>
#include <stdio.h>
Number::Number(const char *value, int base)
{
    this->value = new char[strlen(value)];
    memcpy(this->value, value, strlen(value) * sizeof(char));
    this->base = base;
}

void Number::Print()
{
    printf("Base: %d, Value: %s\n", this->base, this->value);
}