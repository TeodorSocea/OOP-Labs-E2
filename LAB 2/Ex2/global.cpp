#include "global.hpp"
#include <stdlib.h>

int cmpName(Student &a, Student &b){
    int i = 0;
    char* namea = a.getName();
    char* nameb = b.getName();
    while( namea[i] != '\0' && nameb[i] != '\0'){
        if(namea[i] > nameb[i]){
            return 1;
        }else if(namea[i] < nameb[i]){
            return -1;
        }
        i++;
    }
    return namea[i] == '\0' ? -1 : 1;
}

int cmpMath(Student &a, Student &b){
    return a.getMath() > b.getMath() ? 1 : -1;
}
int cmpEng(Student &a, Student &b){
    return a.getEng() > b.getEng() ? 1 : -1;
}
int cmpHis(Student &a, Student &b){
    return a.getHis() > b.getHis() ? 1 : -1;
}

int cmpAvg(Student &a, Student &b){
    return a.getAvg() > b.getAvg() ? 1 : -1;
}