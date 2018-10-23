/************************************************************************************* 
 * *** Author: Jed Piezas
 * *** Date: October 9 2018
 * *** Description:  Contains the implementation details of the Box class
 * ***               Uses the protoypes in the Box header file included in this class
 * ***********************************************************************************/

#include "Box.hpp"

/**********************************************
 * This is the default constructor for the Box.
 * Sets the default dimensions to 1
 * *******************************************/
Box::Box()
{
    height = 1;
    width = 1;
    length = 1;
}

/**********************************************
 * This is the constructor for the Box
 * when parameters are passed in
 * Sets each dimension based on specified
 * parameter.
 * *******************************************/
Box::Box(double newHeight, double newWidth, double newLength)
{
    height = newHeight;
    width = newWidth;
    length = newLength;
}

void Box::setHeight(double newHeight)
{
   height = newHeight; 
}

void Box::setWidth(double newWidth)
{
    width = newWidth;
}

void Box::setLength(double newLength)
{
    length = newLength;
}

/************************************************
 * This function calculates the volume of the Box
 * *********************************************/
double Box::calcVolume()
{
    return length * width * height;
}

/******************************************************
 * This function calculates the surface area of the Box
 * ***************************************************/
double Box::calcSurfaceArea()
{
    return (2.0 * (length * width)) 
        + (2.0 * (length * height)) 
        + (2.0 * (height * width));
}
