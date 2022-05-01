#ifndef GAME__H
#define GAME__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Character.h"
#include "Box.h"
#include "BackGround.h"
#include <SDL_ttf.h>

//step cu = 15
int STEP = 0;
//const int NumberOfBoxes = 54;
//const int BoxesPerRow = 4;
const int Row = NumberOfBoxes/BoxesPerRow;
const char* Timing[] = {"3", "2", "1", "0"};
const char* TimeCount;

struct Game
{
//    int DISTANCE = (SCREEN_WIDTH-400)/BoxesPerRow;
    bool winning = false;
    int DISTANCE = (SCREEN_WIDTH)/BoxesPerRow;

    SDL_Renderer* renderer;

    //Co the xoa Surf di
    SDL_Surface* MainSurf;

    SDL_Texture* AsteroidTexture;
    SDL_Texture* ShieldTexture;

    SDL_Texture* MainText;

    Box box[Row+1][BoxesPerRow];
    int checkBox[Row+1][BoxesPerRow];

// Luc dau dung cai nay
    Character SpaceShip;

    Treasure Gtreasure;

//    Box boxes[Row+1][BoxesPerRow];

    Game(SDL_Renderer* _renderer)
    {
        if (_renderer == nullptr)
        {
            cerr << "error renderer";
            exit(1);
        }
        renderer = _renderer;

        AsteroidTexture = loadTexture("Asteroid.png", renderer);
        ShieldTexture = loadTexture("shield3.png", renderer);

////1
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                checkBox[i][j] = 0;
            }
        }

        int xs = rand()%(Row-8);
        int ys = rand()%(BoxesPerRow-3)+2;
        box[xs][ys].shield = true;
        box[xs][ys].w = 80;
        box[xs][ys].h = 80;

////2
        int countBox = 0;
        while (true)
        {
            for (int i = 0; i <= Row; i++)
            {
                for (int j = 0; j < BoxesPerRow; j++)
                {
                    checkBox[i][j] = 1;
                    countBox++;
                    if (countBox == NumberOfBoxes)
                    {
                        break;
                    }
                }
                if (countBox == NumberOfBoxes)
                {
                    break;
                }
            }
            break;
        }

////3
        int yPos;
        int xPos;
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
//                    xPos = ((rand()%(DISTANCE-BOX_SIZE))+BOX_SIZE/2) + j*DISTANCE + 200;
                    xPos = ((rand()%(DISTANCE-BOX_SIZE))+BOX_SIZE/2) + j*DISTANCE;
                    box[i][j].x = xPos;

//                    if (i == 0)
//                    {
//                        yPos = -(rand()%200) - j*50;
//                    }
//                    else{
//                    yPos = -(rand()%(i*400))-j*100;}
                    yPos = -(rand()%300) - i*500 - j*80;
                    box[i][j].y = yPos;

                    cout << box[i][j].y << endl;

                    box[i][j].rect = {xPos, yPos, BOX_SIZE, BOX_SIZE};
//                    cout << box[i][j].rect.x << endl;
                }
            }
        }

//        SpaceShip.x = 400;
//        SpaceShip.y = 600;
//        SpaceShip.w = 80 ;
//        SpaceShip.h = 100 ;

        SpaceShip.CharacterRect = {SpaceShip.x, SpaceShip.y, SpaceShip.w, SpaceShip.h};
    }

    void CountDown(const SDL_Rect &Background, TTF_Font* font, SDL_Texture* background)
    {
        SDL_Surface* FontSurface;
        SDL_Texture* FontTexture;
        SDL_Color color = { 255, 255, 255 };
        SDL_Rect dsRect;

        int textW = 100;
        int textH = 100;

        for (int i = 0; i < 4; i++)
        {
        SDL_RenderCopy(renderer, background, &Background, NULL);

        FontSurface = TTF_RenderText_Solid(font, "Welcome to my game", color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {10, 300, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        FontSurface = TTF_RenderText_Solid(font, "Game starts in: ", color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {80, 500, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        TimeCount = Timing[i];
        FontSurface = TTF_RenderText_Solid(font, TimeCount, color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {400, 600, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        }
        SDL_FreeSurface(FontSurface);
        SDL_DestroyTexture(FontTexture);
    }

    void updateBox()
    {
        //Array
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].moving(STEP);
                }
            }
        }

//        //Vector
//        for (int i = Boxes.begin(); i <= Boxes.end(); i++)
//        {
//            Boxes[i].moving(STEP);
//        }

    }

    bool checkCollision()
    {
        SDL_Rect MainRect;
        SDL_Rect ThreatRect[Row+1][BoxesPerRow];

        MainRect = {SpaceShip.x, SpaceShip.y, SpaceShip.w, SpaceShip.h};

        ////4
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    ThreatRect[i][j] = {box[i][j].x, box[i][j].y, box[i][j].w, box[i][j].h};
                }
                else {
                    //Dung vector
                }
            }
        }

////5
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (SDL_HasIntersection(&ThreatRect[i][j], &MainRect) == true)
                {
                    box[i][j].collided = true;
                    if (box[i][j].shield == true)
                    {
                        SpaceShip.CharacterShield = true;
                    }
                    else{
                    cout << "Collided" << endl;
                    cout << ThreatRect[i][j].x << ' ' << ThreatRect[i][j].y << ' ' << ThreatRect[i][j].w << ' ' << ThreatRect[i][j].h << endl;
                    cout << box[i][j].x << ' ' << box[i][j].y << ' ' << box[i][j].w << ' ' << box[i][j].h << endl;
                    cout << MainRect.x << ' ' << MainRect.y << ' ' << MainRect.w << ' ' << MainRect.h << endl;
                    cout << SpaceShip.x << ' ' << SpaceShip.y << ' ' << SpaceShip.w << ' ' << SpaceShip.h << endl;
                    return true;
                    }
                }
            }
        }
    }


    bool checkCollision1()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
//                if (SDL_HasIntersection(&box[i][j].rect , &SpaceShip.CharacterRect) == true)
//                {
////                    box[i][j].collided = true;
//                    if (SpaceShip.CharacterShield == true && box[i][j].shield == false)
//                    {
//                        SpaceShip.CharacterShield = false;
//                    }
//                    else if (box[i][j].shield == true && SpaceShip.CharacterShield == false)
//                    {
//                        SpaceShip.CharacterShield = true;
//                        box[i][j].collided = true;
//                        box[i][j].drawing = false;
//                    }
//                    else{
//                    cout << "Collided" << endl;
//                    cout << SpaceShip.x << ' ' << SpaceShip.y << ' ' << SpaceShip.w << ' ' << SpaceShip.h << endl;
//                    cout << box[i][j].rect.x << " " << box[i][j].rect.y << " " << box[i][j].rect.w << " " << box[i][j].rect.h << endl;
//                    return true;
//                    }
//                }

                if (SDL_HasIntersection(&box[i][j].rect , &SpaceShip.CharacterRect) == true)
                {
                    if (SpaceShip.CharacterShield ==  false && box[i][j].shield == false && box[i][j].collided == false)
                    {
                        cout << "Collided" << endl;
                        return true;
                    }
                    else if (SpaceShip.CharacterShield == false && box[i][j].shield == true)
                    {
                        SpaceShip.CharacterShield = true;
                        box[i][j].drawing = false;
                        box[i][j].collided = true;
                        return false;
                    }
                    else if (SpaceShip.CharacterShield == true && box[i][j].shield == false)
                    {
                        SpaceShip.CharacterShield = false;
                        box[i][j].collided = true;
                        box[i][j].drawing = false;
                        return false;
                    }
                }
            }
        }
    }

    void updateLeft()
    {
        SpaceShip.moveLeft();
    }

    void updateRight()
    {
        SpaceShip.moveRight();
    }

    void updateUp()
    {
        SpaceShip.moveUp();
    }

    void updateDown()
    {
        SpaceShip.moveDown();
    }

    bool Over(TTF_Font* font)
    {
        if (checkCollision1())
        {
            SDL_Texture* EndBackground = loadTexture("Boom1.png", renderer);
            SDL_RenderCopy(renderer, EndBackground, NULL, NULL);

            SDL_Color color = {0, 0, 255};

            SDL_Surface* FontOverSurface = TTF_RenderText_Solid(font, "Collided! Game Over!", color);
            SDL_Texture* FontOverTexture = SDL_CreateTextureFromSurface(renderer, FontOverSurface);

            int textW = 500;
            int textH = 500;
            SDL_QueryTexture(FontOverTexture, NULL, NULL, &textW, &textH);
            SDL_Rect dsRect = {0, 400, textW, textH};
            SDL_RenderCopy(renderer, FontOverTexture, NULL, &dsRect);
            SDL_RenderPresent(renderer);

            SDL_Delay(6000);
            return true;
        }
        else if (Score == NumberOfBoxes)
        {
            Gtreasure.Tdrawing = true;
            winning = true;
            return true;
        }
        return false;
    }

    void Over1(TTF_Font* font)
    {
        if (checkCollision1())
        {
            SDL_Texture* EndBackground = loadTexture("Boom1.png", renderer);
            SDL_RenderCopy(renderer, EndBackground, NULL, NULL);

            SDL_Color color = {0, 0, 255};

            SDL_Surface* FontOverSurface = TTF_RenderText_Solid(font, "Collided! Game Over!", color);
            SDL_Texture* FontOverTexture = SDL_CreateTextureFromSurface(renderer, FontOverSurface);

            int textW = 500;
            int textH = 500;
            SDL_QueryTexture(FontOverTexture, NULL, NULL, &textW, &textH);
            SDL_Rect dsRect = {0, 400, textW, textH};
            SDL_RenderCopy(renderer, FontOverTexture, NULL, &dsRect);
            SDL_RenderPresent(renderer);

            SDL_Delay(6000);
            return;
        }
        else if (Score == NumberOfBoxes)
        {
            Gtreasure.Tdrawing = true;
            winning = true;
            return;
        }
        return;
    }

    void checkBoxDes()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].checkDestroy();
                }
            }
        }
    }

    void LoadBoxes()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].LoadBox(AsteroidTexture, ShieldTexture);
                }
            }
        }
    }

    void GameTestDraw()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].TestDraw(renderer);
                }
            }
        }

        SpaceShip.draw(renderer);
    }

    void loadBackGround(SDL_Texture* BGtexture, SDL_Renderer* BGrenderer)
    {
        SDL_RenderCopy(BGrenderer, BGtexture, NULL, NULL);
    }

    void OverWin()
    {
        if (winning == true)
        {
            Gtreasure.tdraw(renderer);
        }
    }
};

#endif // GAME__H
