/********************************************************************************* 
 * ** Author: Jed Piezas
 * ** Date: September 23 2018
 * ** Description:  Asks the user to enter a temperature in Celsius and then
 * **               convers it into Fahrenheit.
 * *******************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    double celsTemp;
    double fahrTemp;

    cout << "Please enter a Celsius temperature." << endl;
    cin >> celsTemp;

    fahrTemp = ((9.0/5.0) * celsTemp) + 32.0;

    cout << "The equivalent Fahrenheit temperature is:" << endl;
    cout << fahrTemp << endl;

    return 0;
}
