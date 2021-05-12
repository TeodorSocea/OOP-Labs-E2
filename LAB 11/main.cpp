#include "Array.h"
#include <iostream>
using namespace std;

int main()
{

    Array<int> MyIntArray(10);
    try
    {
        cout << MyIntArray[100];
    }
    catch (ArrayException &e)
    {
        cout << "Exception: " << e.what();
    }

    Array<char> MyCharArray;
    try
    {
        MyCharArray += 'c';
    }
    catch (ArrayException &e)
    {
        cout << "Exception: " << e.what();
    }

    Array<float> MyFloatArray(15);
    try
    {
        MyFloatArray.Insert(15, 0.11);
    }
    catch (ArrayException &e)
    {
        cout << "Exception: " << e.what();
    }
}