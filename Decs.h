#pragma once
#include <SDL.h>

typedef struct{
	int r;
	int g;
	int b;
	int a;
}Color;

typedef struct{
    SDL_Rect sourceRect;
    SDL_Texture* blockTexture;
} Block;

typedef struct{
	int blockCount;
	Block** blocks;   //this is an array of pointers to blocks
	int blockArrSize;
}BlockArray;

typedef struct{
	SDL_Renderer* renderer;
	BlockArray blocksArr;
	SDL_Rect rect;
} Workspace;


void createBlock(Workspace* workspace, int pos_x, int pos_y, int width, int height);
void deleteBlock(Workspace* workspace, int mouseX, int mouseY);
void blockArrayInit(BlockArray* blockArr, int initialSize);
void freeBlockArray(BlockArray* blockArr);


void eventHandler(int* gameLoop, SDL_Event* event, Workspace* workspace);


void colorToStruct(SDL_Color* color, Color* colorS);


void renderNext(Workspace* workspace);