#pragma once
#include <SDL2/SDL.h>
#include "snake.hpp"

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
        void Print(body *tail, fruit *fruit);
    private:
        bool GameIsRunning;
        SDL_Window * window;
        SDL_Renderer * renderer;
};