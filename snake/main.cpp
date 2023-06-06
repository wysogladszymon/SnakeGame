#include "include/snake.hpp"

#include <cstdlib>
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
    srand(time(NULL)); // reset generatora liczb pseudolosowych
    system("Cls"); //oczyszczenie ekranu

    Plansza plansza(30,30);
    plansza.rysuj();



}
