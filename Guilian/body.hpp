#pragma once

class body {
    public:
        body();
        ~body();
        void setPrev(body*);
        void print();
        int getCoo();
        int testAllCoo(int a, int b);
        void move();
        void setx(int a);
        void sety(int b);
        body* getPrev();
        void setCoo(int a, int b);
        body* newTail();
    private:
        int x;
        int y;
        body *prev;
};