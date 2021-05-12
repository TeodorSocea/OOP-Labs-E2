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
        cout << e.what();
    }
}