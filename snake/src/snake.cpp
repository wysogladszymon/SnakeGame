#include "../include/snake.hpp"

void Plansza::rysuj(){
    //rysowanie góry ramki
    std::cout<< char(201);
    for ( int i = 0; i < x_ ; i++)
        std::cout<< char(205) <<char(205) ;
    std::cout<<char(187)<<std::endl;
    //rysowanie boków ramki
    for (int i = 0; i < y_ ; i++ )
    {
        std::cout << char(186);
        for (int j = 0; j < x_; j++)
            std::cout << "  ";
        std::cout << char(186) <<std::endl;
    }
    //rysowanie dołu ramki
    std::cout<< char(200);
    for ( int i = 0; i < x_ ; i++)
        std::cout<< char(205) <<char(205) ;
    std::cout<< char(188);
}

void Snake::usun_ogon()
{
    idzdoxy(x_k * 2 + 1, y_k + 1);
    std::cout<<"  ";
}

void Snake::rysuj_glowe()
{
    idzdoxy(x_ * 2 + 1, y_ + 1);
    std::cout<<"0";
}
