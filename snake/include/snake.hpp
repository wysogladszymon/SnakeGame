#ifndef INCLUDE_SNAKE_HPP_
#define INCLUDE_SNAKE_HPP_

#include "function.hpp"

#include <cstddef>
#include <vector>
#include <string>
#include <conio.h>
#include<cstdlib>
#include <ctime>
#include <windows.h>
#include <iostream>

class Plansza{
public:
    Plansza(int x = 30, int y = 30) : x_(x) , y_(y) {};
    void rysuj()  ;
private:
    int x_;
    int y_;

};

class Snake {
public:
    Snake(int dlugosc = 1,int glowax = 0, int gloway= 0, int ogonx= 0, int ogony= 0) : dlugosc_(dlugosc), x_(glowax), y_(gloway) ,x_k(ogonx) ,y_k(ogony) {};
    void size(int dl) {dlugosc_ = dl;};
    int size() const {return dlugosc_;};
    void head_x(int x) {x_ = x;};
    void head_y(int y) {y_ = y;};
    int head_x() const {return x_;};
    int head_y() const {return y_;};
    void tail_x(int x) {x_k = x;};
    void tail_y(int y) {y_k = y;};
    int tail_x() const {return x_k;};
    int tail_y() const {return y_k;};
    void usun_ogon();
    void rysuj_glowe();
    void head_both(int x, int y) { x_ = x; y_ = y;};
private:
    int dlugosc_, x_, y_ ,x_k ,y_k;
};

#endif