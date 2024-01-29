#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Decs.h"


int main(int argv, char* args[]){

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Surface* oikawaSurface;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("BOOTLEG PAINT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Workspace workspace;

	workspace.renderer = renderer;
	blockArrayInit(&workspace.blocksArr, 1);
	buttonsArr_init(&workspace.buttonsArr, 1);
	frameArr_init(&workspace.framesArr, 1);

	SDL_Color panelColor = {150,150,150,255};
	SDL_Color canvasColor = {240,240,240,255};

	createFrame(&workspace.framesArr, 0, 0, 800, 60, panelColor);
	createFrame(&workspace.framesArr, 0, 60, 800, 700, canvasColor);

	//createAllButtons(&workspace.buttonsArr);

	int gameLoop = 1;
	SDL_Event event;

	while (gameLoop) {
		while (SDL_PollEvent(&event)!=0) {
			eventHandler(&gameLoop, &event, &workspace);
			buttonClickHandler(&event, &workspace.buttonsArr);
		}

		renderNext(&workspace);
		SDL_Delay(100);
	}
	
	//SDL_DestroyTexture(workspace.oikawaTexture);
	//SDL_DestroyTexture(workspace.block1.blockTexture);
	freeBlockArray(&workspace.blocksArr);
	freeButtonArray(&workspace.buttonsArr);
	freeFramesArray(&workspace.framesArr);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}