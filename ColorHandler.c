#include <stdio.h>
#include "Decs.h"
#include <SDL.h>

void colorToStruct(SDL_Color* color, Color* colorS) {
    colorS->r = color->r;
    colorS->g = color->g;
    colorS->b = color->b;
    colorS->a = color->a;
}