int szybkoscRuchuWeza;
int tempoPojawianiaSieJedzenia;

// Funkcja ustawiająca parametry gry zależnie od poziomu trudności
void ustawParametryGry() {
    switch (poziomTrudnosci) {
        case 1:
            szybkoscRuchuWeza = 200;  // np. wartość w milisekundach
            tempoPojawianiaSieJedzenia = 5;  // np. co 5 sekund
            break;
        case 2:
            szybkoscRuchuWeza = 150;
            tempoPojawianiaSieJedzenia = 3;
            break;
        case 3:
            szybkoscRuchuWeza = 100;
            tempoPojawianiaSieJedzenia = 2;
            break;
        default:
            break;
    }
}

// W sekcji głównej pętli gry
while (pole[wonsz.head_y()][wonsz.head_x()] != 2 ) {
// Ustawienie parametrów gry zależnie od poziomu trudności
ustawParametryGry();

// Reszta kodu gry...

Sleep(szybkoscRuchuWeza);  // Opóźnienie ruchu węża

// Wywołanie funkcji losującej położenie jedzenia z odpowiednim tempem
if (licznikCzasu % (tempoPojawianiaSieJedzenia * 1000 / szybkoscRuchuWeza) == 0) {
// Wylosowanie położenia jedzenia
}

// Inkrementacja licznika czasu
licznikCzasu++;
}

int szybkoscRuchuWeza;
int tempoPojawianiaSieJedzenia;

// Funkcja ustawiająca parametry gry zależnie od poziomu trudności
void ustawParametryGry() {
    switch (poziomTrudnosci) {
        case 1:
            szybkoscRuchuWeza = 200;  // np. wartość w milisekundach
            tempoPojawianiaSieJedzenia = 5;  // np. co 5 sekund
            break;
        case 2:
            szybkoscRuchuWeza = 150;
            tempoPojawianiaSieJedzenia = 3;
            break;
        case 3:
            szybkoscRuchuWeza = 100;
            tempoPojawianiaSieJedzenia = 2;
            break;
        default:
            break;
    }
}

// W sekcji głównej pętli gry
while (pole[wonsz.head_y()][wonsz.head_x()] != 2 ) {
// Ustawienie parametrów gry zależnie od poziomu trudności
ustawParametryGry();

// Reszta kodu gry...

Sleep(szybkoscRuchuWeza);  // Opóźnienie ruchu węża

// Wywołanie funkcji losującej położenie jedzenia z odpowiednim tempem
if (licznikCzasu % (tempoPojawianiaSieJedzenia * 1000 / szybkoscRuchuWeza) == 0) {
// Wylosowanie położenia jedzenia
}

// Inkrementacja licznika czasu
licznikCzasu++;
}
