/********************************************************************************* 
 * ** Author: Jed Piezas
 * ** Date: September 23 2018
 * ** Description:  Asks the user to enter an integer number of cents from 0 to 99
 * **               and outputs how many of each type of coin would represent that
 * **               that amount with the fewest total number of coins.
 * *******************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    const int VALUE_OF_QUARTERS = 25;
    const int VALUE_OF_DIMES = 10;
    const int VALUE_OF_NICKELS = 5;
    const int VALUE_OF_PENNIES = 1;
    int totalCents;
    int remainder;
    int quarters;
    int dimes;
    int nickels;
    int pennies;

    cout << "Please enter an amount in cents less than a dollar." << endl;
    cin >> totalCents;
    
    quarters = totalCents / VALUE_OF_QUARTERS;
    remainder = totalCents % VALUE_OF_QUARTERS;
    
    dimes = remainder / VALUE_OF_DIMES;
    remainder = remainder % VALUE_OF_DIMES;

    nickels = remainder / VALUE_OF_NICKELS;
    remainder = remainder % VALUE_OF_NICKELS;

    pennies = remainder / VALUE_OF_PENNIES;
    
    cout << "Your change will be:" << endl;
    cout << "Q: " << quarters << endl;
    cout << "D: " << dimes << endl;
    cout << "N: " << nickels << endl;
    cout << "P: " << pennies << endl;

    return 0; 
}
