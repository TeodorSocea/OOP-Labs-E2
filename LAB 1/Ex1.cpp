#include <iostream>
#include <cstring>
using namespace std;
int main(){
    FILE *fptr = fopen("in.txt", "rw");
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