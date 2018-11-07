/************************************************************************************** 
 ******* Author: Jed Piezas
 ******* Date: November 4 2018
 ******* Description:  Contains the implementation details of the Circle class.
 *******               Uses prototypes in the Circle header file.
 ***************************************************************************************/

#include "Shape.hpp"
#include "Circle.hpp"
#include <math.h>      

Circle::Circle()
{
    setRadius(0.0);
}

/************************************************************
 * Constructor function that takes in a double and sets it as
 * the radius of the Circle
 * **********************************************************/
Circle::Circle(double newRadius) 
{
    setRadius(newRadius);    
}

/************************************************************
 * Calculates the area of the circle using the formula
 * and the Circle's radius
 * **********************************************************/
double Circle::area()
{      
    // Using 3.14159 for pi
    return pow(radius, 2) * 3.14159;
}

/************************************************************
 * Calculates the perimeter of the circle using the formula
 * the Circle's radius
 * **********************************************************/
double Circle::perimeter()
{      
    // Using 3.14159 for pi
    return 2 * 3.14159 * radius;
}

/************************************************************
 * Helper method that takes in a double and sets it as the
 * Circle's radius
 * **********************************************************/
void Circle::setRadius(double radius)
{
    this->radius = radius;
}
