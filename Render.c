#include <stdio.h>
#include <SDL.h>
#include "Decs.h"

void renderNext(Workspace* workspace){
    SDL_Renderer* renderer = workspace->renderer;

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);

    //SDL_RenderCopy(renderer, workspace->oikawaTexture, NULL, &textureRect);
    for (int i=0; i<workspace->blocksArr.blockCount; i++){
        SDL_RenderCopy(renderer, workspace->blocksArr.blocks[i]->blockTexture, NULL, &workspace->blocksArr.blocks[i]->sourceRect);
    }

    SDL_RenderPresent(renderer);
}