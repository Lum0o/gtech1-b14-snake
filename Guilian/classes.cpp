#include <ctime>
#include <SDL2/SDL.h>
#include "snake.hpp"
#include "body.hpp"

#define NBL 16
#define NBC 32

//BODY : classe pour un morceau de serpent

body::body(){
    this->prev = NULL;
}

body::~body(){}

void body::setPrev(body *a){
    this->prev = a;
}

int body::getX(){
    return this->x;
}

int body::getY(){
    return this->y;
}

void body::setx(int a){
    x = a;
}

void body::sety(int b){
    y = b;
}

void body::move(){
    if (prev != NULL){
        x = prev->getX();
        y = prev->getY();
        prev->move();
    }
}

int body::testAllCoo(int a, int b){
    if (this->x == a && this->y == b){
        return 1;
    }
    if (this->prev != NULL){
        return this->prev->testAllCoo(a, b);
    }
    return 0;
}

void body::setCoo(int a, int b){
    x = a;
    y = b;
}

body* body::newTail(){
    body *test;
    test->prev = this;
    test->setx(x);
    test->sety(y);
    return test;
}

body* body::getPrev(){
    return prev;
}

//SNAKE : class pour une entitée "serpent"

Snake::Snake(){
    this->head = new body();
    this->head->setx(NBC/2);
    this->head->sety(NBL/2);
    this->tail = this->head;
    dir = 3;
}

Snake::~Snake(){
}

void Snake::move(void){

    tail->move();

    int x = head->getX();
    int y = head->getY();
    
    if ( dir == 2) {
        head->setx(x+1);
    }
    else if ( dir == 1) {
        head->setx(x-1);
    }
    else if ( dir == 3) {
        head->sety(y+1);
    }
    else if ( dir == 4) {
        head->sety(y-1);
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

int Snake::eat(int a, int b){
    if (a==head->getX() && b==head->getY()){
        tail = tail->newTail();
        return 1;
    }
    return 0;
}

int Snake::getDir(){
    return dir;
}


int Snake::colision(){
    int a = head->getX();
    int b = head->getY();
    if (a == -1 || a == NBC){
        return 1;
    }else if(b == -1 || b == NBL){
        return 1;
    }
    int test = tail->testAllCoo(a,b);
    if (test == 1){
        return 1;
    }

    return 0;
}

int Snake::testBody(int a, int b){
    int test = tail->testAllCoo(a, b);
    return test;
}

// FRUIT : objet fruit du jeu

fruit::fruit(){
    this -> type = 1;
    this -> x = 0;
    this -> y = 0;

}

fruit::~fruit(){}

int fruit::getX(){
    return this->x;
}

int fruit::getY(){
    return this->y;
}

int fruit::getType(){
    return type;
}

void fruit::summon(Snake *snk){
    int isOkay = 1;
    do{
        printf("x y bfr random = %d %d \n",x,y);
        int a = rand()%NBC;
        int b = rand()%NBL;
        printf("a b aft random = %d %d\n",a,b);

        int test = snk->testBody(a,b);
        if (test == 0){
            isOkay = 0;
            this -> x = a;
            this -> y = b;
        printf("x y aft random = %d %d\n",x,y);
        }


    }while(isOkay == 1);
}