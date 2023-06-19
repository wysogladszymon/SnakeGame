#include "include/snake.hpp"

#include <cstdlib>
#include <string>


int main() {
    int a,b,c;
    int wysokosc;
    int szerokosc;
    int apple;
    int jedzeniex, jedzeniey;
    char klawisz ;
    char kierunek = 'p';                //p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int>historiay;
    int level;                          //zmienna ustalająca poziom gry

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    //menu kontekstowe wyboru przez gracza odpowiednich parametrów
    std::cout<< "Podaj wymiar planszy miedzy 10, a 25:  "<<std::endl;
    std::cin >> szerokosc;
    
    std::cout<< "Wpisz symbol planszy:"<<std::endl;
    std::cin >> symbol

    //zabezpieczenie przed za malym wymiarem
    if (szerokosc < 10)
    {
        szerokosc = 10;
    }

    //zabezpieczenie przed zbyt duzym wymiarem
    if (szerokosc > 25)
    {
        szerokosc = 25;
    }
    wysokosc = szerokosc;

    //poziom gry
    std::cout << "Podaj w skali 1-3 poziom trudnosci:  ";
    std::cin >> level;

    //podanie liczby jablek
    std::cout<< "Podaj liczbę jedzenia (1-5):  "<<std::endl;
    std::cin>> apple;

    //instrukcje dla zle podanych parametrow
    if(apple < 1)
        apple = 1;
    if(apple>5)
        apple = 5;

    //instrukcje dla zle podanych parametrow
    if(level<1)
        level = 1;
    if (level>3)
        level = 3;

    //zmienienie proporcjonalnosci poziomow
    level+=2;

    //reset gry
    restart:

    a = losowanie(szerokosc);
    b = losowanie(wysokosc);



    // inicjalizacja weza
    Snake wonsz(1,a,b,a,b);


    //oczyszczenie ekranu
    system("Cls");

    int pole[wysokosc][szerokosc];      // 0 - puste pole , 1 - jedzenie, 2 - waz
    //ustawienie tablicy samymi pustymi polami
    for (int i = 0; i < wysokosc;i++ )
        for(int j = 0; j < szerokosc ; j++)
            pole[i][j] = 0;

    Plansza plansza(szerokosc ,wysokosc );
    plansza.rysuj();



    c = 0;
    //losowanie poczatkowego pola jedzenia
    while (c < apple)
    {
        do
        {
            jedzeniex = losowanie(szerokosc);
            jedzeniey = losowanie(wysokosc);
        }while (jedzeniex == a && jedzeniey == b && pole[jedzeniey][jedzeniex] != 1);
        pole[jedzeniey][jedzeniex] = 1;
        idzdoxy(jedzeniex*2 + 1, jedzeniey+1);
        std::cout<<'x';
        c++;
    }


    //narysowanie wyniku
    idzdoxy(2, wysokosc + 2);
    std::cout<<"SCORE: "<< wonsz.size();


    //petla gry
    while (pole[wonsz.head_y()][wonsz.head_x()] != 2 )
    {
    //narysowanie glowy oraz ustawienie pola w tablicy, aby oznaczyc lokalizacje weza
        pole[wonsz.head_y()][wonsz.head_x()] = 2;
        wonsz.rysuj_glowe();




        Sleep(1000/level);

        //zapisanie w histori petli wspolrzednych glowy
        historiax.push_back(wonsz.head_x());
        historiay.push_back(wonsz.head_y());

        //wpisanie i usuniecie ogona
        wonsz.tail_x(historiax[historiax.size() - wonsz.size()]);
        wonsz.tail_y(historiay[historiay.size() - wonsz.size()]);
        wonsz.usun_ogon();
        pole[wonsz.tail_y()][wonsz.tail_x()] = 0;


        //uzaeleznienie kierunku w zaleznosci od przycisku
        if(_kbhit())
        {
            //dodanie pauzy na p
            klawisz = _getch();
            if (klawisz == 80 || klawisz == 112)
                klawisz = _getch();
            //reset na r
            if (klawisz == 82 || klawisz == 114)
            {
                goto restart;
            }

            switch (klawisz)
            {
                case 87:
                case 119:
                    if (kierunek != 'd')
                        kierunek = 'g';
                    break;
                case 83:
                case 115:
                    if (kierunek != 'g')
                        kierunek = 'd';
                    break;
                case 68:
                case 100:
                    if (kierunek != 'l')
                        kierunek = 'p';
                    break;
                case 65:
                case 97:
                    if (kierunek != 'p')
                        kierunek = 'l';
                    break;
                default:
                    break;
            }
        }

        //poruszanie w zaleznosci od kierunku
        switch(kierunek)
        {
            case 'g':
                wonsz.head_both(wonsz.head_x(), wonsz.head_y() - 1);
                break;
            case 'd':
                wonsz.head_both(wonsz.head_x(), wonsz.head_y() +1);
                break;
            case 'p':
                wonsz.head_both(wonsz.head_x()+1, wonsz.head_y());
                break;
            case 'l':
                wonsz.head_both(wonsz.head_x()-1, wonsz.head_y());
                break;
        }

        //ustawienie wspolrzednych weza, aby miescily sie w polu gry
        wonsz.head_x((wonsz.head_x()+szerokosc)%szerokosc);
        wonsz.head_y((wonsz.head_y()+wysokosc)%wysokosc );


        //instrukcja gdy waz zje jedzenie
        if (pole[wonsz.head_y()][wonsz.head_x()] ==1)
        {
            wonsz.size(wonsz.size() + 1);
            //ustawienie wyniku
            idzdoxy(9, wysokosc + 2);
            std::cout<<wonsz.size();

            //losowanie nowego pola jedzenia
            while (pole[jedzeniey][jedzeniex] != 0 )
            {
                jedzeniex = losowanie(szerokosc);
                jedzeniey = losowanie(wysokosc);
            }
            pole[jedzeniey][jedzeniex] = 1;
            idzdoxy(jedzeniex * 2 + 1 , jedzeniey+1);
            std::cout<<'x';

        }


    }

    idzdoxy((2*szerokosc-10)/ 2, wysokosc / 2 );
    std::cout<<"GAME OVER" ;
    idzdoxy((2*szerokosc-21)/ 2, wysokosc / 2 +1);
    std::cout<< char(186) <<"  Press ENTER to Quit";

    getch();
}
