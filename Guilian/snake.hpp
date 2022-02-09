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
        int getScore();
        body *head;
        body *tail;
    private:
        int dir;
        int score;
};   

class fruit{
    public:
        fruit();
        ~fruit();
        int getX();
        int getY();
        int getType(); 
        void summon(Snake *snk);
    private:
        int x;
        int y;
        int type;
};