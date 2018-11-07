 /*************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 4 2018
 ********* Description:  Function file for the Square class.
 *********               Includes all implementation methods defined in the header file
 *****************************************************************************************/

#include "Shape.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"

Square::Square()
{
    length = 0;
    width = 0;
}

/*********************************************************
 * Uses the base class constructor to pass in a double to
 * give the Square class its length and width
 * *******************************************************/
Square::Square(double side) : Rectangle(side, side) {}

void Square::setLength(double newSide)
{
    // We use the base classe's setLength and setWidth
    // to make sure the square's sides are the same
    Rectangle::setLength(newSide);
    Rectangle::setWidth(newSide);
}

void Square::setWidth(double newSide)
{
    //See Square::setLength 
    Rectangle::setLength(newSide);
    Rectangle::setWidth(newSide);
}
