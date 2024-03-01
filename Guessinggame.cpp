#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int MAX_GUESSES = 5; // Maximum number of guesses allowed
    const int RANGE = 10; // Range of numbers to guess
    int secretNumber;
    int guess;
    int numGuesses = 0;
    char playAgain;

    // Seed the random number generator
    srand(time(0));

    // Generate the secret number
    secretNumber = rand() % RANGE + 1;

    do {
        cout << "Guess the secret number (between 1 and " << RANGE << "): ";
        cin >> guess;
        numGuesses++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the secret number in " << numGuesses << " guesses!\n";
            cout << "You win!\n";
            break;
        } else {
            cout << "Sorry, that's incorrect.\n";
            if (numGuesses < MAX_GUESSES) {
                cout << "You have " << MAX_GUESSES - numGuesses << " guesses left.\n";
            } else {
                cout << "Game over! You've run out of guesses.\n";
                cout << "The secret number was: " << secretNumber << endl;
                cout << "Would you like to play again? (y/n): ";
                cin >> playAgain;
                if (playAgain == 'y' || playAgain == 'Y') {
                    // Generate a new secret number
                    secretNumber = rand() % RANGE + 1;
                    numGuesses = 0; // Reset the number of guesses
                } else {
                    break; // Exit the game
                }
            }
        }
    } while (numGuesses < MAX_GUESSES);

    return 0;
}
