#include <ctime>
#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "body.hpp"
#include "fruit.hpp"

#define NBL 16
#define NBC 32

// MAINSDLWINDOWS : création de fenêtre

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

int MainSDLWindow::init(const char nom[], int width, int height){
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

//BODY : classe pour un morceau de serpent

body::body(){
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

int body::testAllCoo(int a, int b){
    if (prev != NULL){

        int test = prev->testAllCoo(a,b);
        
        if (test == 1){
            return 1;
        }
        if (x == a && y == b){
            return 1;
        
        return 0;
        }
    }
    return 0;
}

void body::setCoo(int a, int b){
    x = a;
    y = b;
}

//SNAKE : class pour une entitée "serpent"

Snake::Snake(){
    head.setx(NBC/2);
    head.sety(NBL/2);
    tail = head;
    dir = 3;
}

Snake::~Snake(){
}

void Snake::move(void){

    tail.move();

    int x, y = head.getCoo();
    
    if ( dir == 2) {
        head.setx(x+1);
    }
    else if ( dir == 1) {
        head.setx(x-1);
    }
    else if ( dir == 3) {
        head.sety(y+1);
    }
    else if ( dir == 4) {
        head.sety(y-1);
    }
}

void Snake::keyboard(void) {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP] && dir != 2) {
    dir = 1;
  }
  else if (keystates[SDL_SCANCODE_DOWN] && dir != 1) {
    dir = 2;
  }
  else if (keystates[SDL_SCANCODE_LEFT] && dir != 3) {
    dir = 4;
  }
  else if (keystates[SDL_SCANCODE_RIGHT] && dir != 4) {
    dir = 3;
  }
}

void Snake::eat(fruit fruit, Snake snk){
    int a, b = fruit.getCoo();
    int c, d = head.getCoo();
    if (a==c && b==d){
        fruit.summon(snk);
        newTail();
    }
}

void Snake::newTail(){
    body newTail;
    int a, b = tail.getCoo();
    newTail.setCoo(a ,b);
    newTail.setPrev(tail);
    tail = newTail;
}

int Snake::getDir(){
    return dir;
}


int Snake::colision(){
    int a, b = head.getCoo();
    if (a == -1 || a == NBC){
        return 1;
    }else if(b == -1 || b == NBL){
        return 1;
    }
    int test = tail.testAllCoo(a,b);
    if (test == 1){
        return 1;
    }

    return 0;
}

int Snake::testBody(int a, int b){
    int test = tail.testAllCoo(a, b);
    return test;
}

// FRUIT : objet fruit du jeu

fruit::fruit(){
    this -> type = 1;

}

fruit::~fruit(){}

int fruit::getCoo(){
    return x, y;
}

int fruit::getType(){
    return type;
}

void fruit::summon(Snake snk){

    int isOkay = 1;
    do{
        srand((unsigned int)time(0));

        int a = rand()%NBC -1;
        int b = rand()%NBL -1;

        int test = snk.testBody(a,b);
        if (test == 0){
            isOkay = 0;
        }

    }while(isOkay != 1);
}