#include <SDL.h>
#include "../Decs.h"
#include <stdio.h>
#include <SDL_image.h>

void blockArrayInit(BlockArray* blockArr, int initialSize){
    //initialSize is just to create some placeholder data for now :D
    blockArr->blocks = malloc(initialSize*sizeof(Block*));
    if (blockArr==NULL){
        printf("ERROR");
        exit(1);
    }

    blockArr->blockCount = 0;
    blockArr->blockArrSize = initialSize*sizeof(Block*);
}

void createBlock(Workspace* workspace, int pos_x, int pos_y, int width, int height, SDL_Color color){

    BlockArray* blockArr = &workspace->blocksArr;

    Block* block = malloc(sizeof(Block));
    if (block==NULL) {
        printf("ERROR");
        exit(1);
    }
    
    block->sourceRect.x = pos_x;
    block->sourceRect.y = pos_y;
    block->sourceRect.h = height;
    block->sourceRect.w = width;
    block->blockColor = color;

    /*SDL_Surface* blockSurface;
    blockSurface = IMG_Load("resources/blockTexture.png");
    block->blockTexture = SDL_CreateTextureFromSurface(workspace->renderer, blockSurface);
    SDL_FreeSurface(blockSurface);*/

    blockArr->blocks = realloc(blockArr->blocks, blockArr->blockArrSize+sizeof(block));
    if (blockArr == NULL){
        printf("ERROR");
        exit(1);
    }

    blockArr->blocks[blockArr->blockCount] = block;
    blockArr->blockCount += 1;
    blockArr->blockArrSize += sizeof(block);
}

void deleteBlock(Workspace* workspace, int mouseX, int mouseY){
    //deletes the block at that POSITION
    BlockArray* blockArr = &workspace->blocksArr;

    int index = -1;
    for (int i=0; i<blockArr->blockCount; i++){
        if (blockArr->blocks[i]->sourceRect.x == mouseX && blockArr->blocks[i]->sourceRect.y == mouseY) {
            index = i;
            break;
        }
    }
    if (index<0){
        printf("BLOCK NOT FOUND?!?");
    }
    else{
        int sizeOfDeletedBlock = sizeof(blockArr->blocks[index]);
        for (int i=index; i<blockArr->blockCount-1;i++){
            blockArr->blocks[i] = blockArr->blocks[i+1];
        }
        blockArr->blocks = realloc(blockArr->blocks, blockArr->blockArrSize-sizeOfDeletedBlock);
        if (blockArr->blocks == NULL){
            printf("ERROR");
            exit(1);
        }
        blockArr->blockArrSize -= sizeOfDeletedBlock;
        blockArr->blockCount -= 1;
    }
}

void freeBlockArray(BlockArray* blocksArr){
    free(blocksArr->blocks);
    blocksArr->blockArrSize = 0;
    blocksArr->blockCount = 0;
}