#include "include/snake.hpp"
#include "include/function.hpp"

#include <cstdlib>
#include <string>


int main() {
    int a,b;
    int wysokosc;
    int szerokosc;

    int jedzeniex, jedzeniey;
    char klawisz ;
    char kierunek = 'p';                //p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int>historiay;
    int level;                          //zmienna ustalająca poziom gry

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    //ustawienie tablicy samymi pustymi polami
    for (int i = 0; i < wysokosc; i++)
        for (int j = 0; j < szerokosc; j++)
            pole[i][j] = 0;

    //oczyszczenie ekranu
    system("Cls");

    Plansza plansza(szerokosc, wysokosc);
    plansza.rysuj();

    a = losowanie(szerokosc);
    b = losowanie(wysokosc);
    // inicjalizacja i losowanie poczatkowego ustawienia węża
    Snake wonsz(1, a, b, a, b);


    //losowanie poczatkowego pola jedzenia
    do {
        jedzeniex = losowanie(szerokosc);
        jedzeniey = losowanie(wysokosc);
    } while (jedzeniex == a && jedzeniey == b);

    idzdoxy(jedzeniex * 2 + 1, jedzeniey + 1);
    std::cout << 'x';

    //narysowanie wyniku
    idzdoxy(2, wysokosc + 2);
    std::cout << "SCORE: " << wonsz.get_size();

    //petla gry
    while (pole[wonsz.get_head_Y()][wonsz.get_head_X()] != 2) {
        //narysowanie glowy oraz ustawienie pola w tablicy, aby oznaczyc lokalizacje weza
        pole[wonsz.get_head_Y()][wonsz.get_head_X()] = 2;
        wonsz.rysuj_glowe();

        //instrukcja co zrobic gdy waz zje jedzenie
        if (pole[jedzeniey][jedzeniex] == 2)
           wonsz.size(wonsz.size() + 1);


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
        if (_kbhit()) {
             //dodanie pauzy;
            klawisz = _getch();
            if (klawisz == 80 || klawisz == 112)
                klawisz = _getch();
            switch (klawisz) {
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


               //instrukcja gdy waz zje jedzenie
        if (pole[jedzeniey][jedzeniex] == 2)
        {
            //ustawienie wyniku
            idzdoxy(9, wysokosc + 2);
            std::cout<<wonsz.size();

            //losowanie nowego pola jedzenia
            while (pole[jedzeniey][jedzeniex] == 2)
            {
                jedzeniex = losowanie(szerokosc);
                jedzeniey = losowanie(wysokosc);
            }
            idzdoxy(jedzeniex * 2 + 1 , jedzeniey+1);
            std::cout<<'x';

        }

    }

    idzdoxy((2 * szerokosc - 9) / 2, wysokosc / 2);
    std::cout << "GAME OVER" << std::endl;
    std::cout << char(186) << "  Press ENTER to Quit";

    getch();
}
