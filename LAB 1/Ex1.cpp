#include <iostream>
#include <cstring>
using namespace std;
int char_to_int(char buffer[]){
    int output = 0;
    for(int i = 0; i < strlen(buffer)-1; i++){
        output = output * 10 + buffer[i] - '0';
    }
    printf("%d\n", output);
    return output;
}

int main(){
    FILE *fptr = fopen("in.txt", "r");
    if(fptr == NULL){
        printf("File open failed.\n");
        return 0;
    }
    else{
        printf("File open successful.\n");
        char buffer[100];
        int sum = 0;
        fgets(buffer, 100, fptr);
        while(feof(fptr)){
            sum += char_to_int(buffer);
        }
        fclose(fptr);
        printf("%d", sum);
        return 0;
    }
}