#include <iostream>
#include <conio.h> // Wymagane do obsługi funkcji getch()

enum class MenuOption {
    Play,
    HighScores,
    Quit
};

// Funkcja wyświetlająca menu główne i zwracająca wybraną opcję
MenuOption showMainMenu() {
    char userInput;
    MenuOption selectedOption = MenuOption::Play;

    while (true) {
        system("cls"); // Wyczyść ekran (Windows)
        std::cout << "=== MENU GLOWNE ===\n";
        std::cout << "1. Rozpocznij gre\n";
        std::cout << "2. Najlepsze wyniki\n";
        std::cout << "3. Wyjscie\n";
        std::cout << "Wybierz opcje: ";

        userInput = _getch(); // Pobierz pojedynczy klawisz

        switch (userInput) {
            case '1':
                selectedOption = MenuOption::Play;
                break;
            case '2':
                selectedOption = MenuOption::HighScores;
                break;
            case '3':
                selectedOption = MenuOption::Quit;
                break;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                continue; // Powróć do początku pętli
        }

        break; // Zakończ pętlę, jeśli wprowadzono prawidłowy wybór
    }

    return selectedOption;
}

int main() {
    MenuOption selectedOption = showMainMenu();

    switch (selectedOption) {
        case MenuOption::Play:
            std::cout << "Rozpoczynamy gre!\n";
            // Kod obsługujący rozpoczęcie gry Snake
            break;
        case MenuOption::HighScores:
            std::cout << "Wyświetlamy najlepsze wyniki!\n";
            // Kod obsługujący wyświetlanie najlepszych wyników
            break;
        case MenuOption::Quit:
            std::cout << "Do widzenia!\n";
            // Kod obsługujący wyjście z gry
            break;
    }

    return 0;
}
