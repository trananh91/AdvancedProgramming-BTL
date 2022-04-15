#ifndef SDL_ULTIS__H
#define SDL_ULTIS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Para.h"

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(ostream& os,
                 const string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

bool waitUntilKeyPressed();

SDL_Texture* loadTexture (string path, SDL_Renderer* renderer);

//void draw(SDL_Renderer* renderer, int x, int y)
//{
//    SDL_Rect rect;
//    rect.x = x;
//    rect.y = y;
//    rect.w = 30;
//    rect.h = 30;
//    SDL_SetRenderDrawColor (renderer, 0, 0, 255, 255);
//    SDL_RenderFillRect(renderer, &rect);
//    SDL_RenderPresent(renderer);
//}

#endif // SDL_ULTIS__H
