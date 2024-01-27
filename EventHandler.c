#include <stdio.h>
#include <SDL.h>
#include "Decs.h"
#include <math.h>

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
            createBlock(workspace, xPos, yPos, 50, 50, color);
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