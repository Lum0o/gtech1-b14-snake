#pragma once
#include <SDL2/SDL.h>
#include "snake.hpp"
#include "fruit.hpp"
#include <SDL2/SDL_ttf.h>

using namespace std;

class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        void quit();
        bool GetGameState();
        int init(const char name[], int width, int height);
        SDL_Renderer *GetRenderer();
        SDL_Rect GetRect();
        SDL_Rect rect;
        void Print(body *tail, fruit *fruit, int score);
    private:
        bool GameIsRunning;
        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Surface * textZone;
        SDL_Texture * text;
        SDL_Rect scoreArea;
        const char *scoreText;
        TTF_Font *font;
        string scoreString;
};