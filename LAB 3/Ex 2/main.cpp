#include "Canvas.h"
#include <stdlib.h>
using namespace std;

int main(){
    Canvas C(10, 10);
    C.Clear();
    C.Print();
    C.SetPoint(5, 5, 'T');
    C.Print();
}
