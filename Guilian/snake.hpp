#pragma once
#include "body.hpp"

class Snake {
    public:
        Snake();
        ~Snake();
        void keyboard();
        void move();
        void newTail();
        int getDir();
        int testBody(int a, int b);
        int eat(int a, int b);
        int colision();
        body *head;
        body *tail;
    private:
        int dir;
};   

class fruit{
    public:
        fruit();
        ~fruit();
        int getCoo();
        int getType(); 
        void summon(Snake *snk);
    private:
        int x;
        int y;
        int type;
};