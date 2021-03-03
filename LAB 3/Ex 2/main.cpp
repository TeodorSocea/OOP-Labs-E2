#include "Canvas.h"
#include <stdlib.h>
using namespace std;

int main(){
    Canvas C(20, 20);
    C.SetPoint(0, 0, '*');
    C.DrawCircle(10, 10, 7, '*');
    C.Print();
}
