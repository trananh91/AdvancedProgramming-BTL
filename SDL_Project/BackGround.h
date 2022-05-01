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
    SDL_Rect WRect = {160, 0, 430, 400};

    void tdraw(SDL_Renderer* renderer)
    {
        cout << "Yes" << endl;
        Wtexture = loadTexture("VNU.jpg", renderer);
        SDL_RenderCopy(renderer, Wtexture, NULL, &WRect);
    }
};

#endif // BACKGROUND__H
