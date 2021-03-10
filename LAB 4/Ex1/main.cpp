#include "Sort.h"

using namespace std;

int main(){
    int p[] = {1, 2, 3, 4, 5, 6, 7};
    Sort elements("1, 2, 3, 4, 5, 6, 7, 8, 9, 0");
    elements.Print();
    elements = elements+5;
    elements.Print();
    elements.BubbleSort();
    elements.Print();
    elements = 10 + elements;
    elements.Print();
}