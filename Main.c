#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "Decs.h"


int main(int argv, char* args[]){

	SDL_Window* window;
	SDL_Renderer* renderer;
	//SDL_Surface* oikawaSurface;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("BOOTLEG PAINT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 480, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Workspace workspace;

	workspace.renderer = renderer;
	blockArrayInit(&workspace.blocksArr, 1);

	int gameLoop = 1;
	SDL_Event event;

	while (gameLoop) {
		while (SDL_PollEvent(&event)!=0) {
			eventHandler(&gameLoop, &event, &workspace);
		}

		renderNext(&workspace);
		SDL_Delay(100);
	}
	
	//SDL_DestroyTexture(workspace.oikawaTexture);
	//SDL_DestroyTexture(workspace.block1.blockTexture);
	freeBlockArray(&workspace.blocksArr);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();

	return 0;
}