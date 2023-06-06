#ifndef INCLUDE_SNAKE_HPP_
#define INCLUDE_SNAKE_HPP_

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
    Snake(int dlugosc = 1) : dlugosc_(dlugosc) {};
    void set_size(int dl) {dlugosc_ = dl;};
    int size() const {return dlugosc_;};
    void set_x(int x) {x_ = x;};
    void set_y(int y) {y_ = y;};
    int start_x(){return x_;};
    int start_y(){return y_;};
    int end_x(){return x_k;};
    int end_y(){return y_k;};
    void set_endx(int x) {x_k = x;};
    void set_endy(int y) {y_k = y;};

private:
    int dlugosc_, x_, y_ ,x_k ,y_k;
};

#endif
