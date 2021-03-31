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

    vector<char *> myVect;
    myVect.push("Number 1");
    myVect.push("Number 2");
    myVect.push("Number 3");
    myVect.push("Number 4");
    myVect.push("Number 5");
    printf("%s\n", myVect[0]);
    myVect.sort([](char *a, char *b) { return a[strlen(a) - 1] - '0' < b[strlen(b) - 1] - '0' ? 1 : -1; });
    printf("%s ", myVect[0]);
    printf("%s ", myVect[1]);
    printf("%s ", myVect[2]);
    printf("%s ", myVect[3]);
    printf("%s\n", myVect[4]);
    myVect.set("Number 6", 0);
    printf("%s\n", myVect[0]);
    printf("%d ", myVect.firstIndexOf("Number 2", [](char *a, char *b) { return strcmp(a, b) == 0 ? 1 : -1; }));
}