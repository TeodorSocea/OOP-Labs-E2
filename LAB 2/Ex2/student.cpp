#include "student.hpp"
#include <stdlib.h>
#include <stdio.h>

void Student::setName(char * name){
    this->name = name;
}

void Student::setMath(float x){
    if(x < 0 || x > 10)
        return;
    this->grades.math = x;
}