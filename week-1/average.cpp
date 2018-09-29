/********************************************************************************* 
 * ** Author: Jed Piezas
 * ** Date: September 23 2018
 * ** Description:  Asks the user to input five numbers and then prints out the 
 * **               average of those numbers,
 * *******************************************************************************/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    double num1;
    double num2;
    double num3;
    double num4;
    double num5;
    double avgNum;    
    
    cout << "Please enter five numbers." << endl;

    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    avgNum = (num1 + num2 + num3 + num4 + num5)/5;

    cout << "The average of those numbers is:" << endl;
    cout << avgNum << endl;

    return 0;
}
