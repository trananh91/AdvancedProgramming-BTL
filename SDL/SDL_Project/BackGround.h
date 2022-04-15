#ifndef BACKGROUND__H
#define BACKGROUND__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"

struct BackGround
{
    SDL_Renderer* renderer;

//    BackGround(SDL_Renderer* _renderer)
//    {
//        if (_renderer == nullptr)
//        {
//            cerr << "error renderer background";
//            exit(1);
//        }
//        _renderer = renderer;
//    }

    SDL_Texture* background = loadTexture("universe.jpg", renderer);

    void Load(SDL_Renderer* renderer)
    {
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    void Destroy()
    {
        SDL_DestroyTexture (background);
        background = NULL;
    }
};

#endif // BACKGROUND__H
