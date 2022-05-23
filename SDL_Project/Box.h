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
    bool doneAddingScore = false;
    bool drawing = false;
    bool collided = false;
    bool sanitizer = false;
    bool variable = false;
    bool getHit1 = false;
    bool getHit2 = false;

    SDL_Texture* BoxText;

    SDL_Rect rect = {x, y, BOX_SIZE, BOX_SIZE};

    void moving(int& yStep)
    {
        if (Score <= 15 && shield == false)
            yStep = 8;
        else if (Score > 15 && Score <= 30 && shield == false)
            yStep = 12;
        else if (Score > 30 && Score <= 65 && shield == false)
            yStep = 15;
        else if (Score > 65 && Score <= NumberOfViruses && shield == false)
            yStep = 18;

        y += yStep;
        rect.y += yStep;

        if (y >= -10 && collided == false)
        {
            drawing = true;
        }
    }

    void LoadBox(SDL_Texture* ATexture, SDL_Texture* STexture, SDL_Texture* HTexture, SDL_Texture* VTexture)
    {
        if (shield == false && sanitizer == false && variable == false)
        {
            BoxText = ATexture;
        }
        else if (shield == true)
        {
            BoxText = STexture;
        }
        else if (sanitizer == true)
        {
            BoxText = HTexture;
        }
        else if (variable == true)
        {
            BoxText = VTexture;
        }
    }

    void TestDraw(SDL_Renderer* renderer)
    {
        if (drawing == true)
        {
            SDL_RenderCopy(renderer, BoxText, NULL, &rect);
        }
    }

    void AddScore()
    {
        if (y >= SCREEN_HEIGHT && doneAddingScore == false)
        {
            Score++;
            doneAddingScore = true;
            return;
        }
    }

};

#endif // BOX__H
