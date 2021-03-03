#include "Canvas.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
void Canvas::Clear(){
    for(int i = 0; i < this->height; i++)
        for(int j = 0; j < this->width; j++){
            this->SetPoint(i, j, ' ');
        }
}

Canvas::Canvas(int width, int height){
    this->width = width;
    this->height = height;
    char **mat = (char **)malloc(height * sizeof(char*));
    for(int i = 0; i < height; i++)
        mat[i] = (char *)malloc(width * sizeof(char));
    this->board = mat;
    this->Clear();
}

void Canvas::SetPoint(int x, int y, char ch){
    this->board[x][y] = ch;
}

void Canvas::Print(){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            printf("%c ", this->board[i][j]);
        }
        printf("\n");
    }
}

int distance(int x, int y, int i, int j){
    return sqrt((x-i)*(x-i)+(y-j)*(y-j));
}

void Canvas::DrawCircle(int x, int y, int ray, char ch){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            if(distance(x, y, i, j) == ray){
                this->SetPoint(i, j, ch);
            }
        }
    }
}
