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

Number::Number(const Number &n)
{
    this->value = n.value;
    this->base = n.base;
}

Number::Number(Number &&n)
{
    this->value = n.value;
    this->base = n.base;
    delete &n.value;
    delete &n;
}

Number::~Number()
{
    delete[] this->value;
    delete[] this;
}
