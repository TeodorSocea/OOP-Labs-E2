#include "Math.h"
#include <cstdarg>
int Math::Add(int a, int b){
    return a + b;
}

int Math::Add(int a, int b, int c){
    return a + b + c;
}

int Math::Add(double a, double b){
    return a + b;
}

int Math::Add(double a, double b, double c){
    return a + b + c;
}

int Math::Mul(int a, int b){
    return a * b;
}

int Math::Mul(int a, int b, int c){
    return a * b * c;
}

int Math::Mul(double a, double b){
    return a * b;
}

int Math::Mul(double a, double b, double c){
    return a * b * c;
}

int Math::Add(int count, ...){
    int r = count;
    va_list va;
    va_start(va, count);
    while(int v = va_arg(va, int)){
        r += v;
    }
    va_end(va);
    return r;
}