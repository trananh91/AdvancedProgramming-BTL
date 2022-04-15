#ifndef BOX__H
#define BOX__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Para.h"
//#include "game.h"

using namespace std;

const int BOX_SIZE = 60;

struct Box
{
    int x;
    int y;
    int w = BOX_SIZE;
    int h = BOX_SIZE;


//    int xpos;
//    int ypos;
//    SDL_Texture* NewTexture = NULL;
//    Box(int i, int j)
//    {
//        xpos = i;
//        ypos = j;
//        SDL_Rect rect = {{(rand()%(DISTANCE-BOX_SIZE)+BOX_SIZE/2) + ypos*DISTANCE, -(rand()%200)-xpos*400 - ypos*200, 100, 100}}
//    }
//    SDL_Rect rect = {{(rand()%(DISTANCE-BOX_SIZE)+BOX_SIZE/2) + j*DISTANCE, -(rand()%200)-i*400 - j*200, 100, 100}}
//    Uint32 TimeToStart;
//    Uint32 StartNow;

//    SDL_Renderer* renderer;

//    Box (SDL_Renderer* _renderer)
//    {
//        if (_renderer == nullptr)
//        {
//            cerr << "error renderer";
//            exit(1);
//        }
//        _renderer = renderer;
//    }

    void draw(SDL_Renderer* renderer)
    {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;

        SDL_Texture* NewTexture = NULL;
        SDL_Surface* loadedSurface = IMG_Load( "Asteroid.png");
        if( loadedSurface == NULL )
        {
            printf( "Unable to load image %s! SDL_image Error: \n", IMG_GetError());
        }
        else
        {
            NewTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
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
//        SDL_Texture* NewTexture = loadTexture("Asteroid.png", renderer);
//        SDL_RenderCopy(renderer, NewTexture, NULL, &rect);
////        SDL_RenderPresent(renderer);
//    }

    void moving(int yStep)
    {
//        while (y < 300)
//        {
            y += yStep;
//            if (y == SCREEN_HEIGHT)
//            {
//                SDL_DestroyTexture(NewTexture);
//                NewTexture = NULL;
//            }
//        }
    }

//    void checkDone()
//    {
//        if (y == SCREEN_HEIGHT)
//        {
//            SDL_DestroyTexture(NewTexture);
//            NewTexture = NULL;
//            cout << "Done!" << endl;
//        }
//    }

//    void start()
//    {
////        unit32 sTime = SDL_GetTicks();
////        Unit32 StartNow;
//        while (true)
//        {
//            Uint32 sTime = SDL_GetTicks();
//            StartNow = sTime - StartTime;
//        }
////        if (sTime - StartTime == TimeToStart)
////        {
////            moving(yStep);
////        }
//    }

    int GetX() {return x;}
    int Gety() {return y;}

};

#endif // BOX__H
