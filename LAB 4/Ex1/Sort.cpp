#include "Sort.h"
#include <stdio.h>
#include <cstdlib>

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

Sort::Sort(int count, int mini, int maxi){
    this->count = count;
    this->data = new int[count];
    for(int i = 0 ; i < this->count; i++){
        this->data[i] = rand() % (maxi - mini + 1) + mini; 
    }
}