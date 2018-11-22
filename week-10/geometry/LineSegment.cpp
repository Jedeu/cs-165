/**************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 21 2018
 ********* Description:  Function file of the LineSegment class. 
 *********               Implements all the methods that were defined in the header file
 *****************************************************************************************/

#include "Point.hpp"
#include "LineSegment.hpp"

/***************************************************
 * Constructor that takes in a pointer to two Points
 * to create a LineSegment
 * *************************************************/
LineSegment::LineSegment(Point* point1, Point* point2)
{
    this->point1 = point1;
    this->point2 = point2;
}

void LineSegment::setEnd1(Point* newPoint1)
{
    point1 = newPoint1;
}

Point* LineSegment::getEnd1()
{
    return point1;
}

void LineSegment::setEnd2(Point* newPoint2)
{
    point2 = newPoint2;
}

Point* LineSegment::getEnd2()
{
    return point2; 
}

/********************************************
 * Returns the length of the LineSegment
 * using the distance between its two Points.
 * ******************************************/
double LineSegment::length()
{
    return point1->distanceTo(*point2);
}

/********************************************
 * Returns the slope of the line distance
 * using the coordinates of the two points.
 * *****************************************/
double LineSegment::slope()
{
    // The slope is equal to (y2-y1) / (x2 - x1)
    double yDistance = point2->getYCoord() - point1->getYCoord();
    double xDistance = point2->getXCoord() - point1->getXCoord();

    return yDistance / xDistance;
}
