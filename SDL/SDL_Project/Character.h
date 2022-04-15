#ifndef CHARACTER__H
#define CHARACTER__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"

struct Character
{
    int x;
    int y;
    int w;
    int h;

    SDL_Rect CharacterRect;

//    Character(int _x, int _y, int _w, int _h)
//    {
//        x = _x;
//        y = _y;
//        w = _w;
//        h = _h;
//
//        CharacterRect.x = _x;
//        CharacterRect.y = _y;
//        CharacterRect.w = _w;
//        CharacterRect.h = _h;
//    }

//    SDL_Rect Mrect = {400, 500, 100, 100};
//    SDL_Renderer* renderer;

//    void draw(SDL_Renderer* renderer)
//    {
//        SDL_Rect rect;
//        rect.x = x;
//        rect.y = y;
////        rect.w = BOX_SIZE;
////        rect.h = BOX_SIZE;
//
//        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//        SDL_RenderFillRect(renderer, &rect);
//        SDL_RenderPresent(renderer);
//    }

    void draw(SDL_Renderer* renderer)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;

        SDL_Texture* NewTexture = NULL;
        SDL_Surface* loadedSurface = IMG_Load( "SpaceShip1.png");
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: \n", IMG_GetError() );
        }
        else
        {
            NewTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
            if( NewTexture == NULL )
            {
                printf( "Unable to create texture from %s! SDL Error: \n", SDL_GetError() );
            }
            else
            {
                //Get image dimensions
                rect.w = w;
                rect.h = h;
            }

            //Get rid of old loaded surface
            SDL_FreeSurface( loadedSurface );
        }
        SDL_RenderCopy(renderer, NewTexture, NULL, &rect);
//        SDL_RenderPresent(renderer);
    }

//    void draw(SDL_Renderer* renderer)
//    {
//        SDL_Rect rect;
//        rect.x = x;
//        rect.y = y;
//
//        SDL_Texture* NewTexture = loadTexture("SpaceShip1.png", renderer);
//        SDL_RenderCopy(renderer, NewTexture, NULL, &rect);
////        SDL_RenderPresent(renderer);
//    }

    void moveLeft()
    {
        x -= 30;
    }

    void moveRight()
    {
        x += 30;
    }
};

#endif // CHARACTER__H
