#include "include/snake.hpp"

#include <cstdlib>
using namespace std;
void idzdoxy(int x, int y)
{
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = short(x);
    dwPos.Y = short(y);

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

int losowanie(int gora = 10, int dol = 0)
{
    return std::rand()%gora + dol;
}

int main() {
    int wysokosc = 10;
    int szerokosc = 10;
    int pole[wysokosc][szerokosc];      // 0 - puste pole , 1 - jedzenie, 2 - waz
    int jedzeniex, jedzeniey;
    char klawisz;
    char kierunek = 'p';                //p - prawo, l - lewo, g - gora, d - dol
    std::vector<int> historiax;
    std::vector<int>historiay;

    srand(time(nullptr)); // reset generatora liczb pseudolosowych

    Snake wonsz;
    wonsz.set_x(losowanie(szerokosc));
    wonsz.set_y(losowanie(wysokosc)); //losowanie poczatkowego ustawienia węża

    for (int i = 0; i < wysokosc;i++ )
        for(int j = 0; j < szerokosc ; j++)
            pole[i][j] = 0;


    system("Cls"); //oczyszczenie ekranu

    Plansza plansza(szerokosc,wysokosc);
    plansza.rysuj();

    while (pole[wonsz.start_x()][wonsz.start_y()] != 2 )
    {
        pole[wonsz.start_x()][wonsz.start_y()] = 2;
        idzdoxy(wonsz.start_x()*2 +1, wonsz.start_y()+1);
        std::cout<< 'o';

        historiax.push_back(wonsz.start_x());
        historiay.push_back(wonsz.start_y());
        wonsz.set_endx(historiax[historiax.size() - wonsz.size()]);
        wonsz.set_endy(historiay[historiay.size() - wonsz.size()]);     //ustawienie wspolrzednych konca

        do
        {
            jedzeniex = losowanie(szerokosc);
            jedzeniey = losowanie(wysokosc);
        }while (pole[jedzeniey][jedzeniex] == 2);
        idzdoxy(jedzeniex*2+1, jedzeniey+1);
        std::cout<<'x';

    }

    Sleep(1000);

    idzdoxy((2*szerokosc-10)/2, wysokosc + 2);
    std::cout<<"KONIEC GRY";
}
