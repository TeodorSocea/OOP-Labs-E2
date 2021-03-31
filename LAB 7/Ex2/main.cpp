#include "vector.h"
#include <stdio.h>
#include <cstring>
#include <iostream>
struct tuplu
{
    int x, y;
};

int main()
{
    vector<tuplu> myV;
    tuplu A;
    A.x = 1;
    A.y = 2;
    myV.push(A);
    tuplu B;
    B.x = 3;
    B.y = 4;
    myV.push(B);
    printf("%d, %d\n", myV.get(0).x, myV.get(0).y);
    printf("%d, %d\n", myV.get(1).x, myV.get(1).y);
    myV.sort([](tuplu a, tuplu b) { return a.x + a.y < b.x + b.y ? 1 : -1; });
    printf("%d, %d\n", myV.get(0).x, myV.get(0).y);
    printf("%d, %d\n", myV.get(1).x, myV.get(1).y);
}