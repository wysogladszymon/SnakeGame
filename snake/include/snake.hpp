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
    Snake(int dlugosc = 4) : dlugosc_(dlugosc) {};
    void zwieksz_rozmiar() {dlugosc_ += 1;};
    int get_size() const {return dlugosc_;};
private:
    int dlugosc_;
};

#endif
