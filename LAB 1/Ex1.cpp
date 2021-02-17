#include <iostream>
using namespace std;
int main(){
    FILE *fptr = fopen("input.in", "rw");
    if(fptr == NULL){
        cout<<"File open failed.";
    }
}