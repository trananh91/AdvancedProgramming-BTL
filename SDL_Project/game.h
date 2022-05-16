#ifndef GAME__H
#define GAME__H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <ctime>
#include "SDL_Ultis.h"
#include "Para.h"
#include "Character.h"
#include "Box.h"
#include "Bullet.h"
#include <SDL_ttf.h>
#include <SDL_mixer.h>

const int Row = NumberOfViruses/VirusesPerRow;
const char* Timing[] = {"3", "2", "1", "0"};
const char* TimeCount;
const int Mask_Size = 80;

int STEP;

struct Game
{
    // Khoang cach giua cac virus
    int DISTANCE = (RightEdge - LeftEdge)/VirusesPerRow;

    SDL_Renderer* renderer;

    SDL_Texture* VirusTexture;
    SDL_Texture* MaskTexture;
    SDL_Texture* SanitizerTexture;

    SDL_Texture* MainText;

    Box box[Row+1][VirusesPerRow];
    int checkBox[Row+1][VirusesPerRow];

    Character UET_Main;

    Bullet SatKhuan;

    Game(SDL_Renderer* _renderer)
    {
        if (_renderer == nullptr)
        {
            cerr << "error renderer";
            exit(1);
        }
        renderer = _renderer;

        VirusTexture = loadTexture("Virus_Red.png", renderer);
        MaskTexture = loadTexture("Face_Mask.png", renderer);
//        MaskTexture = loadTexture("C:\\ltnc-btl\\SDL_Project\\Character\\Face_Mask.png", renderer);
        SanitizerTexture = loadTexture("Sanitizer.png", renderer);

        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                checkBox[i][j] = 0;
            }
        }

        int xs = (rand()%4)+3;
        int ys = (rand()%1);

        int xs1 = xs+2;
        int ys1 = ys+2;

        int xs2 = xs1+1;
        int ys2 = ys1+1;

        box[xs][ys].shield = true;
        box[xs1][ys1].shield = true;
        box[xs2][ys2].sanitizer = true;

//        box[0][0].sanitizer = true;

        int countBox = 0;
        while (true)
        {
            cout << DISTANCE << endl;
            for (int i = 0; i <= Row; i++)
            {
                for (int j = 0; j < VirusesPerRow; j++)
                {
                    checkBox[i][j] = 1;
                    countBox++;
                    if (countBox == NumberOfViruses)
                    {
                        break;
                    }
                }
                if (countBox == NumberOfViruses)
                {
                    break;
                }
            }
            break;
        }

        int yPos;
        int xPos;
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    xPos = LeftEdge + (rand()%(DISTANCE-BOX_SIZE)) + BOX_SIZE/2 + j*DISTANCE;
                    box[i][j].x = xPos;

                    yPos = -(rand()%200) - i*500 - j*400;
                    box[i][j].y = yPos;

                    box[i][j].rect = {xPos, yPos, BOX_SIZE, BOX_SIZE};
                }
            }
        }
    }

    void CountDown(TTF_Font* font, SDL_Texture* background)
    {
        SDL_Surface* FontSurface;
        SDL_Texture* FontTexture;
        SDL_Color color = { 130, 36, 196};

        SDL_Rect dsRect;

        int textW = 100;
        int textH = 100;

        for (int i = 0; i < 4; i++)
        {
        SDL_RenderCopy(renderer, background, NULL, NULL);

        FontSurface = TTF_RenderText_Solid(font, "ON  MY  WAY  TO  VNU", color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {300, 80, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        FontSurface = TTF_RenderText_Solid(font, "Game  starts  in: ", color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {600, 300, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        TimeCount = Timing[i];
        FontSurface = TTF_RenderText_Solid(font, TimeCount, color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        dsRect = {800, 400, textW, textH};
        SDL_RenderCopy(renderer, FontTexture, NULL, &dsRect);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_RenderClear(renderer);
        }
        SDL_FreeSurface(FontSurface);
        SDL_DestroyTexture(FontTexture);

        Mix_Music* music = NULL;

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        {
            printf("%s", Mix_GetError());
        }

        music = Mix_LoadMUS("HelpMe.ogg");
        if (music == NULL)
        {
            printf("%s", Mix_GetError());
        }

        Mix_PlayMusic(music, -1);
    }

    void Update()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].moving(STEP);
                }
            }
        }
        SatKhuan.updateBullet();
    }

    bool checkCollision()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (SDL_HasIntersection(&box[i][j].rect , &UET_Main.CharacterRect) == true)
                {
                    //Thua
                    if (UET_Main.CharacterShield ==  false && box[i][j].shield == false && box[i][j].collided == false && box[i][j].sanitizer == false)
                    {
                        return true;
                    }
                    //an dc khien
                    if (UET_Main.CharacterShield == false && box[i][j].shield == true && box[i][j].collided == false && box[i][j].sanitizer == false)
                    {
                        UET_Main.CharacterShield = true;
                        box[i][j].drawing = false;
                        box[i][j].collided = true;

                        Mix_Chunk* chunk = NULL;

                        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
                        {
                            printf("%s", Mix_GetError());
                        }

                        chunk = Mix_LoadWAV("Coin.wav");
                        if (chunk == NULL)
                        {
                            printf("%s", Mix_GetError());
                        }
                        Mix_PlayChannel(-1, chunk, 0);

                        return false;
                    }
                    //mat khien
                    else if (UET_Main.CharacterShield == true && box[i][j].shield == false && box[i][j].sanitizer == false && box[i][j].collided == false)
                    {
                        UET_Main.CharacterShield = false;
                        box[i][j].collided = true;
                        box[i][j].drawing = false;

                        return false;
                    }
                    //co khien va an them khien
                    else if (UET_Main.CharacterShield == true && box[i][j].shield == true)
                    {
                        box[i][j].collided = true;
                        return false;
                    }
                    //an duoc sat khuan
                    else if (box[i][j].sanitizer == true && box[i][j].collided == false)
                    {
                        SatKhuan.AbleToShoot = true;
                        box[i][j].drawing = false;
                        box[i][j].collided = true;

                        Mix_Chunk* chunk = NULL;

                        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
                        {
                            printf("%s", Mix_GetError());
                        }

                        chunk = Mix_LoadWAV("Coin.wav");
                        if (chunk == NULL)
                        {
                            printf("%s", Mix_GetError());
                        }
                        Mix_PlayChannel(-1, chunk, 0);

                        return false;
                    }

                }

                if (SDL_HasIntersection(&box[i][j].rect, &SatKhuan.WRect) == true)
                {
                    if (SatKhuan.Tdrawing == true && box[i][j].shield == false && SatKhuan.hit == false)
                    {
                        box[i][j].collided = true;
                        box[i][j].drawing = false;
                        SatKhuan.hit = true;
                        return false;
                    }
                }

//                for (int i = 0; i < 3; i++)
//                {
//                    if (SDL_HasIntersection(&box[i][j].rect, &SatKhuan[i].WRect) == true)
//                    {
//                        if (SatKhuan[i].Tdrawing == true && box[i][j].shield == false && SatKhuan[i].hit == false)
//                        {
//                            box[i][j].collided = true;
//                            box[i][j].drawing = false;
//                            SatKhuan[i].hit = true;
//                        }
//                    }
//                }
            }
        }
        return false;
    }

    void updateLeft()
    {
        UET_Main.moveLeft();
    }

    void updateRight()
    {
        UET_Main.moveRight();
    }

    void updateUp()
    {
        UET_Main.moveUp();
    }

    void updateDown()
    {
        UET_Main.moveDown();
    }

    bool Over(SDL_Texture* BGtexture)
    {
        if (checkCollision())
        {
            Mix_HaltMusic();
            SDL_Texture* EndBackground = loadTexture("COVID.jpg", renderer);
            SDL_RenderCopy(renderer, EndBackground, NULL, NULL);

            SDL_RenderPresent(renderer);

            Mix_Chunk* chunk = NULL;

            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
            {
                printf("%s", Mix_GetError());
            }

            chunk = Mix_LoadWAV("gameOver.wav");
            if (chunk == NULL)
            {
                printf("%s", Mix_GetError());
            }
            Mix_PlayChannel(-1, chunk, 0);

            SDL_Delay(6000);
            return true;
        }
        else if (Score == NumberOfViruses)
        {
            Mix_HaltMusic();

            SDL_RenderClear(renderer);
            loadBackGround(BGtexture, renderer);
            UET_Main.WinDraw(renderer);

            SDL_Rect WRect = {280, 40, 800, 420};
            cout << "Yes" << endl;
            SDL_Texture* Wtexture = loadTexture("VNU.jpg", renderer);
            SDL_RenderCopy(renderer, Wtexture, NULL, &WRect);

            SDL_RenderPresent(renderer);

            Mix_Chunk* chunk = NULL;

            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
            {
                printf("%s", Mix_GetError());
            }

            chunk = Mix_LoadWAV("Applause.wav");
            Mix_PlayChannel(-1, chunk, 0);

            return true;
        }
        return false;
    }

    void LoadBoxes()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].LoadBox(VirusTexture, MaskTexture, SanitizerTexture);
                }
            }
        }
    }

    void GameDraw()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].TestDraw(renderer);
                }
            }
        }

        UET_Main.draw(renderer);
        SatKhuan.Bdraw(renderer);
    }

    void loadBackGround(SDL_Texture* BGtexture, SDL_Renderer* BGrenderer)
    {
        SDL_RenderCopy(BGrenderer, BGtexture, NULL, NULL);
    }

    void Shooting()
    {

        SatKhuan.x = UET_Main.x;
        SatKhuan.y = UET_Main.y;

        SatKhuan.WRect = {UET_Main.x, UET_Main.y, 60, 60};
        SatKhuan.Tdrawing = true;
        SatKhuan.AbleToShoot = false;

//        SatKhuan[numberOfBullet-1].x = UET_Main.x;
//        SatKhuan[numberOfBullet-1].y = UET_Main.y;
//
//        SatKhuan[numberOfBullet-1].WRect = {UET_Main.x, UET_Main.y, 60, 60};
//        SatKhuan[numberOfBullet-1].Tdrawing = true;
//        SatKhuan[numberOfBullet-1].AbleToShoot = false;

        Mix_Chunk* chunk = NULL;

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        {
            printf("%s", Mix_GetError());
        }

        chunk = Mix_LoadWAV("Shoot.wav");
        if (chunk == NULL)
        {
            printf("%s", Mix_GetError());
        }
        Mix_PlayChannel(-1, chunk, 0);

    }

    void handleEvent(SDL_Event &e)
    {
        if (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        SDL_Quit();
                    case SDLK_RIGHT:
                        updateRight();
                        break;
                    case SDLK_LEFT:
                        updateLeft();
                        break;
                    case SDLK_UP:
                        updateUp();
                        break;
                    case SDLK_DOWN:
                        updateDown();
                        break;
                    case SDLK_SPACE:
                        if (SatKhuan.AbleToShoot == true)
                        {
                            Shooting();
                        }
                }
            }
        }
    }

    void gameInit()
    {

        Mix_Music* music = NULL;

        if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
        {
            printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
        {
            printf("%s", Mix_GetError());
        }

        music = Mix_LoadMUS("HelpMe.ogg");
        if (music == NULL)
        {
            printf("%s", Mix_GetError());
        }

        Mix_PlayMusic(music, -1);
    }

    void GameCounting(TTF_Font* font)
    {
        string s;
        int textW = 100;
        int textH = 100;
        SDL_Rect DisRect = {100, 60, textW, textH};
        SDL_Surface* FontSurface;
        SDL_Texture* FontTexture;
        SDL_Color color = {255, 255, 0};

        s = to_string(Score) + "%";
        FontSurface = TTF_RenderText_Solid(font, s.c_str(), color);
        FontTexture = SDL_CreateTextureFromSurface(renderer, FontSurface);
        SDL_QueryTexture(FontTexture, NULL, NULL, &textW, &textH);
        SDL_RenderCopy(renderer, FontTexture, NULL, &DisRect);

        SDL_Rect bulletRect = {120, 200, 80, 100};
        SDL_Texture* bulletTexture = loadTexture("Water.png", renderer);

        if(SatKhuan.AbleToShoot == true && SatKhuan.hit == false)
        {
            SDL_RenderCopy(renderer, bulletTexture, NULL, &bulletRect);
        }
    }

    void checkScoreAdded()
    {
        for (int i = 0; i <= Row; i++)
        {
            for (int j = 0; j < VirusesPerRow; j++)
            {
                if (checkBox[i][j] == 1)
                {
                    box[i][j].AddScore();
                }
            }
        }
    }

};

#endif // GAME__H
