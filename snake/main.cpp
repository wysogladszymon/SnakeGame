#include "include/snake.hpp"
#include "include/function.hpp"

#include <cstdlib>
#include <string>


int main() {
    int a,b;
    int wysokosc = 10;
    int szerokosc = 10;
    int pole[wysokosc][szerokosc];      // 0 - puste pole , 1 - jedzenie, 2 - waz
    int jedzeniex, jedzeniey;
    char klawisz;
    char kierunek = 'p';                //p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int>historiay;

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    //ustawienie tablicy samymi pustymi polami
    for (int i = 0; i < wysokosc;i++ )
        for(int j = 0; j < szerokosc ; j++)
            pole[i][j] = 0;

    //oczyszczenie ekranu
    system("Cls");

    Plansza plansza(szerokosc,wysokosc);
    plansza.rysuj();

    a = losowanie(szerokosc);
    b = losowanie(wysokosc);
    // inicjalizacja i losowanie poczatkowego ustawienia węża
    Snake wonsz(1,a,b,a-1,b);

    //oznaczenie w tablicy miejsca węża
    pole[wonsz.head_y()][wonsz.head_x()] = 2;

    //losowanie poczatkowego pola jedzenia
    do
    {
        jedzeniex = losowanie(szerokosc);
        jedzeniey = losowanie(wysokosc);
    }while (pole[jedzeniey][jedzeniex] == 2);

    idzdoxy(jedzeniex*2+1, jedzeniey+1);
    std::cout<<'x';

    //petla gry
    while (pole[wonsz.head_x()][wonsz.head_y()] != 2 )
    {

        //uzaeleznienie kierunku w zaleznosci od przycisku
        if(_kbhit())
        {
            klawisz = getch();
            switch (klawisz)
            {
                case 87:
                case 119:
                    kierunek = 'g';
                    break;
                case 83:
                case 115:
                    kierunek = 'd';
                    break;
                case 68:
                case 100:
                    kierunek = 'p';
                    break;
                case 65:
                case 97:
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
        wonsz.tail_x((wonsz.tail_x()+szerokosc)%szerokosc);
        wonsz.head_y((wonsz.head_y()+wysokosc)%wysokosc);
        wonsz.tail_y((wonsz.tail_y()+wysokosc)%wysokosc);

        //narysowanie glowy oraz ustawienie pola w tablicy, aby oznaczyc lokalizacje weza
        pole[wonsz.head_y()][wonsz.head_x()] = 2;
        wonsz.rysuj_glowe();

        //zapisanie w histori petli wspolrzednych glowy
        historiax.push_back(wonsz.head_x());
        historiay.push_back(wonsz.head_y());

        Sleep(1000);

        //instrukcja co zrobic gdy waz zje jedzenie
        if(pole[jedzeniey][jedzeniex] == 2)
            wonsz.size(wonsz.size() + 1);

        //ustawienie wspolrzednych konca
        wonsz.tail_x(historiax[historiax.size() - wonsz.size()]);
        wonsz.tail_y(historiay[historiay.size() - wonsz.size()]);
        wonsz.usun_ogon();
        pole[wonsz.tail_y()][wonsz.tail_x()] = 0;



        while (pole[jedzeniey][jedzeniex] == 2)
        {
            jedzeniex = losowanie(szerokosc);
            jedzeniey = losowanie(wysokosc);
        }
        idzdoxy(jedzeniex*2+1, jedzeniey+1);
        std::cout<<'x';

    }

    Sleep(1000);

    idzdoxy((2*szerokosc-10)/2, wysokosc + 2);
    std::cout<<"KONIEC GRY";
}
