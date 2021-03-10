#include "Sort.h"
#include <stdio.h>

void Sort::Print(){
    for(int i = 0 ; i < this->count; i++)
        printf("%d ", this->data[i]);
    printf("\n");
}

int Sort::GetElementsCount(){
    return this->count;
}

int Sort::GetElementFromIndex(int index){
    return this->data[index];
}
