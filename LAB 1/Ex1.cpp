#include <iostream>
using namespace std;
int main(){
    FILE *fptr = fopen("input.in", "rw");
    if(fptr == NULL){
        cout<<"File open failed.";
        return 0;
    }
    else{
        char *buffer;
        fgets(buffer, 100, fptr);
        while(!feof(fptr)){
            
        }
    }
}