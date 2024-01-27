#include <stdio.h>
#include <SDL.h>
#include "Decs.h"
#include <math.h>

SDL_Color black = {0, 0, 0};
SDL_Color white = {255, 255, 255};
SDL_Color red = {200, 0, 0};
SDL_Color blue = {0, 200, 0};
SDL_Color green = {0, 0, 200};
SDL_Color yellow = {220, 220, 0};
SDL_Color purple = {148, 0, 211};
SDL_Color orange = {100, 64, 0};
SDL_Color lavender = {90, 90, 98};
SDL_Color grey = {152, 115, 172};

void snapToGrid(int* mouseX, int* mouseY);

void eventHandler(int* gameLoop, SDL_Event* event, Workspace* workspace){
    if (event->type == SDL_QUIT) {
        *gameLoop = 0;
    }
    else if (event->type == SDL_MOUSEBUTTONDOWN) {
        int xPos = event->motion.x; int yPos = event->motion.y;
        snapToGrid(&xPos, &yPos);
        if (event->button.button == SDL_BUTTON_LEFT) {
            SDL_Color color = {100, 150, 200, 255};
            createBlock(workspace, xPos, yPos, 50, 50, lavender);
        }
        else{
            deleteBlock(workspace, xPos, yPos);
        }
    }
}

void snapToGrid(int* mouseX, int* mouseY){
    *mouseX = 50*floor((double) *mouseX/50);
    *mouseY = 50*floor((double) *mouseY/50);
}