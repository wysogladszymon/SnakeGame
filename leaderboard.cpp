#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Wynik {
    std::string nazwaGracza;
    int wynik;
};

void zapiszWynikDoLeaderboardu(const std::string& nazwaGracza, int wynik) {
    std::ofstream plik("leaderboard.txt", std::ios::app);
    if (!plik) {
        std::cout << "Błąd podczas otwierania pliku leaderboardu." << std::endl;
        return;
    }

    plik << nazwaGracza << " " << wynik << std::endl;
    plik.close();
}

std::vector<Wynik> wczytajLeaderboard() {
    std::vector<Wynik> wyniki;
    std::ifstream plik("leaderboard.txt");
    if (!plik) {
        std::cout << "Brak pliku leaderboardu." << std::endl;
        return wyniki;
    }

    std::string nazwaGracza;
    int wynik;
    while (plik >> nazwaGracza >> wynik) {
        wyniki.push_back({nazwaGracza, wynik});
    }

    plik.close();
    return wyniki;
}

void wyswietlLeaderboard(const std::vector<Wynik>& wyniki) {
    std::cout << "=== LEADERBOARD ===" << std::endl;
    if (wyniki.empty()) {
        std::cout << "Brak wyników do wyświetlenia." << std::endl;
        return;
    }

    int miejsce = 1;
    for (const auto& wynik : wyniki) {
        std::cout << miejsce << ". " << wynik.nazwaGracza << " - " << wynik.wynik << std::endl;
        miejsce++;
    }
}

bool porownajWyniki(const Wynik& wynik1, const Wynik& wynik2) {
    return wynik1.wynik > wynik2.wynik;
}

void sortujLeaderboard(std::vector<Wynik>& wyniki) {
    std::sort(wyniki.begin(), wyniki.end(), porownajWyniki);
}

int main() {
    std::vector<Wynik> leaderboard = wczytajLeaderboard();
    sortujLeaderboard(leaderboard);
    wyswietlLeaderboard(leaderboard);

    std::string nazwaGracza;
    int wynik;

    std::cout << "Podaj swoje imię: ";
    std::cin >> nazwaGracza;
    std::cout << "Podaj swój wynik: ";
    std::cin >> wynik;

    zapiszWynikDoLeaderboardu(nazwaGracza, wynik);

    leaderboard = wczytajLeaderboard();
    sortujLeaderboard(leaderboard);
    wyswietlLeaderboard(leaderboard);

    return 0;
}
