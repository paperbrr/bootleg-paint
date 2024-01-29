#pragma once
#include <SDL.h>

extern SDL_Color brushColor;

typedef struct{
    SDL_Rect sourceRect;
    SDL_Color color;
    void (*actionFunc) ();
} Button;

typedef struct{
    int length;
    int arrDataSize;
    Button** buttons;
} ButtonsArray;

typedef struct{
    SDL_Rect sourceRect;
    SDL_Color color;
} Frame;

typedef struct{
    int length;
    int arrDataSize;
    Frame** frames;
} FramesArray;

typedef struct{
    SDL_Rect sourceRect;
    SDL_Texture* blockTexture;
	SDL_Color blockColor;
} Block;

typedef struct{
	int blockCount;
	Block** blocks;   //this is an array of pointers to blocks
	int blockArrSize;
}BlockArray;

typedef struct{
	SDL_Renderer* renderer;
	BlockArray blocksArr;
	ButtonsArray buttonsArr;
    FramesArray framesArr;
} Workspace;

void createBlock(Workspace* workspace, int pos_x, int pos_y, int width, int height, SDL_Color color);
void deleteBlock(Workspace* workspace, int mouseX, int mouseY);
void blockArrayInit(BlockArray* blockArr, int initialSize);
void freeBlockArray(BlockArray* blockArr);


void eventHandler(int* gameLoop, SDL_Event* event, Workspace* workspace);


void setRenderColor(SDL_Color color, SDL_Renderer* renderer);


void renderNext(Workspace* workspace);

void buttonsArr_init(ButtonsArray* buttonArr, int initialSize);
void createButton(ButtonsArray* buttonArr, int x, int y, int h, int w, void (*actionPtr) (), SDL_Color color);
void renderButtons(ButtonsArray* buttonArr, SDL_Renderer* renderer);
void buttonClickHandler(SDL_Event* event ,ButtonsArray* buttonArr);
void freeButtonArray(ButtonsArray* buttonArr);


void frameArr_init(FramesArray* framesArr, int initialSize);
void createFrame(FramesArray* framesArr, int x, int y, int w, int h, SDL_Color frameColor);
void renderFrames(FramesArray* framesArr, SDL_Renderer* renderer);
void freeFramesArray(FramesArray* framesArr);


void createAllButtons(ButtonsArray* buttonsArr);