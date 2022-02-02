#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "body.hpp"

#define NBL 16
#define NBC 32

MainSDLWindow fenetre;
Snake snk;

MainSDLWindow::MainSDLWindow(){
    this-> window, renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Rect MainSDLWindow::GetRect(){
    return rect;
}

int MainSDLWindow::Init(const char nom[], int width, int height){
    window = SDL_CreateWindow(nom,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, width , height , SDL_WINDOW_RESIZABLE);
    if(window == NULL){
        cout << "Erreur lors de la creation d'une fenetre :" << SDL_GetError();
        return EXIT_FAILURE;
    } 
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        cout << "Erreur lors de la creation d'un renderer :" << SDL_GetError();
        return EXIT_FAILURE;
    }
    rect.x = 300;
    rect.y = 300;
    rect.h = 20;
    rect.w = 20;
    return EXIT_SUCCESS;
}

SDL_Renderer *MainSDLWindow::GetRenderer(void){
    return renderer;
}

body::body(){
    this -> x = NULL;
    this -> y = NULL;
    this -> prev = NULL;
}

body::~body(){}

void body::setPrev(body a){
    *prev = a;
}

int body::getCoo(){
    return x, y;
}

void body::setx(int a){
    x = a;
}

void body::sety(int b){
    x = b;
}

void body::move(){
    if (prev != NULL){
        int a, b = prev->getCoo();
        x = a;
        y = b;
        prev->move();
    }
}

Snake::Snake(){
    head.setx(NBC/2);
    head.sety(NBL/2);
    tail = head;
    length = 1;
    dir = "r";
}

Snake::~Snake(){
}

void Snake::move(void){

    tail.move();

    int x, y = head.getCoo();
    
    if ( dir == "d") {
        head.setx(x+1);
    }
    else if ( dir == "u") {
        head.setx(x-1);
    }
    else if ( dir == "r") {
        head.sety(y+1);
    }
    else if ( dir == "l") {
        head.sety(y-1);
    }
}

void Snake::keyboard(void) {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP] && dir != "d") {
    dir = "u";
  }
  if (keystates[SDL_SCANCODE_DOWN] && dir != "u") {
    dir = "d";
  }
  if (keystates[SDL_SCANCODE_LEFT] && dir != "r") {
    dir = "l";
  }
  if (keystates[SDL_SCANCODE_RIGHT] && dir != "l") {
    dir = "r";
  }
}

string Snake::getDir(){
    return dir;
}

int Snake::getLength(){
    return length;
}

int **tab_malloc() {
  int **tab_ = (int**)malloc(NBL * sizeof(int*));
  for(int l=0; l<NBL; l++)
    tab_[l] = (int*)malloc(NBC * sizeof(int));
  return tab_;
}
 
int main(){
    int length = snk.getLength();
    bool IsGameRunning = true;
    SDL_Rect square = fenetre.GetRect();
    fenetre.Init("une fenêtre", 600, 600);
    SDL_Renderer *renderer = fenetre.GetRenderer();
    SDL_Event event;
    
    
    while (IsGameRunning)
    {
        while (SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT){
            IsGameRunning = false;
        }
    }
    snk.move();
    snk.keyboard();
    /*
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &square);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
    */
    SDL_Delay(500);

    }
}
