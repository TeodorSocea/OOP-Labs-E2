#include "global.hpp"
#include <stdio.h>
#include <iostream>
int main(){
    Student s1;
    Student s2;
    char name[40];
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

    

    printf("Let's create a another student! What is his name: ");
    scanf("%s", name);
    s2.setName(name);
    printf("%s", s1.getName());
    printf("%s", s2.getName());
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
    s1.printGrades();
    
    printf("%s", s1.getName());

    printf("%d", cmpName(s1, s2));

}