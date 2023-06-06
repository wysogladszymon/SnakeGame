#include "snake.hpp"

void Plansza::rysuj(){
    //rysowanie góry ramki
    std::cout<< char(219);
    for ( int i = 0; i < x_ ; i++)
        std::cout<< char(223) <<char(223) ;
    std::cout<<char(219)<<std::endl;
    //rysowanie boków ramki
    for (int i = 1; i < y_ ; i++ )
    {
        std::cout << char(219);
        for (int j = 0; j < x_; j++)
            std::cout << "  ";
        std::cout << char(219) <<std::endl;
    }
    //rysowanie dołu ramki
    for ( int i = 0; i < x_+1 ; i++)
        std::cout<< char(223) <<char(223) ;

}

