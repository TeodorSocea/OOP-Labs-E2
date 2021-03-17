#include "Numbers.h"
#include <cstring>
Number::Number(const char *value, int base)
{
    this->value = new char[strlen(value)];
    memcpy(this->value, value, strlen(value) * sizeof(char));
    this->base = base;
}