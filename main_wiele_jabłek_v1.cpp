#include "include/snake.hpp"
#include <cstdlib>
#include <string>
#include <vector>

struct Jedzenie {
    int x;
    int y;
};

int main() {
    int a, b;
    int wysokosc;
    int szerokosc;

    std::vector<Jedzenie> jablka; // wektor przechowujący jabłka
    int jedzenie_count = 1; // liczba początkowych jabłek (domyślnie: 1)

    int jedzeniex, jedzeniey;
    char klawisz;
    char kierunek = 'p'; // p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int> historiay;
    int level; // zmienna ustalająca poziom gry

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    // menu kontekstowe wyboru przez gracza odpowiednich parametrów
    std::cout << "Podaj wymiar planszy miedzy 10, a 25  " << std::endl;
    std::cin >> szerokosc;

    // zabezpieczenie przed za malym wymiarem
    if (szerokosc < 10) {
        szerokosc = 10;
    }

    // zabezpieczenie przed zbyt duzym wymiarem
    if (szerokosc > 25) {
        szerokosc = 25;
    }
    wysokosc = szerokosc;

    // poziom gry
    std::cout << "Podaj w skali 1-3 poziom trudnosci  ";
    std::cin >> level;

    if (level < 1)
        level = 1;
    if (level > 3)
        level = 3;

    // zmienienie proporcjonalnosci poziomow
    level += 2;

    int pole[wysokosc][szerokosc]; // 0 - puste pole , 1 - jedzenie, 2 - waz
    // ustawienie tablicy samymi pustymi polami
    for (int i = 0; i < wysokosc; i++)
        for (int j = 0; j < szerokosc; j++)
            pole[i][j] = 0;

    // oczyszczenie ekranu
    system("Cls");

    Plansza plansza(szerokosc, wysokosc);
    plansza.rysuj();

    a = losowanie(szerokosc);
    b = losowanie(wysokosc);

    // inicjalizacja
    Snake wonsz(1, a, b, a, b);

    // wybór liczby początkowych jabłek
    std::cout << "Wybierz liczbe poczatkowych jablek: (1 - jedno jablko, 2 - wiele jablek) ";
    std::cin >> jedzenie_count;

    if (jedzenie_count < 1)
        jedzenie_count = 1;
    if (jedzenie_count > 2)
        jedzenie_count = 2;

    // losowanie poczatkowych pol jabłek
    for (int i = 0; i < jedzenie_count; i++) {
        do {
            Jedzenie nowe_jedzenie;
            nowe_jedzenie.x = losowanie(szerokosc);
            nowe_jedzenie.y = losowanie(wysokosc);
            jablka.push_back(nowe_jedzenie);
        } while (jablka[i].x == a && jablka[i].y == b);
    }

    // narysowanie początkowych jabłek
    for (const auto& jedzenie : jablka) {
        idzdoxy(jedzenie.x * 2 + 1, jedzenie.y + 1);
        std::cout << 'x';
    }

    // narysowanie wyniku
    idzdoxy(2, wysokosc + 2);
    std::cout << "SCORE: " << wonsz.size();

    // petla gry
    while (pole[wonsz.head_y()][wonsz.head_x()] != 2) {
        // narysowanie glowy oraz ustawienie pola w tablicy, aby oznaczyc lokalizacje weza
        pole[wonsz.head_y()][wonsz.head_x()] = 2;
        wonsz.rysuj_glowe();

        // sprawdzenie, czy wąż zjadł jakieś jabłko
        for (int i = 0; i < jablka.size(); i++) {
            if (pole[jablka[i].y][jablka[i].x] == 2) {
                // ustawienie wyniku
                idzdoxy(9, wysokosc + 2);
                std::cout << wonsz.size();

                // usuniecie zjedzonego jabłka
                jablka.erase(jablka.begin() + i);

                // aktualizacja rozmiaru węża
                wonsz.size(wonsz.size() + 1);

                // losowanie nowego pola jedzenia
                do {
                    Jedzenie nowe_jedzenie;
                    nowe_jedzenie.x = losowanie(szerokosc);
                    nowe_jedzenie.y = losowanie(wysokosc);
                    jablka.push_back(nowe_jedzenie);
                } while (pole[jablka[i].y][jablka[i].x] == 2);

                for (const auto& jedzenie : jablka) {
                    idzdoxy(jedzenie.x * 2 + 1, jedzenie.y + 1);
                    std::cout << 'x';
                }

                break;
            }
        }

        Sleep(1000 / level);

        // zapisanie w histori petli wspolrzednych glowy
        historiax.push_back(wonsz.head_x());
        historiay.push_back(wonsz.head_y());

        // wpisanie i usuniecie ogona
        wonsz.tail_x(historiax[historiax.size() - wonsz.size()]);
        wonsz.tail_y(historiay[historiay.size() - wonsz.size()]);
        wonsz.usun_ogon();
        pole[wonsz.tail_y()][wonsz.tail_x()] = 0;

        // uzaeleznienie kierunku w zaleznosci od przycisku
        if (_kbhit()) {
            // dodanie pauzy;
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

        // poruszanie w zaleznosci od kierunku
        switch (kierunek) {
            case 'g':
                wonsz.head_both(wonsz.head_x(), wonsz.head_y() - 1);
                break;
            case 'd':
                wonsz.head_both(wonsz.head_x(), wonsz.head_y() + 1);
                break;
            case 'p':
                wonsz.head_both(wonsz.head_x() + 1, wonsz.head_y());
                break;
            case 'l':
                wonsz.head_both(wonsz.head_x() - 1, wonsz.head_y());
                break;
        }

        // ustawienie wspolrzednych weza, aby miescily sie w polu gry
        wonsz.head_x((wonsz.head_x() + szerokosc) % szerokosc);
        wonsz.head_y((wonsz.head_y() + wysokosc) % wysokosc);
    }

    idzdoxy((2 * szerokosc - 12) / 2, wysokosc / 2);
    std::cout << "GAME OVER" << std::endl;
    std::cout << char(186) << "  Press ENTER to Quit";

    getch();
}