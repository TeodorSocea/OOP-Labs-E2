#include "Numbers.h"

int main()
{

    Number a("110", 2);
    a.Print();
    Number b("1002", 2);
    b.Print();
    b.SwitchBase(10);
    b.Print();
    a.Print();
}