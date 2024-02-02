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
    srand(time(0));

    int targetNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Zgadnij liczbę z zakresu 1-100.\n";

    do {
        cout << "Podaj swoją próbę: ";
        cin >> guess;
        attempts++;

        if (guess == targetNumber) {
            cout << "Brawo! Zgadłeś liczbę " << targetNumber << " po " << attempts << " próbach.\n";
            break;
        } else if (guess < targetNumber) {
            cout << "Za mało. Spróbuj ponownie.\n";
        } else {
            cout << "Za dużo. Spróbuj ponownie.\n";
        }
    } while (true);
}

// Ping Pong
void playPingPong() {
    const int width = 20;
    const int height = 10;

    int ballX, ballY, paddle1Y, paddle2Y;
    int ballSpeedX, ballSpeedY;
    bool exitGame = false;

    auto setup = [&]() {
        ballX = width / 2;
        ballY = height / 2;
        paddle1Y = height / 2 - 2;
        paddle2Y = height / 2 - 2;
        ballSpeedX = -1;
        ballSpeedY = 0;
    };

    auto draw = [&]() {
        system("clear");

        for (int i = 0; i < width + 2; i++)
            cout << "-";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "|";
                if (i == ballY && j == ballX)
                    cout << "O"; // Ball
                else if (i >= paddle1Y && i < paddle1Y + 4 && j == 1)
                    cout << "#"; // Left Paddle
                else if (i >= paddle2Y && i < paddle2Y + 4 && j == width - 2)
                    cout << "#"; // Right Paddle
                else
                    cout << " ";
                if (j == width - 1)
                    cout << "|";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "-";
        cout << endl;
    };

    auto input = [&]() {
        char ch;
        cin >> ch;

        switch (ch) {
            case 'w':
                paddle1Y = max(0, paddle1Y - 1);
                break;
            case 's':
                paddle1Y = min(height - 4, paddle1Y + 1);
                break;
            case 'q':
                exitGame = true;
                break;
        }
    };

    auto update = [&]() {
        ballX += ballSpeedX;
        ballY += ballSpeedY;

        if (ballY <= 0 || ballY >= height - 1)
            ballSpeedY = -ballSpeedY;

        if (ballX == 2 && ballY >= paddle1Y && ballY < paddle1Y + 4)
            ballSpeedX = -ballSpeedX;

        if (ballX == width - 3 && ballY >= paddle2Y && ballY < paddle2Y + 4)
            ballSpeedX = -ballSpeedX;

        if (ballX <= 0 || ballX >= width - 1) {
            setup();
        }
    };

    auto gameLoop = [&]() {
        while (!exitGame) {
            draw();
            input();
            update();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    };

    setup();
    gameLoop();
}

// Tetris
void playTetris() {
    const int width = 10;
    const int height = 20;

    vector<vector<char>> board(height, vector<char>(width, ' '));
    int currentPiece[4][4];
    int currentX, currentY;
    bool exitGame = false;

    auto init = [&]() {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                board[i][j] = ' ';

        currentX = width / 2;
        currentY = 0;

        // Default Tetris piece (L-shaped)
        currentPiece[0][0] = 1; currentPiece[0][1] = 1; currentPiece[0][2] = 1; currentPiece[0][3] = 1;
    };

    auto draw = [&]() {
        system("clear");

        for (int i = 0; i < width + 2; i++)
            cout << "-";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "|";
                if (i >= currentY && i < currentY + 4 && j >= currentX && j < currentX + 4 && currentPiece[i - currentY][j - currentX] == 1)
                    cout << "#"; // Tetris piece
                else
                    cout << board[i][j];
                if (j == width - 1)
                    cout << "|";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "-";
        cout << endl;
    };

    auto isValidMove = [&]() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (currentPiece[i][j] == 1 && (board[i + currentY][j + currentX] != ' ' || j + currentX < 0 || j + currentX >= width || i + currentY >= height))
                    return false;
        return true;
    };

    auto rotatePiece = [&]() {
        int temp[4][4];

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                temp[i][j] = currentPiece[i][j];

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                currentPiece[i][j] = temp[3 - j][i];
    };

    auto input = [&]() {
        char ch;
        cin >> ch;

        switch (ch) {
            case 'a':
                currentX--;
                if (!isValidMove()) currentX++;
                break;
            case 'd':
                currentX++;
                if (!isValidMove()) currentX--;
                break;
            case 's':
                currentY++;
                if (!isValidMove()) currentY--;
                break;
            case 'w':
                rotatePiece();
                if (!isValidMove()) rotatePiece();
                break;
            case 'q':
                exitGame = true;
                break;
        }
    };

    auto update = [&]() {
        currentY++;

        if (!isValidMove()) {
            currentY--;

            // Place the piece on the board
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    if (currentPiece[i][j] == 1)
                        board[i + currentY][j + currentX] = '#';

            // Check for completed rows and clear them
            for (int i = height - 1; i >= 0; i--) {
                bool isRowFull = true;
                for (int j = 0; j < width; j++) {
                    if (board[i][j] == ' ') {
                        isRowFull = false;
                        break;
                    }
                }
                if (isRowFull) {
                    for (int k = i; k > 0; k--)
                        for (int j = 0; j < width; j++)
                            board[k][j] = board[k - 1][j];
                    for (int j = 0; j < width; j++)
                        board[0][j] = ' ';
                }
            }

            // Generate a new piece
            init();
        }
    };

    auto gameLoop = [&]() {
        while (!exitGame) {
            draw();
            input();
            update();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    };

    init();
    gameLoop();
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
