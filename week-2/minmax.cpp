/********************************************************************************* Author: Jed Piezas
 * ** Date: October 1 2018
 * ** Description:  Asks the user to enter the number of integers they would
 * **               like to enter. Once all integers are entered, it will output
 *                  the smallest integer and the largest integer
 * *******************************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int numOfIntegers;
    int minValue;
    int maxValue;
    int currentValue;

    // Save the number of integers that the user will enter
    cout << "How many integers would you like to enter?" << endl;
    cin >> numOfIntegers;
    
    // Allow the user to input these integers
    if ( numOfIntegers > 1 ) {
        cout << "Please enter " << numOfIntegers << " integers." << endl;
    } else {
        // Specifications say that we can assume numOfIntegers is an integer >=1
        cout << "Please enter an integer." << endl;
    }
    // Store the first integer as both min and max value to start
    cin >> minValue;
    maxValue = minValue;

    for( int i = 1; i < numOfIntegers; i++ ) {
        // Store input as the number to compare
        cin >> currentValue;
        // Compare current value with min and max
        // Replace min and max value with comparator based on value
        if ( currentValue < minValue ) {
            minValue = currentValue;
        }
        if ( currentValue > maxValue ) {
            maxValue = currentValue;
        }        
    }
    
    // Output the min and max numbers
    cout << "min: " << minValue << endl;
    cout << "max: " << maxValue << endl;
    
    return 0;
}
