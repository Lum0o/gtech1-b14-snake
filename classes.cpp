#include <ctime>
#include <SDL2/SDL.h>
#include "snake.hpp"
#include "fruit.hpp"
#include "body.hpp"

#define NBL 16
#define NBC 32

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
#define PAUSE 0

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
    if (this->x == a && this->y == b && prev != NULL){
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
    body *test = new body();
    test->prev = this;
    test->setx(this->x);
    test->sety(this->y);
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
    dir = PAUSE;
    score = 0;
}

Snake::~Snake(){
}

void Snake::move(void){

    if (dir != PAUSE){
      tail->move();
    }

    int x = head->getX();
    int y = head->getY();
    
    if ( dir == UP) {
        head->sety(y-1);
    }
    else if ( dir == DOWN) {
        head->sety(y+1);
    }
    else if ( dir == RIGHT) {
        head->setx(x+1);
    }
    else if ( dir == LEFT) {
        head->setx(x-1);
    }
}

void Snake::keyboard(void) {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP] && dir != DOWN) {
    dir = UP;
  }
  else if (keystates[SDL_SCANCODE_DOWN] && dir != UP) {
    dir = DOWN;
  }
  else if (keystates[SDL_SCANCODE_LEFT] && dir != RIGHT) {
    dir = LEFT;
  }
  else if (keystates[SDL_SCANCODE_RIGHT] && dir != LEFT) {
    dir = RIGHT;
  }
}

int Snake::eat(int a, int b){
    if (a==head->getX() && b==head->getY()){
        tail = tail->newTail();
        score ++;
        return 1;
    }
    return 0;
}

int Snake::getDir(){
    return dir;
}

int Snake::getScore(){
    return score;
}


int Snake::colision(){
    int a = head->getX();
    int b = head->getY();

    if (a < 0 || a > NBC){
        return 1;
    }else if(b < 0 || b > NBL){
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
        int a = rand()%NBC;
        int b = rand()%NBL;

        int test = snk->testBody(a,b);
        if (test == 0){
            isOkay = 0;
            this -> x = a;
            this -> y = b;
        }


    }while(isOkay == 1);
}