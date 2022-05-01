#ifndef CHARACTER__H
#define CHARACTER__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"

const int SpaceShipW = 80;
const int SpaceShipH = 100;
const int SpaceShipX = 400;
const int SpaceShipY = 600;

struct Character
{
    int x = SpaceShipX;
    int y = SpaceShipY;
    int w = SpaceShipW;
    int h = SpaceShipH;

    bool CharacterShield = false;

    SDL_Rect CharacterRect = {x, y, w, h};

    SDL_Surface* CSurface;
    SDL_Texture* CTexture;

    void draw(SDL_Renderer* renderer)
    {
//        if (CharacterShield == true)
//        {
//            CSurface = IMG_Load("SpaceShipWithShield.png");
//        }
//        else{
//        CSurface = IMG_Load( "BattleShip.png");}
//        if( CSurface == NULL )
//        {
//            printf( "Unable to load image %s! SDL_image Error: \n", IMG_GetError() );
//        }
//        else
//        {
//            CTexture = SDL_CreateTextureFromSurface( renderer, CSurface );
//            if( CTexture == NULL )
//            {
//                printf( "Unable to create texture from %s! SDL Error: \n", SDL_GetError() );
//            }
//
//            //Get rid of old loaded surface
//            SDL_FreeSurface( CSurface );
//        }
//        SDL_RenderCopy(renderer, CTexture, NULL, &CharacterRect);

        if (CharacterShield == true)
        {
            CTexture = loadTexture("UET_Face_Mask.png", renderer);
        }
        else
        {
//            CTexture = loadTexture("BattleShip.png", renderer);
            CTexture = loadTexture("UET2.png", renderer);
        }
        SDL_RenderCopy(renderer, CTexture, NULL, &CharacterRect);
    }

    void moveLeft()
    {
        x -= 30;
        CharacterRect.x -= 30;
    }

    void moveRight()
    {
        x += 30;
        CharacterRect.x += 30;
    }

    void moveUp()
    {
        y -= 30;
        CharacterRect.y -= 30;
    }

    void moveDown()
    {
        y += 30;
        CharacterRect.y += 30;
    }
};

#endif // CHARACTER__H
