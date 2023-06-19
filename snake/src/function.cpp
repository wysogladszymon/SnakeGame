#include "../include/function.hpp"


void idzdoxy(int x, int y) {
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = short(x);
    dwPos.Y = short(y);

    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

int losowanie(int gora, int dol) {
    return std::rand() % (gora - dol) + dol;
}

