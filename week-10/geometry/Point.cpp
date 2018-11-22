/**************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 21 2018
 ********* Description:  Function file of the Point class. Includes all the implementation
 *********               details that were declared in the header file.
 *****************************************************************************************/

#include <cmath>
#include "Point.hpp"

using std::pow;
using std::sqrt;

Point::Point()
{
    xCoord = 0.0;
    yCoord = 0.0;
}

/*****************************************************************
 * Constructor that takes two doubles and sets them to the Point's
 * xCoord and yCoord, respectively.
 * **************************************************************/
Point::Point(double xCoord, double yCoord)
{
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

double Point::getXCoord()
{
    return xCoord;
}

void Point::setXCoord(double newXCoord)
{
    xCoord = newXCoord;
}

double Point::getYCoord()
{
    return yCoord;
}

void Point::setYCoord(double newYCoord)
{
    yCoord = newYCoord;
}

double Point::distanceTo(Point endPoint)
{
    // No need to worry about the distance being negative because we
    // square it later to find pythagoreanDistance
    double yDistance = endPoint.getYCoord() - yCoord;
    double xDistance = endPoint.getXCoord() - xCoord;
    double pythagoreanDistance = sqrt(pow(yDistance, 2) + pow(xDistance, 2));
    
    return pythagoreanDistance;
}
