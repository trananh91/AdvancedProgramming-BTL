#ifndef BACKGROUND__H
#define BACKGROUND__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"

struct Treasure
{
    bool Tdrawing = false;

    SDL_Texture* Wtexture;
    SDL_Rect WRect = {200, 150, 400, 400};

    void tdraw(SDL_Renderer* renderer)
    {
//        if (Tdrawing == true){
            Wtexture = loadTexture("shield.png", renderer);
            SDL_RenderCopy(renderer, Wtexture, NULL, &WRect);
//            SDL_RenderPresent(renderer);
//        }
    }
};

#endif // BACKGROUND__H
