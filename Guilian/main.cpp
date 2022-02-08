#include <ctime>
#include <iostream>
#include <SDL2/SDL.h>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "body.hpp"

#define NBL 16
#define NBC 32

int main_coach()
{
    MainSDLWindow window;
    window.init("Snake", 200, 200);
    int game_state = 1;
    SDL_Event event;
    do {
      // End of frame:
      SDL_PollEvent(&event);
      switch(event.type) {
        case SDL_QUIT:
          game_state = 0;
          break;
      }
      SDL_Delay(100);
    } while (game_state);
    return EXIT_SUCCESS;
}

int main()
{
    MainSDLWindow window;
    window.init("Snake", 1024, 512);

    srand((unsigned int)time(0));

    Snake *snk = new Snake();
    fruit *frt = new fruit();
    frt->summon(snk);

    int frame_delay;
    Uint32 frame_start;
    SDL_Event event;

    do
    {
        window.quit();
        SDL_Delay(100);
        snk->keyboard();
        snk->move();
        SDL_Delay(100);
        window.Print(snk->tail , frt);

        // cout << "test4" << endl;

        // int test = 0;
        // //test = snk->colision();
        // if (test == 1)
        // {
        //     GameIsRunning = 0;
        // }

        // cout << "GameIsRunning" << GameIsRunning << endl;
        // if (GameIsRunning == 0) break;
        // continue;

        // cout << "test2" << endl;
        // int a, b = frt->getCoo();
        // if (snk->eat(a, b) == 1)
        // {
        //     frt->summon(snk);
        // }

        // frame_delay = 20 - (SDL_GetTicks() - frame_start);
        // if (frame_delay > 0)
        // SDL_Delay(frame_delay);

    } while (window.GetGameState());

    if(snk != NULL) delete snk;
    if(frt != NULL) delete frt;
}