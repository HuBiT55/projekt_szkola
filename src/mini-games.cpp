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
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Poziome
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Pionowe
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Przekątna
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Przekątna odwrotna
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false; // Istnieje puste pole
        }
    }
    return true; // Plansza jest pełna
}

// Funkcja do czyszczenia ekranu
void clearScreen() {
    system("clear");
}

void playTicTacToe() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';

    do {
        drawBoard(board);

        int row, col;
        cout << "Gracz " << currentPlayer << ", podaj rząd (1-3) i kolumnę (1-3): ";
        cin >> row >> col;

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(board, currentPlayer)) {
                drawBoard(board);
                cout << "Gracz " << currentPlayer << " wygrywa!\n";
                break;
            }

            if (isBoardFull(board)) {
                drawBoard(board);
                cout << "Remis!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Zamień gracza
        } else {
            cout << "Nieprawidłowe pole. Spróbuj ponownie.\n";
        }
    } while (true);
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
        cout << "\n===== GameHub =====\n";
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