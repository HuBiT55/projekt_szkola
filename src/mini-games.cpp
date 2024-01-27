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

struct Point {
    int x;
    int y;
};

// Tetris
void playTetris() {
    cout << "Witaj w Tetrisie!\n";
    cout << "Instrukcja:\n";
    cout << "1. Użyj klawiszy 'a' i 'd' do poruszania klockiem w lewo i w prawo.\n";
    cout << "2. Użyj klawisza 's' do przyspieszenia opadania klocka.\n";
    cout << "3. Użyj klawiszy 'w' do obracania klocka.\n";
    cout << "4. Graj dopóki klocki nie osiągną góry planszy.\n";
    cout << "5. Powodzenia!\n";

    cout << "Naciśnij Enter, aby rozpocząć...";
    cin.ignore(); // Oczekaj na wciśnięcie Enter

    const int BOARD_WIDTH = 10;
    const int BOARD_HEIGHT = 20;

    vector<vector<char>> board(BOARD_HEIGHT, vector<char>(BOARD_WIDTH, ' '));
    vector<Point> currentPiece;

    auto isValidMove = [&](int dx, int dy) {
        for (const Point& point : currentPiece) {
            int nx = point.x + dx;
            int ny = point.y + dy;

            if (nx < 0 || nx >= BOARD_WIDTH || ny < 0 || ny >= BOARD_HEIGHT || board[ny][nx] != ' ') {
                return false;
            }
        }
        return true;
    };

    auto placePiece = [&]() {
        for (const Point& point : currentPiece) {
            board[point.y][point.x] = '#';
        }
        currentPiece.clear();
    };

    auto clearLines = [&]() {
        for (int i = BOARD_HEIGHT - 1; i >= 0; --i) {
            if (all_of(board[i].begin(), board[i].end(), [](char c) { return c == '#'; })) {
                board.erase(board.begin() + i);
                board.insert(board.begin(), vector<char>(BOARD_WIDTH, ' '));
            }
        }
    };

    auto moveLinesDown = [&](int row) {
        for (int i = row; i > 0; --i) {
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                board[i][j] = board[i - 1][j];
            }
        }
    };

    auto isLineFull = [&](int row) {
        return all_of(board[row].begin(), board[row].end(), [](char c) { return c == '#'; });
    };

    auto clearLine = [&](int row) {
        fill(board[row].begin(), board[row].end(), ' ');
    };

    auto generateRandomPiece = [&]() {
        return vector<Point>{{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    };

    auto update = [&]() {
        if (isValidMove(0, 1)) {
            for (Point& point : currentPiece) {
                point.y += 1;
            }
        } else {
            placePiece();
            clearLines();
            currentPiece = generateRandomPiece();
        }
    };

    auto drawBoard = [&]() {
        for (int i = 0; i < BOARD_HEIGHT; ++i) {
            for (int j = 0; j < BOARD_WIDTH; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    };

    while (true) {
        drawBoard();
        update();
        this_thread::sleep_for(chrono::milliseconds(500)); // Przerwa między krokami
        system("clear");
    }
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