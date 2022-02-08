#include <string>
#include <iostream>
#include <cstdlib>
#include "MainSDLWindow.hpp"

#define SIZE 32

// MAINSDLWINDOWS : création de fenêtre

MainSDLWindow::MainSDLWindow()
{
    cout << "CONSTRUCTOR!!!" << endl;
    this->window = NULL;
    this->renderer = NULL;
    this->GameIsRunning = true;
}

MainSDLWindow::~MainSDLWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool MainSDLWindow::GetGameState(){
    return GameIsRunning;
}

SDL_Rect MainSDLWindow::GetRect()
{
    return rect;
}

void MainSDLWindow::quit(){
    SDL_Event event;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            GameIsRunning = false;
        }
    }
}

int MainSDLWindow::init(const char nom[], int width, int height)
{
    cout << "INIT!!!" << endl;
    // Init SDL:
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    window = SDL_CreateWindow(nom, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == NULL)
    {
        cout << "Erreur lors de la creation d'une fenetre :" << SDL_GetError();
        return EXIT_FAILURE;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Erreur lors de la creation d'un renderer :" << SDL_GetError();
        return EXIT_FAILURE;
    }
    rect.h = SIZE;
    rect.w = SIZE;
    return EXIT_SUCCESS;
}

SDL_Renderer *MainSDLWindow::GetRenderer(void)
{
    return renderer;
}

void MainSDLWindow::Print(body *tail, fruit *fruit)
{

    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    this->rect.x = fruit->getX() * SIZE;
    this->rect.y = fruit->getY() * SIZE;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);

    // SDL_SetRenderTarget(renderer, NULL);

    body *Segment;
    Segment = tail;
    while (Segment->getPrev() != NULL)
    {
        rect.x = Segment->getX() * SIZE;
        rect.y = Segment->getY() * SIZE;
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect);
        Segment = Segment->getPrev();
    }
    rect.x = Segment->getX() * SIZE;
    rect.y = Segment->getY() * SIZE;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer); // Refresh the renderer
}