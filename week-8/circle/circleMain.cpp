/************************************************************************************** 
 ******** Author: Jed Piezas
 ******** Date: November 10 2018
 ******** Description:  Prompts the user to enter a radius. The program will then
 ********               create a new Circle with that radius. Throws if inputted value
 ********               is larger than the maxRadius. Does not handle negative radii.
 ****************************************************************************************/

#include <iostream>
#include "Circle.hpp"

using std::cin;
using std::cout;
using std::endl;

double Circle::maxRadius = 10.0;

int main()
{
    cout << "Enter the maxRadius for Circles." << endl;
    double maxRadius;
    cin >> maxRadius;
    Circle::setMaxRadius(maxRadius);
    try 
    {
        cout << "Enter the radius for a new Circle object." << endl;
        double newRadius;
        cin >> newRadius;
        Circle newCircle(newRadius);
        cout << "The Circle object was successfully created." << endl;
        cout << "The area of the circle is " << newCircle.calcArea() << "." << endl;
    }
    catch (Circle::IllegalRadius ex)
    {
        cout << "The Circle object could not be created." << endl;
        cout << "A radius of " << ex.badRadius << " exceeds the maximum allowed radius." << endl;
    }
    return 0;
}
