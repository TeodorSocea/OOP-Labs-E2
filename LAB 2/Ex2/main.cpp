#include "global.hpp"
#include <stdio.h>
int main(){
    Student s1, s2;
    char* name;
    float grade;
    
    printf("Let's create a student! What is his name: ");
    scanf("%s", name);
    s1.setName(name);
    printf("Math grade: ");
    scanf("%f", &grade);
    s1.setMath(grade);
    printf("English grade: ");
    scanf("%f", &grade);
    s1.setEng(grade);
    printf("History grade: ");
    scanf("%f", &grade);
    s1.setHis(grade);

    s1.printGrades();
}