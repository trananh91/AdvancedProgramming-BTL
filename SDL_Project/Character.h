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
const int SpaceShipX = 630;
const int SpaceShipY = 570;

struct Character
{
    int x = SpaceShipX;
    int y = SpaceShipY;
    int w = SpaceShipW;
    int h = SpaceShipH;

    bool CharacterShield = false;
    bool atEdge = false;

    SDL_Rect CharacterRect = {x, y, w, h};

    SDL_Surface* CSurface;
    SDL_Texture* CTexture;

    void draw(SDL_Renderer* renderer)
    {

        if (CharacterShield == true)
        {
            CTexture = loadTexture("UET_SC_Mask.png", renderer);
        }
        else
        {
            CTexture = loadTexture("UET_SC1.png", renderer);
        }

        if (x < LeftEdge || x > RightEdge)
        {
            if (x < LeftEdge)
            {
                x = LeftEdge;
                CharacterRect.x = LeftEdge;
            }
            else
            {
                x = RightEdge;
                CharacterRect.x = RightEdge;
            }
        }

        if (y < UpEdge || y > DownEdge)
        {
            if (y < UpEdge)
            {
                y = UpEdge;
                CharacterRect.y = UpEdge;
            }
            else
            {
                y = DownEdge;
                CharacterRect.y = DownEdge;
            }
        }

        SDL_RenderCopy(renderer, CTexture, NULL, &CharacterRect);
    }

    void WinDraw(SDL_Renderer* renderer)
    {
        SDL_Rect WinRect = {600, 500, 300, 300};
        CTexture = loadTexture("UETWin1.png", renderer);
        SDL_RenderCopy(renderer, CTexture, NULL, &WinRect);
    }

    void moveLeft()
    {
        if (atEdge == false)
        {
            x -= 30;
            CharacterRect.x -= 30;
        }
    }

    void moveRight()
    {
        if (atEdge == false)
        {
            x += 30;
            CharacterRect.x += 30;
        }
    }

    void moveUp()
    {
        if (atEdge == false)
        {
            y -= 30;
            CharacterRect.y -= 30;
        }
    }

    void moveDown()
    {
        if (atEdge == false)
        {
            y += 30;
            CharacterRect.y += 30;
        }
    }
};

#endif // CHARACTER__H
