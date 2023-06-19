#ifndef INCLUDE_SNAKE_HPP_
#define INCLUDE_SNAKE_HPP_

#include "../include/function.hpp"

#include <cstddef>
#include <vector>
#include <string>
#include <conio.h>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <iostream>

class Plansza {
public:
    Plansza(int x = 30, int y = 30) : x_(x), y_(y) {};

    void rysuj();

private:
    int x_;
    int y_;

};

class Snake {
public:
    Snake(int dlugosc = 1, int glowax = 0, int gloway = 0, int ogonx = 0, int ogony = 0, char pole = '0') : dlugosc_(
            dlugosc), x_(glowax), y_(gloway), x_k(ogonx), y_k(ogony), pole_(pole) {};

    void set_size(int dl) { dlugosc_ = dl; };

    int get_size() const { return dlugosc_; };

    void set_head_X(int x) { x_ = x; };

    void set_head_Y(int y) { y_ = y; };

    int get_head_X() const { return x_; };

    int get_head_Y() const { return y_; };

    void set_tail_X(int x) { x_k = x; };

    void set_tail_Y(int y) { y_k = y; };

    int get_tail_X() const { return x_k; };

    int get_tail_Y() const { return y_k; };

    void usun_ogon();

    void rysuj_glowe(char symbol);

    void head_both(int x, int y) {
        x_ = x;
        y_ = y;
    };

    void set_pole(char pole) { pole_ = pole; };


private:
    int dlugosc_, x_, y_, x_k, y_k;
    char pole_;
    char symbol;
};

#endif
