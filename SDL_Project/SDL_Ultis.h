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

#endif // SDL_ULTIS__H
