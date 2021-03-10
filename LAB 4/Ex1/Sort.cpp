#include "Sort.h"
#include <stdio.h>
#include <cstdlib>
#include <iterator>
#include <cstdarg>

int getNumbersCountFromInputString(char * input_string){
    int count_output = 1;
    for (int i = 0; i < strlen(input_string); i++)
        if (input_string[i] == ',')
            count_output++;
    return count_output;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

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

Sort::Sort(char *input_string){
    this->count = getNumbersCountFromInputString(input_string);
    this->data = new int[this->count];
    int k = 0, num = 0;
    for (int i = 0; i <= strlen(input_string); i++)
    {
        if (input_string[i] == ',' || input_string[i] == '\0')
        {
            data[k++] = num;
            num = 0;
        }
        else if (iswdigit(input_string[i]))
            num = num * 10 + (input_string[i] - '0');
    }
}

void Sort::InsertSort(bool ascendent)
{
    if (ascendent)
    {
        for (int i = 1; i < this->count; i++)
        {
            int key = this->data[i];
            int j = i - 1;
            while (j >= 0 && this->data[j] > key)
            {
                this->data[j + 1] = this->data[j];
                j = j - 1;
            }
            this->data[j + 1] = key;
        }
    }
    else
    {
        for (int i = 1; i < this->count; i++)
        {
            int key = this->data[i];
            int j = i - 1;
            while (j >= 0 && this->data[j] < key)
            {
                this->data[j + 1] = this->data[j];
                j = j - 1;
            }
            this->data[j + 1] = key;
        }
    }
}

void Sort::BubbleSort(bool ascendent)
{
    for (int i = 0; i < this->count - 1; i++)
        for (int j = 0; j < this->count - i - 1; j++)
            if (ascendent)
            {
                if (this->data[j] > this->data[j + 1])
                    swap(&this->data[j], &this->data[j + 1]);
            }
            else
            {
                if (this->data[j] < this->data[j + 1])
                    swap(&this->data[j], &this->data[j + 1]);
            }
}