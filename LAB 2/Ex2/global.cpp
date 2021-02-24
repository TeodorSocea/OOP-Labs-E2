#include "global.hpp"
#include <stdlib.h>

int cmpName(Student a, Student b){
    int i = 0;
    char* nameA = a.getName();
    char* nameB = b.getName();

    while(nameA[i] != '\0' && nameB[i] != '\0'){
        if(nameA[i] > nameB[i]){
            return 1;
        }else if(nameA[i] < nameB[i]){
            return -1;
        }
        i++;
    }
    return nameA[i] == '\0' ? -1 : 1;
}

int cmpMath(Student a, Student b){
    return a.getMath() > b.getMath() ? 1 : -1;
}
int cmpEng(Student a, Student b){
    return a.getEng() > b.getEng() ? 1 : -1;
}
int cmpHis(Student a, Student b){
    return a.getHis() > b.getHis() ? 1 : -1;
}