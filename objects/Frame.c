#include <SDL.h>
#include "../Decs.h"
#include <stdio.h>
#include <SDL_image.h>

void frameArr_init(FramesArray* framesArr, int initialSize){
    framesArr->frames = malloc(initialSize*sizeof(Frame));
    if (framesArr->frames==NULL){
        printf("ERROR");
        exit(1);
    }
    framesArr->length = 0;
    framesArr->arrDataSize = initialSize*sizeof(Frame);
}

void createFrame(FramesArray* framesArr, int x, int y, int w, int h, SDL_Color frameColor){
    Frame* newFrame = malloc(sizeof(Frame));
    newFrame->sourceRect.x = x;
    newFrame->sourceRect.y = y;
    newFrame->sourceRect.h = h;
    newFrame->sourceRect.w = w;
    newFrame->color = frameColor;

    framesArr->frames = realloc(framesArr->frames, framesArr->arrDataSize+sizeof(newFrame));
    if (framesArr->frames==NULL){
        printf("ERROR");
        exit(1);
    }

    framesArr->frames[framesArr->length] = newFrame;
    framesArr->length += 1;
    framesArr->arrDataSize += sizeof(newFrame);
}

void renderFrames(FramesArray* framesArr, SDL_Renderer* renderer){
    for (int i=0; i<framesArr->length; i++){
        SDL_Color renderColor = framesArr->frames[i]->color;
        SDL_SetRenderDrawColor(renderer, renderColor.r, renderColor.g, renderColor.b, renderColor.a);
        SDL_RenderFillRect(renderer, &framesArr->frames[i]->sourceRect);
    }
}

void freeFramesArray(FramesArray* framesArr){
    free(framesArr->frames);
    framesArr->arrDataSize = 0;
    framesArr->length = 0;
}