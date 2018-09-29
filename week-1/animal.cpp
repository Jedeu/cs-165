/********************************************************************************* Author: Jed Piezas
** Date: September 23 2018
** Description:  Asks the user for their favourite animal and then prints out
**               that that is their favourite animal.
*******************************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
    std::string faveAnimal;
    std::cout << "Please enter your favourite animal." << std::endl;
    std::cin >> faveAnimal;
    std::cout << "Your favourite animal is the " << faveAnimal;
    std::cout << "." << std::endl;
    
    return 0;
}

