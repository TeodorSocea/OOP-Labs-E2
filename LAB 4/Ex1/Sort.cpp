#include "Sort.h"
#include <stdio.h>
void Sort::Print(){
    for(int i = 0 ; i < this->count; i++)
        printf("%d ", this->data[i]);
    printf("\n");
}
