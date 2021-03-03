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

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){
    int minx = left < right ? left : right;
    int maxx = left > right ? left : right;
    int miny = top < bottom ? top : bottom;
    int maxy = top > bottom ? top : bottom;

    for(int i = minx; i < maxx; i++){
        for(int j = miny; j < maxy; j++){
            if(i == minx || i == maxx-1)
                this->SetPoint(i, j, ch);
            else if(j == miny || j == maxy-1)
                this->SetPoint(i, j, ch);
        }
    }
}
