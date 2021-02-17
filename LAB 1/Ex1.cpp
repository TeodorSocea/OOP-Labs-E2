#include <iostream>
#include <cstring>
using namespace std;
int char_to_int(char *buffer){
    int p = 1, output = 0;
    for(int i = 0; i < strlen(buffer); i++){
        output = p * (buffer[i]-'0') + output;
        p *= 10;
    }
    return output;
}

int main(){
    FILE *fptr = fopen("in.txt", "rw");
    if(fptr == NULL){
        printf("File open failed.");
        return 0;
    }
    else{
        char *buffer;
        fgets(buffer, 100, fptr);
        while(!feof(fptr)){
            
        }
    }
}