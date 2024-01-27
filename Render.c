#include <stdio.h>
#include <SDL.h>
#include "Decs.h"

void renderNext(Workspace* workspace){
    SDL_Renderer* renderer = workspace->renderer;

    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    SDL_RenderClear(renderer);

    //SDL_RenderCopy(renderer, workspace->oikawaTexture, NULL, &textureRect);
    for (int i=0; i<workspace->blocksArr.blockCount; i++){
        setRenderColor(workspace->blocksArr.blocks[i]->blockColor, workspace->renderer);
        SDL_RenderFillRect(workspace->renderer, &workspace->blocksArr.blocks[i]->sourceRect);
        //SDL_RenderCopy(renderer, workspace->blocksArr.blocks[i]->blockTexture, NULL, &workspace->blocksArr.blocks[i]->sourceRect);
    }

    SDL_RenderPresent(renderer);
}