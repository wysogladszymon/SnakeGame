#ifndef INCLUDE_SNAKE_HPP_
#define INCLUDE_SNAKE_HPP_

#include <cstddef>
#include <vector>
#include <string>
#include <conio.h>
#include<cstdlib>
#include <ctime>
#include <windows.h>

class Plansza{
public:
    Plansza(int x = 30, int y = 30) : x_(x) , y_(y) {};
private:
    int x_;
    int y_;

};
#endif
