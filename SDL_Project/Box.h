#ifndef BOX__H
#define BOX__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Para.h"

using namespace std;

const int BOX_SIZE = 60;

struct Box
{
    int x;
    int y;
    int w = BOX_SIZE;
    int h = BOX_SIZE;

    bool shield = false;
    bool done = false;
    bool drawing = false;
    bool collided = false;

//    SDL_Surface* surface;
    SDL_Texture* BoxText;

    SDL_Rect rect;

    void checkDestroy()
    {
        if (y >= SCREEN_HEIGHT && done == false)
        {
            Score++;
            done = true;
//            SDL_DestroyTexture(BoxText);
            cout << "Destroy!" << " " << Score << endl;
            return;
        }
    }

    void moving(int& yStep)
    {
        if (Score <= 10)
            yStep = 8;
        else if (Score > 10 && Score <= 25)
            yStep = 12;
        else if (Score > 25 && Score <= 45)
            yStep = 16;
        else if (Score > 45 && Score <= NumberOfBoxes)
            yStep = 25;
        y += yStep;
        rect.y += yStep;
        if (y >= 0 && collided == false)
        {
            drawing = true;
        }
    }

//    void draw2(SDL_Renderer* renderer)
//    {
//        SDL_RenderCopy(renderer, texture, NULL, &rect);
//    }

    void LoadBox(SDL_Texture* ATexture, SDL_Texture* STexture)
    {
        if (shield == false)
        {
            BoxText = ATexture;
        }
        else{
            BoxText = STexture;
        }
    }

    void TestDraw(SDL_Renderer* renderer)
    {
        if (drawing == true)
        {
            SDL_RenderCopy(renderer, BoxText, NULL, &rect);
        }
    }
};

#endif // BOX__H
