#include "student.hpp"
#include <stdlib.h>
#include <stdio.h>

void Student::setName(char *name){
    this->name = name;
}

void Student::setMath(float x){
    if(x < 0 || x > 10)
        return;
    this->grades.math = x;
}
void Student::setEng(float x){
    if(x < 0 || x > 10)
        return;
    this->grades.eng = x;
}
void Student::setHis(float x){
    if(x < 0 || x > 10)
        return;
    this->grades.his = x;
}

char* Student::getName(){
    return this->name;
}

float Student::getMath(){
    return this->grades.math;
}
float Student::getEng(){
    return this->grades.eng;
}
float Student::getHis(){
    return this->grades.his;
}

float Student::getAvg(){
    this->avg = (this->grades.math + this->grades.eng + this->grades.his) / 3;
    return this->avg;
}

void Student::printGrades(){
    
    printf("Name: %s. Math: %.2f English: %.2f History: %.2f Averege: %.2f\n", this->name, this->grades.math, this->grades.eng, this->grades.his, this->getAvg());
}