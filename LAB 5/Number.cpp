#include "Numbers.h"
#include <cstring>
#include <stdio.h>
#include <ctype.h>
Number::Number(const char *value, int base)
{
    this->value = new char[strlen(value) + 1];
    memcpy(this->value, value, (strlen(value) + 1) * sizeof(char));
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

void Number::operator=(Number &n)
{
    this->value = n.value;
    this->base = n.base;
}

int Number::GetDigitsCount()
{
    return strlen(this->value);
}

int Number::GetBase()
{
    return this->base;
}

void Number::SwitchBase(int newBase)
{
    printf("Debugging\n");
    char output[1000];
    int X = this->base;
    int value = 0, i = 0;
    for (int k = 0; k < strlen(this->value); k++)
    {
        printf("Debugging for\n");
        value = (X * value) + (isalpha(this->value[i]) ? (this->value[i] - 'A' + 10) : (this->value[i] - '0'));
    }
    while (value)
    {
        printf("Debugging while\n");
        output[i] = (value % newBase < 10) ? ((value % newBase) + '0') : ((value % newBase) - 10 + 'A');
        value /= newBase;
        i++;
    }
    printf("Debugging out\n");
    memcpy(this->value, output, strlen(output) * sizeof(output));
    this->base = newBase;
    printf("Debugging end\n");
}