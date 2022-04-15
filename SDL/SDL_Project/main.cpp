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

//    const char* Timing[] = {"3", "2", "1", "0"};
//    const char* TimeCount;

using namespace std;

const Uint32 FPS = 800;
const Uint32 frameDelay = 1000 / FPS;

int main(int argc, char* argv[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    initSDL(window, renderer);

    // Font
    TTF_Init();
    TTF_Font* font = TTF_OpenFont("digital-7.ttf", 100);

    SDL_Rect Background = {100, 100, SCREEN_WIDTH/2, SCREEN_HEIGHT/2 };
    SDL_Texture* background = loadTexture("universe1.jpg", renderer);

//
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    SDL_RenderClear(renderer);

//    for (int i = 0; i < 3; i++){

//    SDL_Texture* background = loadTexture("universe1.jpg", renderer);
//    SDL_RenderCopy(renderer, background, &Background, NULL);

//    const char* Timing[] = {"3", "2", "1", "0"};
//    const char* TimeCount;

//
//    for (int i = 0; i < 4; i++){
//
//    SDL_Texture* background = loadTexture("universe1.jpg", renderer);
//    SDL_RenderCopy(renderer, background, &Background, NULL);
//
//    SDL_Color color = {255, 255, 255};
//
//    SDL_Surface* FontSurface = TTF_RenderText_Solid(font, "Welcome to my game", color);
//    SDL_Texture* FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
//
//    SDL_Surface* FontSurface1 = TTF_RenderText_Solid(font, "Game starts in: ", color);
//    SDL_Texture* FontTexture1 = SDL_CreateTextureFromSurface(renderer, FontSurface1);
//
////    const char* TimeCount = "3";
////    const char* Timing[] = {"3", "2", "1", "0"};
////    const char* TimeCount;
////    SDL_Surface* CountSurface = TTF_RenderText_Solid(font, TimeCount, color);
////    SDL_Texture* CountTexture = SDL_CreateTextureFromSurface(renderer, CountSurface);
//
//    int textW = 100;
//    int textH = 100;
//
//    SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
//    SDL_Rect dsRect = {10, 300, textW, textH};
//    SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);
//
//    SDL_QueryTexture(FontTexture1, NULL, NULL, &textW, &textH);
//    SDL_Rect dsRect1 = {80, 500, textW, textH};
//    SDL_RenderCopy(renderer, FontTexture1, NULL, &dsRect1);
//
////    SDL_QueryTexture(CountTexture, NULL, NULL, &textW, &textH);
////    SDL_Rect dsRect2 = {400, 600, textW, textH};
////    SDL_RenderCopy(renderer, CountTexture, NULL, &dsRect2);
//
////    TimeCount = "2";
//
////    for (int i = 0; i < 3; i++)
////    {
////        uint32 StartTimeCount = SDL_GetTicks();
//        TimeCount = Timing[i];
//        SDL_Surface* CountSurface = TTF_RenderText_Solid(font, TimeCount, color);
//        SDL_Texture* CountTexture = SDL_CreateTextureFromSurface(renderer, CountSurface);
//
//        SDL_QueryTexture(CountTexture, NULL, NULL, &textW, &textH);
//        SDL_Rect dsRect2 = {400, 600, textW, textH};
//        SDL_RenderCopy(renderer, CountTexture, NULL, &dsRect2);
//
//        SDL_RenderPresent(renderer);
//        SDL_Delay(1000);
//        SDL_RenderClear(renderer);
//    }

//    SDL_RenderPresent(renderer);

//    SDL_Delay(5000);

//    SDL_Event e1;
//    while (SDL_PollEvent(&e1))
//    {
//        if (e1.type == SDL_KEYDOWN)
//        {
//            if (e1.key.keysym.sym == SDLK_SPACE)
//            {
//                SDL_Delay(3000);
//            }
//        }
//    }

// Ban dau dung cai nay
//    SDL_Rect Background;
//    Background.x = 100;
//    Background.y = 100;
//    Background.w = SCREEN_WIDTH/2;
//    Background.h = SCREEN_HEIGHT/2;
//
//    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//    SDL_RenderClear(renderer);
//
//    SDL_Texture* background = loadTexture("universe.jpg", renderer);
//    SDL_RenderCopy(renderer, background, &Background, NULL);

//    SDL_RenderPresent(renderer);

//    int counter = 0;
    srand(time(nullptr));
//    SDL_Event e;

    Game game(renderer);
    game.CountDown(Background, font, background);
//    game.checkPos();
//    cout << game.box[0][0].rect.x << " " << game.box[0][0].rect.y << endl;
//    cout << game.SpaceShip.rect.x << " " << game.SpaceShip.rect.y << endl;

//    cout << "Done!" << endl;

//    game.TimeGameStart = SDL_GetTicks();
//    cout << game.TimeGameStart << endl;

//    while (!game.isOver())
    int counter = 0;
    while (true)
    {
//        game.checkBoxDone();

//        cout << game.SpaceShip.x << " " << game.SpaceShip.y << endl;
//        if (game.isRunning() == false)
//        {
//            cout << "Game Over!";
//            return 0;
//        }
//            cout << counter << endl;
//        int pos = counter%3;
        Uint32 TimeStart = SDL_GetTicks();
//        SDL_RenderClear(renderer);
//        Uint32 TimePassed  = SDL_GetTicks();
//        cout << TimePassed << endl;
//        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//        SDL_RenderClear(renderer);
//        SDL_Texture* background = loadTexture("background.jpg", renderer);
//        SDL_RenderCopy(renderer, background, NULL, NULL);

        SDL_Texture* background = loadTexture("universe.jpg", renderer);
        SDL_RenderCopy(renderer, background, &Background, NULL);
//        cout << "Background" << " " << counter << endl;

//        SDL_RenderCopy(renderer, background, &backgrounds[pos], NULL);
//        counter++;

//        game.draw();
//        game.start(0);
//        game.updateBoxes(0);

        game.updateBox();
//        cout << "Updating" << " " << counter << endl;
//        game.checkBoxDone();
//        game.start();

//        if (SDL_WaitEvent(&e) == 0) {game.updateBox(); continue;}
//        if (e.type == SDL_QUIT) break;
//        else {

        SDL_Event e;
        if (SDL_PollEvent(&e) != 0){
        if (e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
//                case SDLK_ESCAPE: break;
                case SDLK_RIGHT:
                    game.updateRight();
//                    break;
                    continue;
                case SDLK_LEFT:
                    game.updateLeft();
//                    break;
                    continue;
                case SDLK_UP:
                    game.SpaceShip.y -= 30;
//                    break;
                    continue;
                case SDLK_DOWN:
                    game.SpaceShip.y += 30;
//                    break;
                    continue;
                default:
                    game.updateBox();
//////                    break;
                    continue;
            }
        }
    }
//        SDL_Delay(2000);
        counter++;
//        cout << counter << endl;
        game.draw();
//        cout << "Drawing" << " " << counter << endl;
        SDL_RenderPresent(renderer);
//        cout << "Presenting" << " " << counter << endl;
        SDL_RenderClear(renderer);
//        if (game.checkCollision())
//        {
//            return 0;
//        }
        Uint32 end = SDL_GetTicks() - TimeStart;
        if (frameDelay > end)
        {
            SDL_Delay(frameDelay - end);
        }
        if (game.checkCollision())
        {
//                game.updateBox();
//                game.draw();
                game.Over(font);
//                SDL_Texture* EndBackground = loadTexture("Boom1.png", renderer);
//                SDL_RenderCopy(renderer, EndBackground, NULL, NULL);
//
//                SDL_Color color = {0, 0, 255};
//
//                SDL_Surface* FontOverSurface = TTF_RenderText_Solid(font, "Collided! Game Over!", color);
//                SDL_Texture* FontOverTexture = SDL_CreateTextureFromSurface(renderer, FontOverSurface);
//
//                int textW = 500;
//                int textH = 500;
//                SDL_QueryTexture(FontOverTexture, NULL, NULL, &textW, &textH);
//                SDL_Rect dsRect = {0, 400, textW, textH};
//                SDL_RenderCopy(renderer, FontOverTexture, NULL, &dsRect);
//                SDL_RenderPresent(renderer);
//
//                SDL_Delay(6000);
                return 0;
//            SDL_Delay(2000);
//            break;
        }
//        SDL_Delay(50);

//        if (game.EndPhase1())
//        {
//            break;
//        }
    }



//    SDL_HasIntersection()


//   SDL_Event e;
//    while (true) {
//        if ( SDL_PollEvent(&e) == 0)  SDL_Delay(100);
//        else if (e.type == SDL_QUIT) break;
//        else if (e.type == SDL_KEYDOWN){
////            cerr << "_" << SDL_GetKeyName(e.key.keysym.sym) << "_" << endl;
//            switch(e.key.keysym.sym)
//            {
//                case SDLK_UP: y -= step; break;
//                case SDLK_DOWN: y += step; break;
//                case SDLK_RIGHT: x += step; break;
//                case SDLK_LEFT: x -= step; break;
//            }
//            draw(renderer, x, y);
//        }
//    }

    SDL_DestroyTexture (background);
    background = NULL;

//    SDL_Texture* EndBackground = loadTexture("universe1.jpg", renderer);
//    SDL_RenderCopy(renderer, EndBackground, &Background, NULL);
//    SDL_RenderPresent(renderer);
//    SDL_Delay(6000);


//    SDL_DestroyTexture(FontTexture);
//    SDL_FreeSurface(FontSurface);
//    TTF_CloseFont(font);
//    TTF_Quit();

    quitSDL(window, renderer);
    return 0;
}



