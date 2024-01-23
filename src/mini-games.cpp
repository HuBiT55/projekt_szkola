#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Kółko i krzyżyk
void drawBoard(char board[3][3]) {
    // implementacja funkcji...
}

bool checkWin(char board[3][3], char player) {
    // implementacja funkcji...
}

bool isBoardFull(char board[3][3]) {
    // implementacja funkcji...
}

void playTicTacToe() {
    // implementacja funkcji...
}

// Zgadywanie liczby
void playNumberGuessingGame() {
    // implementacja funkcji...
}

// Ping Pong
void playPingPong() {
    // implementacja funkcji...
}

// Tetris
void playTetris() {
    // implementacja funkcji...
}

// Wspólna funkcja dla gier
void clearScreen() {
    system("clear");
}

int main() {
    int choice;

    do {
        cout << "\n===== Game Hub =====\n";
        cout << "1. Kółko i krzyżyk\n";
        cout << "2. Zgadywanie liczby\n";
        cout << "3. Ping Pong\n";
        cout << "4. Tetris\n";
        cout << "5. Wyjście\n";
        cout << "Wybierz grę (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Kółko i krzyżyk
                clearScreen();
                playTicTacToe();
                break;
            case 2:
                // Zgadywanie liczby
                clearScreen();
                playNumberGuessingGame();
                break;
            case 3:
                // Ping Pong
                clearScreen();
                playPingPong();
                break;
            case 4:
                // Tetris
                clearScreen();
                playTetris();
                break;
            case 5:
                cout << "Dziękujemy za korzystanie z Game Hub. Do zobaczenia!\n";
                break;
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
        }
    } while (choice != 5);

    return 0;
}
