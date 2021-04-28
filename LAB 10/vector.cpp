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

int MyVector::getSize()
{
    return Size;
}

bool MyVector::Add(int elem)
{
    if (Size == Capacity)
        throw CapacityExceeded();
    Elements[Size++] = elem;
    return true;
}

bool MyVector::Delete(int index)
{
    if (index < 0 || index >= Size)
    {
        throw IndexOutOfBounds();
    }
    for (int i = index; i < Size - 1; i++)
    {
        Elements[i] = Elements[i + 1];
    }
    Size--;
    return true;
}

void MyVector::Iterate(int (*fnc)(int &e1))
{
    for ()
}