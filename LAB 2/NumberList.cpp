#include "NumberList.hpp"
#include <stdlib.h>
#include <stdio.h>

void NumberList::Init(){
    this->count = 0;
}

bool NumberList::Add(int x){
    if(this->count != 10){
        this->numbers[this->count] = x;
        this->count++;
        return true;
    }
    else
        return false;
}

void NumberList::Sort(){
    for(int i = 0; i < this->count -1 ; i++){
        for(int j = i+1; j  < this->count; j++){
            if(this->numbers[i] > this->numbers[j]){
                swap(this->numbers[i], this->numbers[j]);
            }
        }
    }
}
void NumberList::Print(){
    for(int i = 0; i < this->count; i++){
        printf("%d ", this->numbers[i]);
        printf("\n");
    }
}