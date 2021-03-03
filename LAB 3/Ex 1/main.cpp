#include "Math.h"
#include <iostream>
int main(){
    Math mathObj;
    std::cout<<mathObj.Add(1, 2 ,3 ,4);
    std::cout<<'\0';
    std::cout<<mathObj.Add("1234", "1234");
}