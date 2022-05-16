#ifndef BULLET__H
#define BULLET__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"

struct Bullet
{
    int x;
    int y;

    bool Tdrawing = false;
    bool AbleToShoot = false;
    bool hit = false;

    SDL_Texture* Btexture;

    SDL_Rect WRect;

    void Bdraw(SDL_Renderer* renderer)
    {
        Btexture = loadTexture("NuocSatKhuan.png", renderer);
        if (Tdrawing == true && hit == false)
        {
            SDL_RenderCopy(renderer, Btexture, NULL, &WRect);
        }
    }

    void updateBullet()
    {
        y -= 20;
        WRect.y -= 20;
        if (y <= 0)
        {
            Tdrawing = false;
        }
    }
};

#endif // BULLET__H
