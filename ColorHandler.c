#include <stdio.h>
#include "Decs.h"
#include <SDL.h>

void setRenderColor(SDL_Color* color, SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);
}