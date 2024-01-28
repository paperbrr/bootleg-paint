#include <stdio.h>
#include <SDL.h>
#include "Decs.h"
#include <math.h>

SDL_Color black = {0, 0, 0, 255};
SDL_Color white = {255, 255, 255, 255};
SDL_Color red = {200, 0, 0, 255};
SDL_Color blue = {0, 0, 200, 255};
SDL_Color green = {0, 200, 0, 255};
SDL_Color yellow = {220, 220, 0, 255};
SDL_Color purple = {148, 0, 211, 255};
SDL_Color orange = {255, 165, 0, 200};
SDL_Color peach = {255, 218, 185, 255};
SDL_Color grey = {90, 90, 98, 255};

SDL_Color renderColor;

void snapToGrid(int* mouseX, int* mouseY);

void eventHandler(int* gameLoop, SDL_Event* event, Workspace* workspace){
    if (event->type == SDL_QUIT) {
        *gameLoop = 0;
    }
    else if (event->type == SDL_MOUSEBUTTONDOWN) {
        int xPos = event->motion.x; int yPos = event->motion.y;
        snapToGrid(&xPos, &yPos);
        if (yPos<100) return;
        if (event->button.button == SDL_BUTTON_LEFT) {
            SDL_Color color = {100, 150, 200, 255};
            createBlock(workspace, xPos, yPos, 50, 50, renderColor);
        }
        else{
            deleteBlock(workspace, xPos, yPos);
        }
    }
    else if (event->type == SDL_KEYDOWN){
        int keycode = event->key.keysym.sym;
        if (keycode==SDLK_1){renderColor=black;}
        else if (keycode==SDLK_2){renderColor=red;}
        else if (keycode==SDLK_3){renderColor=green;}
        else if (keycode==SDLK_4){renderColor=blue;}
        else if (keycode==SDLK_5){renderColor=yellow;}
        else if (keycode==SDLK_6){renderColor=orange;}
        else if (keycode==SDLK_7){renderColor=purple;}
        else if (keycode==SDLK_8){renderColor=grey;}
        else if (keycode==SDLK_9){renderColor=peach;}
    }
}

void snapToGrid(int* mouseX, int* mouseY){
    *mouseX = 50*floor((double) *mouseX/50);
    *mouseY = 50*floor((double) *mouseY/50);
}