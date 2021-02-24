#include "global.hpp"
#include <stdio.h>
#include <iostream>
int main(){
    Student s1, s2;
    char name[40];
    float grade;
    int len;
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

    printf("Let's create a another student! What is his name: ");
    scanf("%s", name);
    s2.setName(name);
    printf("Math grade: ");
    scanf("%f", &grade);
    s2.setMath(grade);
    printf("English grade: ");
    scanf("%f", &grade);
    s2.setEng(grade);
    printf("History grade: ");
    scanf("%f", &grade);
    s2.setHis(grade);

    s2.printGrades();

}