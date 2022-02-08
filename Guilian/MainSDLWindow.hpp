#pragma once
#include <SDL2/SDL.h>
#include "snake.hpp"

using namespace std;

class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        int init(const char name[], int width, int height);
        SDL_Renderer *GetRenderer();
        SDL_Rect GetRect();
        SDL_Rect rect;
        void Print(body *tail, fruit *fruit);
    private:
        SDL_Window * window;
        SDL_Renderer * renderer;
};
