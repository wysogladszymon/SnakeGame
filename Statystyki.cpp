#include <iostream>
#include <fstream>
#include <string>

void wyswietlStatystyki() {
    std::ifstream plik("statystyki.txt");
    if (plik.is_open()) {
        std::string linia;
        while (getline(plik, linia)) {
            std::cout << linia << std::endl;
        }
        plik.close(); 
    } else {
        std::cout << "Nie można otworzyć pliku ze statystykami." << std::endl;
    }
}

void wyswietlOsiagniecia() {
    std::ifstream plik("osiagniecia.txt");
    if (plik.is_open()) {
        std::string linia;
        while (getline(plik, linia)) {
            std::cout << linia << std::endl;
        }
        plik.close();
    } else {
        std::cout << "Nie można otworzyć pliku z osiągnięciami." << std::endl;
    }
}

void zapiszStatystyki(int wynik) {
    std::ofstream plik("statystyki.txt", std::ios_base::app);
    if (plik.is_open()) {
        plik << "Wynik: " << wynik << std::endl;
        plik.close();
    } else {
        std::cout << "Nie można zapisać statystyk." << std::endl;
    }
}

void odblokujOsiagniecie(const std::string& nazwa) {
    std::ofstream plik("osiagniecia.txt", std::ios_base::app);
    if (plik.is_open()) {
        plik << "Odblokowano osiągnięcie: " << nazwa << std::endl;
        plik.close();
    } else {
        
        
        std::cout << "Nie można zapisać osiągnięcia." << std::endl;
    }
}

