#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>
Canvas::Canvas(int width, int height){
    this->width = width;
    this->height = height;
    char **mat = (char **)malloc(height * sizeof(char*));
    for(int i = 0; i < height; i++)
        mat[i] = (char *)malloc(width * sizeof(char));
    this->board = mat;
    delete(mat);
}

void Canvas::SetPoint(int x, int y, char ch){
    this->board[x][y] = ch;
}

void Canvas::Print(){
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++){
            printf("%c", this->board[i][j]);
        }
}
void Canvas::Clear(){
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++){
            this->board[i][j] = ' ';
        }
}