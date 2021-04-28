#include "vector.h"

MyVector::MyVector(int capacity)
{
    Capacity = capacity;
    Size = 0;
    Elements = new int[Capacity];
}

MyVector::~MyVector()
{
    delete[] Elements;
}

int &MyVector::operator[](int index)
{
    if (index < 0 || index >= Size)
        throw IndexOutOfBounds();
    return Elements[index];
}
