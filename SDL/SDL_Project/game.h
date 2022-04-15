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
#include <SDL_ttf.h>

const int GameOver = 200;
const int STEP = 10;
const int NumberOfBoxes = 18;
const int BoxesPerRow = 5;
const int Row = NumberOfBoxes/BoxesPerRow;
const char* Timing[] = {"3", "2", "1", "0"};
const char* TimeCount;

struct Game
{
//    struct box;
//    Uint32 TimeGameStart;
    int DISTANCE = SCREEN_WIDTH/BoxesPerRow;

    SDL_Renderer* renderer;

//    int Row = NumberOfBoxes/BoxesPerRow;


//    vector<Box> boxes;

//    SDL_Rect MainRect;
//    SDL_Rect ThreatRect[Row+1][BoxesPerRow];

    Box box[Row+1][BoxesPerRow];
    int checkBox[Row+1][BoxesPerRow];


    //Luc dau dung cai nay
//    SDL_Rect MainRect;
//    SDL_Rect ThreatRect[Row+1][BoxesPerRow];

//    for (int i = 0; i <= Row; i++)
//    {
//        for (int j = 0; j < BoxesPerRow; j++)
//        {
//            box[i][j].rect = {(rand()%(DISTANCE-BOX_SIZE)+BOX_SIZE/2) + j*DISTANCE, -(rand()%200)-i*400 - j*200, 100, 100};
//        }
//    }
//    Box box[NumberOfBoxes];

//    int BoxPos[SCREEN_WIDTH+1] = {0};


// Luc dau dung cai nay
    Character SpaceShip;

//    Box boxes[Row+1][BoxesPerRow];

    Game(SDL_Renderer* _renderer)
    {
        if (_renderer == nullptr)
        {
            cerr << "error renderer";
            exit(1);
        }
        renderer = _renderer;


        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                checkBox[i][j] = 0;
            }
        }

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

//        box1.x = 380;
//        box1.y = 0;

//        for (int i = 0; i < NumberOfBoxes; i++)
//        {
//            box[i].y = -(rand()%500);
////            int xpos = rand()%((SCREEN_WIDTH-(BOX_SIZE/2)+1)+BOX_SIZE/2);
////            if (BoxPos[xpos] == 0) box[i].x = xpos;
////            box[i].TimeToStart = 1000*(rand()%6);
//
////            cout << box[i].TimeToStart << endl;
//            box[i].x = rand()%(DISTANCE-BOX_SIZE)+BOX_SIZE/2 + i*DISTANCE;
////            cout << box[i].x << endl;
//        }

//        int counter = 0;
//        while (true)
//        {

        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                        box[i][j].y = -(rand()%400)-i*300-j*400;
                        box[i][j].x = (rand()%(DISTANCE-BOX_SIZE)+BOX_SIZE/2) + j*DISTANCE;
//                        cout << NumberOfBoxes << " " << counter << endl;
//                        cout << box[i][j].x << " " << box[i][j].y << endl;
                }
            }
        }


//        }

        SpaceShip.x = 400;
        SpaceShip.y = 600;
        SpaceShip.w = 80 ;
        SpaceShip.h = 100 ;

//        MainRect = {SpaceShip.x, SpaceShip.y, SpaceShip.w, SpaceShip.h};
//
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                if (checkBox[i][j] == 1)
//                {
//                    ThreatRect[i][j] = {box[i][j].x, box[i][j].y, box[i][j].w, box[i][j].h};
////                    cout << ThreatRect[i][j]. x << " " << box[i][j].x << endl;
////                    cout << ThreatRect[i][j]. y << " " << box[i][j].y << endl;
////                    cout << ThreatRect[i][j]. w << " " << box[i][j].w << endl;
////                    cout << ThreatRect[i][j]. h << " " << box[i][j].h << endl;
//                }
////                else {
////                    //Dung vector
////                }
//            }
//        }

//        cout << SpaceShip.CharacterRect.x << " " << SpaceShip.CharacterRect.y << " " << SpaceShip.CharacterRect.w << " " << SpaceShip.CharacterRect.h << endl;

        //Luc dau dung cai nay
//        MainRect = {SpaceShip.x, SpaceShip.y, SpaceShip.w, SpaceShip.h};
//
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                if (checkBox[i][j] == 1)
//                {
//                    ThreatRect[i][j] = {box[i][j].x, box[i][j].y, box[i][j].w, box[i][j].h};
//                }
//            }
//        }

//        SDL_Rect Background;
//        Background.x = 100;
//        Background.y = 100;
//        Background.w = SCREEN_WIDTH/2;
//        Background.h = SCREEN_HEIGHT/2;

//        SDL_Texture* background = loadTexture("universe1.jpg", renderer);
//        SDL_RenderCopy(renderer, background, &Background, NULL);

    }

    void CountDown(const SDL_Rect &Background, TTF_Font* font, SDL_Texture* background)
    {
        for (int i = 0; i < 4; i++)
        {
        SDL_RenderCopy(renderer, background, &Background, NULL);

        SDL_Color color = {255, 255, 255};

        SDL_Surface* FontSurface = TTF_RenderText_Solid(font, "Welcome to my game", color);
        SDL_Texture* FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);

        SDL_Surface* FontSurface1 = TTF_RenderText_Solid(font, "Game starts in: ", color);
        SDL_Texture* FontTexture1 = SDL_CreateTextureFromSurface(renderer, FontSurface1);

        int textW = 100;
        int textH = 100;

        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        SDL_Rect dsRect = {10, 300, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        SDL_QueryTexture(FontTexture1, NULL, NULL, &textW, &textH);
        SDL_Rect dsRect1 = {80, 500, textW, textH};
        SDL_RenderCopy(renderer, FontTexture1, NULL, &dsRect1);

        TimeCount = Timing[i];
        SDL_Surface* CountSurface = TTF_RenderText_Solid(font, TimeCount, color);
        SDL_Texture* CountTexture = SDL_CreateTextureFromSurface(renderer, CountSurface);

        SDL_QueryTexture(CountTexture, NULL, NULL, &textW, &textH);
        SDL_Rect dsRect2 = {400, 600, textW, textH};
        SDL_RenderCopy(renderer, CountTexture, NULL, &dsRect2);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        }
    }


//    bool isRunning()
//    {
////        return box[NumberOfBoxes-1].y >= 600;
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                if (SDL_HasIntersection(&box[i][j].rect, &SpaceShip.Mrect))
//                {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }

//    void checkPos()
//    {
////        cout << SpaceShip.x << " " << SpaceShip.y << " " << SpaceShip.w << " " << SpaceShip.h;
////        cout << box[0][0].x << " " << box[0][0].y << " " << box[0][0].w << " " << box[0][0].h;
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                cout << checkBox[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//        cout << MainRect.x << " " << MainRect.y << " " << MainRect.w << " " << MainRect.h << endl;
//        cout << ThreatRect[0][0].x << " " << ThreatRect[0][0].y << " " << ThreatRect[0][0].w << " " << ThreatRect[0][0].h << endl;
//        cout << box[0][0].x << " " << box[0][0].y << " " << box[0][0].w << " " << box[0][0].h << endl;
//
//    }

//    void updateBox()
//    {
//        // box1.moving(STEP);
//
////        for (int i = 0; i < NumberOfBoxes; i++)
////        {
////            box[i].moving(STEP);
////        }
//        int countBox = 0;
//        while (true)
//        {
//            for (int i = 0; i <= Row; i++)
//            {
//                for (int j = 0; j < BoxesPerRow; j++)
//                {
//                    box[i][j].moving(STEP);
//                    countBox++;
//                    if (countBox == NumberOfBoxes)
//                    {
//                        break;
//                    }
//                }
//                if (countBox == NumberOfBoxes)
//                {
//                    break;
//                }
//            }
//            break;
//        }
//    }

    void updateBox()
    {
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

    }

    void updateBox1()
    {
        int countBox = 0;
        while (countBox <= NumberOfBoxes)
        {
            for (int i = 0; i <= Row; i++)
            {
                for (int j = 0; j < BoxesPerRow; j++)
                {
                    box[i][j].moving(STEP);
                    countBox++;
                }
            }
        }
    }

//    void checkBoxDone()
//    {
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                if (checkBox[i][j] == 1 && box[i][j].y >= 300)
//                {
//                    checkBox[i][j]= 0;
////                    SDL_DestroyTexture(box[i][j].NewTexture);
////                    box[i][j].NewTexture = NULL;
//                }
//            }
//        }
//    }

//    void updateBoxes(int i)
//    {
//        while (box[i].y < 600)
//        {
//            box[i].moving(STEP);
//            box[i].draw(renderer);
//        }
//    }

    bool checkCollision()
    {
        SDL_Rect MainRect;
        SDL_Rect ThreatRect[Row+1][BoxesPerRow];

        MainRect = {SpaceShip.x, SpaceShip.y, SpaceShip.w, SpaceShip.h};

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

        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (SDL_HasIntersection(&ThreatRect[i][j], &MainRect) == true)
                {
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

    void updateLeft()
    {
        SpaceShip.moveLeft();
    }

    void updateRight()
    {
        SpaceShip.moveRight();
    }

//    void draw()
//    {
////        for (int i = 0; i < NumberOfBoxes; i++)
////        {
////            box[i].draw(renderer);
////        }
//        int countBox = 0;
//        while (true)
//        {
//            for (int i = 0; i <= Row; i++)
//            {
//                for (int j = 0; j < BoxesPerRow; j++)
//                {
//                    box[i][j].draw(renderer);
//                    countBox++;
//                    if (countBox == NumberOfBoxes)
//                    {
//                        break;
//                    }
//                }
//                if (countBox == NumberOfBoxes)
//                {
//                    break;
//                }
//            }
//            break;
//        }
//
////        box1.draw(renderer);
//        SpaceShip.draw(renderer);
////        SDL_RenderPresent(renderer);
//    }

    void draw()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < BoxesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].draw(renderer);
                }
            }
        }

        SpaceShip.draw(renderer);
    }

    void Over(TTF_Font* font)
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
    }

//    bool EndPhase1()
//    {
//        int counter = 1;
//        for (int i = 0; i <= Row; i++)
//        {
//            for (int j = 0; j < BoxesPerRow; j++)
//            {
//                if (checkBox[i][j] == 1)
//                {
//                    if (box[i][j].y == SCREEN_HEIGHT)
//                    {
//                        counter++;
//                        cout << counter << endl;
//                    }
//                    if (counter == NumberOfBoxes)
//                    {
//                        return true;
//                    }
//                }
//            }
//        }
//    }

};

#endif // GAME__H
