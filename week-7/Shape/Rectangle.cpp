 /*************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 4 2018
 ********* Description:  Contains implementation details of the Rectangle class.
 *********               Uses all methods and members declared in the Rectangle header file.
 *****************************************************************************************/

#include "Shape.hpp"
#include "Rectangle.hpp"

Rectangle::Rectangle()
{
    length = 0.0;
    width = 0.0;
}

/***********************************************************
 * Uses the this pointer to set the length and width to the
 * double values passed into the constructor
 * ********************************************************/
Rectangle::Rectangle(double length, double width)
{
    this->length = length;
    this->width = width;
}

void Rectangle::setLength(double newLength)
{
    length = newLength;
}

void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

/***********************************************************
 * Calculates the area using its length and width
 * ********************************************************/
double Rectangle::area()
{

    return length * width;
}


/***********************************************************
 * Calculates the perimeter using its length and width
 * ********************************************************/
double Rectangle::perimeter()
{
    return 2 * (length + width);
}
