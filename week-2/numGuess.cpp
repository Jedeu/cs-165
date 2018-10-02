/********************************************************************************* 
 *Author: Jed Piezas
 *Date: October 1 2018
 *Description:  Asks the user to enter a number to guess. Then it asks another
 *              user (presumably) to make a guess of the other player's number
 *              If the guess is too high, it will tell the user the guess is too high.
 *              If the guess is too low, it will tell the user the guess is too low.
 *              When the guess is finally correct, it will inform the user how many
 *              tries it took.
 *********************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int numToGuess;
    
    // Output the number to guess and save it
    cout << "Enter the number for the player to guess." << endl;
    cin >> numToGuess;
    
    // Have the other player start guessing numbers
    cout << "Enter your guess." << endl;
    
    int numOfGuesses = 0;
    int guessedNum;
    
    // Keep taking in guesses until the guess is right
    while ( guessedNum != numToGuess ) {
        cin >> guessedNum;
        // Increment the guess by 1 for every attempt
        numOfGuesses += 1;
        // Give a hint to the user depending on the guess
        if ( guessedNum > numToGuess ) {
            cout << "Too high - try again." << endl;
        } else if ( guessedNum < numToGuess ) {
            cout << "Too low - try again." << endl;
        }
    }
    
    // Output the number of attempts made
    if ( numOfGuesses > 1 ) {
        cout << "You guessed it in " << numOfGuesses << " tries." << endl;
    } else {
        // Fix the program's grammar :)
        cout << "You guessed it in 1 try." << endl;
    }

    return 0;
}
