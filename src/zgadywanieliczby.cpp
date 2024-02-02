#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Initialize the random number generator
    srand(time(0));

    // Generate a random number to guess between 1 and 100
    int numberToGuess = rand() % 100 + 1;

    int guess;
    int numberOfAttempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        numberOfAttempts++;

        if (guess < numberToGuess) {
            cout << "The number is too low. Try again.\n";
        } else if (guess > numberToGuess) {
            cout << "The number is too high. Try again.\n";
        } else {
            cout << "Congratulations! You guessed the number in " << numberOfAttempts << " attempts.\n";
        }

    } while (guess != numberToGuess);

    return 0;
}
