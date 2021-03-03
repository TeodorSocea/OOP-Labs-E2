#include "Canvas.h"
#include <stdlib.h>
using namespace std;

int main(){
    Canvas C(20, 10);
    C.Clear();
    C.Print();
    C.SetPoint(9, 5, 'T');
    C.Print();
}
