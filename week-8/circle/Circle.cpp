/************************************************************************************** 
 ******** Author: Jed Piezas
 ******** Date: November 10 2018
 ******** Description:  Contains the implementation details of the Circle class.
 ********               Uses prototypes in the Circle header file.
 ****************************************************************************************/

#include <cmath>
#include "Circle.hpp"

using std::pow;

Circle::Circle()
{
    radius = 1.0;
}

Circle::Circle(double radius)
{
    if (radius > maxRadius) {
        throw IllegalRadius(radius);
    }
    this->radius = radius;
}

double Circle::calcArea()
{
    // Use 3.14159 for pi
   return 3.14159 * pow(radius, 2); 
}

void Circle::setMaxRadius(double newMax)
{
    maxRadius = newMax;
}
