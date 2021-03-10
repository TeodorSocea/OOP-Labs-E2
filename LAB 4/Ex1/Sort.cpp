#include "Sort.h"
#include <stdio.h>
#include <cstdlib>
#include <iterator>
#include <cstdarg>

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
    this->data = new int[this->count];
    for(int i = 0 ; i < this->count; i++){
        this->data[i] = rand() % (maxi - mini + 1) + mini; 
    }
}

Sort::Sort(std::initializer_list<int> list) : data(new int[list.size()]){
    std::copy(std::begin(list), std::end(list), this->data);
    this->count = list.size();
}

Sort::Sort(int count, int* input_array){
    this->count = count;
    this->data = new int[this->count];
    for(int i = 0; i < this->count; i++)
        this->data[i] = input_array[i];
}

Sort::Sort(int count...){
    this->count = count;
    this->data = new int[this->count];
    va_list args;
    va_start(args, count);
    for(int i = 0 ; i < this->count; i++)
        this->data[i] = va_arg(args, int);
    va_end(args);
}   