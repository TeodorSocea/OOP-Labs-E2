#include "Math.h"
#include <cstdarg>
#include <cstring>
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

char* Math::Add(const char* a , const char* b){
    char output[1000];
    const char* maxnum = strlen(a) > strlen(b) ? a : b;
    const char* minnum = strlen(a) > strlen(b) ? b : a;
    int i = strlen(maxnum);
    int j = strlen(minnum);
    int k = 0;
    int carry = 0;
    while(j != 0){
        output[k++] = (maxnum[i-1] - '0' + minnum[j-1] - '0') % 10 + carry + '0' ;
        carry = (maxnum[i-1] - '0' + minnum[j-1] - '0') /10 != 0 ? 1 : 0;
        i--;
        j--;
    }
    while(i){
        output[k++] = maxnum[i-1];
        i--;
    }
    output[k] = '\0';
    for(int x = 0, y = k-1; x<y; x++, y--){
        char aux = output[x];
        output[x] = output[y];
        output[y] = aux;
    }
    return output;
}