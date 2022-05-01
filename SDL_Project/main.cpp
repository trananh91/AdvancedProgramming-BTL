#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Box.h"
#include "game.h"
#include "Character.h"
#include "BackGround.h"
#include <stdio.h>
#include <SDL_ttf.h>


using namespace std;

const Uint32 FPS = 10;
const Uint32 frameDelay = 1000 / FPS;

int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    initSDL(window, renderer);

    SDL_Texture* background;

    // Font
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("digital-7.ttf", 100);

    SDL_Rect Background = {100, 100, SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
    background = loadTexture("universe1.jpg", renderer);

    srand(time(nullptr));

    Game game(renderer);
    game.CountDown(Background, font, background);
    game.LoadBoxes();
//    background = loadTexture("universe.jpg", renderer);
    background = loadTexture("Road.png", renderer);

    int counter = 0;
//    while(!game.Over(font))
    while (true)
    {
        game.checkBoxDes();

        Uint32 TimeStart = SDL_GetTicks();
        game.loadBackGround(background, renderer);

        SDL_RenderCopy(renderer, background, NULL, NULL);

        game.updateBox();

        SDL_Event e;
        if (SDL_PollEvent(&e) != 0){
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
//                case SDLK_ESCAPE: break;
                case SDLK_RIGHT:
                    game.updateRight();
                    break;
                    continue;
                case SDLK_LEFT:
                    game.updateLeft();
                    break;
                    continue;
                case SDLK_UP:
                    game.updateUp();
                    break;
                    continue;
                case SDLK_DOWN:
                    game.updateDown();
                    break;
                    continue;
                default:
                    game.updateBox();

                    continue;
            }
        }
    }
        counter++;
//        game.draw();
        game.GameTestDraw();

        SDL_RenderPresent(renderer);

        SDL_RenderClear(renderer);
        Uint32 end = SDL_GetTicks() - TimeStart;
        if (frameDelay > end)
        {
            SDL_Delay(frameDelay - end);
        }
//        if (game.checkCollision1() || Score == NumberOfBoxes)
//        {
//            game.Over1(font);
//            break;
//        }

        if (game.Over1(font, background))
        {
            break;
        }
    }

//    SDL_RenderClear(renderer);
//    game.loadBackGround(background, renderer);
//    game.OverWin();
//    game.SpaceShip.draw(renderer);
//    SDL_RenderPresent(renderer);

    SDL_Delay(6000);

    SDL_DestroyTexture (background);
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}



