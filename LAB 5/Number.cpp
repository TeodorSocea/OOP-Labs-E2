#include "Numbers.h"
#include <cstring>
#include <stdio.h>
#include <ctype.h>

void Number::setValue(const char *value)
{
    memcpy(this->value, value, strlen(value) * sizeof(char) + 1);
}

char *Number::getValue()
{
    return this->value;
}

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
}

Number::~Number()
{
    delete[] this->value;
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

char Number::operator[](int index)
{
    if (index < this->GetDigitsCount())
        return this->value[index];
}

char *Add(const char *a, const char *b)
{
    char output[1000];
    const char *maxnum = strlen(a) > strlen(b) ? a : b;
    const char *minnum = strlen(a) > strlen(b) ? b : a;
    int i = strlen(maxnum);
    int j = strlen(minnum);
    int k = 0;
    int carry = 0;
    while (j != 0)
    {
        output[k++] = (maxnum[i - 1] - '0' + minnum[j - 1] - '0') % 10 + carry + '0';
        carry = (maxnum[i - 1] - '0' + minnum[j - 1] - '0') / 10 != 0 ? 1 : 0;
        i--;
        j--;
    }
    while (i)
    {
        output[k++] = maxnum[i - 1];
        i--;
    }
    output[k] = '\0';
    for (int x = 0, y = k - 1; x < y; x++, y--)
    {
        char aux = output[x];
        output[x] = output[y];
        output[y] = aux;
    }
    return output;
}

void operator+(Number &a, Number b)
{
    int old_base = a.GetBase();
    b.SwitchBase(10);
    a.SwitchBase(10);
    a.setValue(Add(a.getValue(), b.getValue()));
    a.Print();
    a.SwitchBase(old_base);
}

void Number::SwitchBase(int newBase)
{
    char output[1000];
    int X = this->base;
    int value = 0, i = 0;
    for (int k = 0; k < strlen(this->value); k++)
    {
        value = (X * value) + (isalpha(this->value[i]) ? (this->value[i] - 'A' + 10) : (this->value[i] - '0'));
    }
    while (value)
    {
        output[i] = (value % newBase < 10) ? ((value % newBase) + '0') : ((value % newBase) - 10 + 'A');
        value /= newBase;
        i++;
    }
    memcpy(this->value, output, strlen(output) * sizeof(char));
    this->base = newBase;
}