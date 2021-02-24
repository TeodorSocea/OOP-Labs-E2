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