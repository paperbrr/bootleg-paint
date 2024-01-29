#include "Decs.h"
#include <stdio.h>

SDL_Color colorsArr[] = {{1,1,1,255},  //placeholder btw
                         {0,0,0,255},
                         {255, 255, 255, 255},
                         {200, 0, 0, 255},
                         {0, 0, 200, 255},
                         {0, 200, 0, 255},
                         {220, 220, 0, 255},
                         {148, 0, 211, 255},
                         {255, 165, 0, 200},
                         {255, 218, 185, 255},
                         {90, 90, 98, 255}};

typedef enum {
    none,
    black,
    white,
    red,
    green,
    blue,
    yellow,
    purple,
    orange,
    peach,
    grey
} colors;

void brushToPeach(){
    brushColor = colorsArr[peach];
}
void brushToBlack(){
    brushColor = colorsArr[black];
}
void brushToWhite(){
    brushColor = colorsArr[white];
}
void brushToRed(){
    brushColor = colorsArr[red];
}
void brushToGreen(){
    brushColor = colorsArr[green];
}
void brushToBlue(){
    brushColor = colorsArr[blue];
}
void brushToYellow(){
    brushColor = colorsArr[yellow];
}
void brushToOrange(){
    brushColor = colorsArr[orange];
}
void brushToGrey(){
    brushColor = colorsArr[grey];
}
void brushToPurple(){
    brushColor = colorsArr[purple];
}


void createAllButtons(ButtonsArray* buttonsArr){
    createButton(buttonsArr, 10, 10, 30, 69, brushToPeach, colorsArr[peach]);
    createButton(buttonsArr, 89, 10, 30, 69, brushToBlack, colorsArr[black]);
    createButton(buttonsArr, 168, 10, 30, 69, brushToWhite, colorsArr[white]);
    createButton(buttonsArr, 247, 10, 30, 69, brushToRed, colorsArr[red]);
    createButton(buttonsArr, 326, 10, 30, 69, brushToGreen, colorsArr[green]);
    createButton(buttonsArr, 405, 10, 30, 69, brushToBlue, colorsArr[blue]);
    createButton(buttonsArr, 484, 10, 30, 69, brushToYellow, colorsArr[yellow]);
    createButton(buttonsArr, 563, 10, 30, 69, brushToOrange, colorsArr[orange]);
    createButton(buttonsArr, 642, 10, 30, 69, brushToGrey, colorsArr[grey]);
    createButton(buttonsArr, 721, 10, 30, 69, brushToPurple, colorsArr[purple]);
}