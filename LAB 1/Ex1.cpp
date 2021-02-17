#include <iostream>
#include <cstring>
using namespace std;
int char_to_int(char buffer[]){
    int output = 0;
    for(int i = 0; i < strlen(buffer); i++){
        output = (buffer[i]-'0') + output*10;
    }
    return output;
}

int main(){
    FILE *fptr = fopen("in.txt", "r");
    if(fptr == NULL){
        printf("File open failed.");
        return 0;
    }
    else{
        printf("File open successful.");
        char buffer[100];
        int sum = 0;
        while(fgets(buffer, 100, fptr)!=NULL){
            sum += char_to_int(buffer);
        }
        fclose(fptr);
        printf("%d", sum);
        return 0;
    }
}