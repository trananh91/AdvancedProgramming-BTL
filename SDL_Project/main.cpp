#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"
#include "game.h"
#include "Character.h"
#include "Bullet.h"
#include <stdio.h>
#include <SDL_ttf.h>


using namespace std;

const Uint32 FPS = 10;
const Uint32 frameDelay = 1000 / FPS;

int main(int argc, char* argv[])
{
    // Init SDL
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    initSDL(window, renderer);

    // Font
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("waltograph42.ttf", 90);

    //Background
    SDL_Texture* background = loadTexture("School.jpg", renderer);

    // srand for random
    srand(time(nullptr));

    Game game(renderer);
    game.CountDown(font, background);
    game.LoadBoxes();

    // Change background
    background = loadTexture("Road.png", renderer);

    while (!game.Over(background))
    {
        Uint32 TimeStart = SDL_GetTicks();

        // Load background
        game.loadBackGround(background, renderer);

        // Draw characters
        game.GameDraw();

        // Update Virus and Bullet
        game.Update();

        // Event for keyboard
        SDL_Event e;
        game.handleEvent(e);

        // Counting % to win and Score
        game.GameCounting(font);
        game.checkScoreAdded();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        Uint32 end = SDL_GetTicks() - TimeStart;
        if (frameDelay > end)
        {
            SDL_Delay(frameDelay - end);
        }
    }
    SDL_Delay(4000);

    SDL_DestroyTexture (background);
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}



