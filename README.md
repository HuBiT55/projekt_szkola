# Game Hub - Terminalowa Kolekcja Mini-gier
projekt szkolny

# Opis projektu:
Game Hub to terminalowa aplikacja zawierająca kilka mini-gier. Gracz ma możliwość wyboru spośród różnorodnych gier, takich jak Kółko i krzyżyk, Zgadywanie liczby, Ping Pong oraz Tetris. Aplikacja została napisana w języku C++ i oferuje prosty interfejs tekstowy do rozrywki.

# Struktura projektu:
Projekt składa się z kilku modułów, z których każdy odpowiada za inną grę. Każdy moduł posiada własne funkcje sterujące logiką gry, interakcją z graczem i aktualizacją stanu gry.

- main.cpp: Plik główny, zawiera menu główne i logikę wyboru gry.
- kolko_krzyzyk.cpp: Moduł gry w Kółko i krzyżyk.
- zgadywanie_liczby.cpp: Moduł gry w Zgadywanie liczby.
- ping_pong.cpp: Moduł gry w Ping Pong.
- tetris.cpp: Moduł gry w Tetris.


# Zależności:
Aplikacja korzysta z podstawowych funkcji języka C++, nie wymaga dodatkowych bibliotek.
Kompatybilność: Aplikacja została przetestowana na systemie Linux.
Instrukcja obsługi:
Uruchomienie aplikacji spowoduje pojawienie się menu głównego z listą dostępnych gier.
Wybierz numer odpowiadający interesującej cię grze.
Postępuj zgodnie z instrukcjami wyświetlanymi na ekranie.

## Opis gier:

# 1. Kółko i krzyżyk:

Gracz zmierza się z komputerem, postaw kółko lub krzyżyk w odpowiednim miejscu, staraj się wygrać.

Instrukcja:
Wybierz pole, w którym chcesz postawić swój znak (kółko lub krzyżyk).
Podaj numer wiersza (1-3) i kolumny (1-3), aby umieścić swój znak.

# 2. Zgadywanie liczby:

Program losuje liczbę z zakresu 1-100, a gracz musi odgadnąć wylosowaną wartość.

Instrukcja:
Podaj swoją propozycję liczby z zakresu 1-100.
System poinformuje cię, czy twoja liczba jest za duża, za mała czy dokładna.
Celem jest odgadnięcie liczby za jak najmniejszą liczbę prób.

# 3. Ping Pong:

Steruj paletką i odbijaj piłkę, staraj się unikać utraty punktów.

Instrukcja:
Steruj paletką w górę ('w') i w dół ('s').
Unikaj, aby piłka nie minęła twojej paletki.
Gra zakończy się, gdy piłka minie twoją paletkę.

# 4.Tetris:

Umieść spadające kształty tak, aby wypełnić całą linię i zdobyć punkty.

Instrukcja:
Sterowanie kształtem za pomocą klawiszy:
'a' - ruch w lewo,
'd' - ruch w prawo,
's' - opadanie w dół,
'w' - obrót kształtu.
Celem jest ułożenie kształtów w taki sposób, aby zapełnić całe linie i zdobyć punkty.


# Dodatkowe uwagi:
W grach Ping Pong i Tetris można korzystać z klawisza 'q' w celu powrotu do menu głównego w dowolnym momencie.
Każda gra korzysta z funkcji obsługi wejścia, co umożliwia interakcję z graczem.
Zastosowano komentarze w języku polskim i angielskim zgodnie z wymaganiami projektu.

