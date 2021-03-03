#include "Canvas.h"
#include <stdlib.h>
using namespace std;

int main(){
    Canvas C(20, 20);
    C.DrawRect(0, 5, 19, 19, '*');
    C.Print();
}
