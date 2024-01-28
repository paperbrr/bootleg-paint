#include "Decs.h"
#include <stdio.h>

void renderUI(SDL_Rect* buttonsPanel, SDL_Rect* canvas){
    //creates the panel, its buttons and a canvas
    //NOTE:NOT CUSTOMISABLE
    
    //creating the panel for buttons
    

}

void random(){
    printf("I AM DYIN");
}


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

void createAllButtons(ButtonsArray* buttonsArr){
    createButton(buttonsArr, 50, 50, 50, 50, random, colorsArr[peach-1]);
}