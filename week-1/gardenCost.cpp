/********************************************************************************* 
 * ** Author: Jed Piezas
 * ** Date: September 23 2018
 * ** Description:  Asks the user for the cost of soil, the flower seeds, and
 * **               the fence. Outputs the total cost.
 * *******************************************************************************/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    double soilCost;
    double seedCost;
    double fenceCost;
    double totalCost;

    cout << "What does the soil cost?" << endl;
    cin >> soilCost;
    cout << "What do the flower seeds cost?" << endl;
    cin >> seedCost;
    cout << "What does the fence cost?" << endl;
    cin >> fenceCost;

    totalCost = soilCost + seedCost + fenceCost;

    cout << "The total cost is " << totalCost << endl;    
    
    return 0; 
}
