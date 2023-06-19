#include "include/snake.hpp"

#include <cstdlib>
#include <string>


int main() {
<<<<<<< HEAD
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
=======
    int a, b;
    int wysokosc = 25;
    int szerokosc = 25;
    int pole[wysokosc][szerokosc];      // 0 - puste pole , 1 - jedzenie, 2 - waz
    int jedzeniex, jedzeniey;
    char klawisz, newkierunek;
    char kierunek = 'p';                //p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int> historiay;
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    //menu kontekstowe wyboru przez gracza odpowiednich parametrów
    std::cout<< "Podaj wymiar planszy miedzy 10, a 25:  "<<std::endl;
    std::cin >> szerokosc;

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
    for (int i = 0; i < wysokosc; i++)
        for (int j = 0; j < szerokosc; j++)
            pole[i][j] = 0;

<<<<<<< HEAD
    Plansza plansza(szerokosc ,wysokosc );
    plansza.rysuj();

=======
    //oczyszczenie ekranu
    system("Cls");

    Plansza plansza(szerokosc, wysokosc);
    plansza.rysuj();

    a = losowanie(szerokosc);
    b = losowanie(wysokosc);
    // inicjalizacja i losowanie poczatkowego ustawienia węża
    Snake wonsz(1, a, b, a, b);
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903


    c = 0;
    //losowanie poczatkowego pola jedzenia
<<<<<<< HEAD
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

=======
    do {
        jedzeniex = losowanie(szerokosc);
        jedzeniey = losowanie(wysokosc);
    } while (jedzeniex == a && jedzeniey == b);

    idzdoxy(jedzeniex * 2 + 1, jedzeniey + 1);
    std::cout << 'x';
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903

    //narysowanie wyniku
    idzdoxy(2, wysokosc + 2);
    std::cout << "SCORE: " << wonsz.get_size();


    //petla gry
    while (pole[wonsz.get_head_Y()][wonsz.get_head_X()] != 2) {
        //narysowanie glowy oraz ustawienie pola w tablicy, aby oznaczyc lokalizacje weza
        pole[wonsz.get_head_Y()][wonsz.get_head_X()] = 2;
        wonsz.rysuj_glowe();

<<<<<<< HEAD
=======
        //instrukcja co zrobic gdy waz zje jedzenie
        if (pole[jedzeniey][jedzeniex] == 2)
            wonsz.set_size(wonsz.get_size() + 1);
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903



        Sleep(1000/level);

        //zapisanie w histori petli wspolrzednych glowy
        historiax.push_back(wonsz.get_head_X());
        historiay.push_back(wonsz.get_head_Y());

        //wpisanie i usuniecie ogona
        wonsz.set_tail_X(historiax[historiax.size() - wonsz.get_size()]);
        wonsz.set_tail_Y(historiay[historiay.size() - wonsz.get_size()]);
        wonsz.usun_ogon();
        pole[wonsz.get_tail_Y()][wonsz.get_tail_X()] = 0;


        //uzaeleznienie kierunku w zaleznosci od przycisku
<<<<<<< HEAD
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
=======
        if (_kbhit()) {
            klawisz = getch();
            switch (klawisz) {
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903
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
        switch (kierunek) {
            case 'g':
                wonsz.head_both(wonsz.get_head_X(), wonsz.get_head_Y() - 1);
                break;
            case 'd':
                wonsz.head_both(wonsz.get_head_X(), wonsz.get_head_Y() + 1);
                break;
            case 'p':
                wonsz.head_both(wonsz.get_head_X() + 1, wonsz.get_head_Y());
                break;
            case 'l':
                wonsz.head_both(wonsz.get_head_X() - 1, wonsz.get_head_Y());
                break;
        }

        //ustawienie wspolrzednych weza, aby miescily sie w polu gry
        wonsz.set_head_X((wonsz.get_head_X() + szerokosc) % szerokosc);
        wonsz.set_head_Y((wonsz.get_head_Y() + wysokosc) % wysokosc);


<<<<<<< HEAD
        //instrukcja gdy waz zje jedzenie
        if (pole[wonsz.head_y()][wonsz.head_x()] ==1)
=======
              //instrukcja gdy waz zje jedzenie
        if (pole[jedzeniey][jedzeniex] == 2)
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903
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

<<<<<<< HEAD
    idzdoxy((2*szerokosc-10)/ 2, wysokosc / 2 );
    std::cout<<"GAME OVER" ;
    idzdoxy((2*szerokosc-21)/ 2, wysokosc / 2 +1);
    std::cout<< char(186) <<"  Press ENTER to Quit";
=======
    idzdoxy((2 * szerokosc - 9) / 2, wysokosc / 2);
    std::cout << "GAME OVER" << std::endl;
    std::cout << char(186) << "  Press ENTER to Quit";
>>>>>>> 40fb977a74463718ca40ab7f9071419a93484903

    getch();
}
