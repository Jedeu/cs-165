/********************************************************************************* 
 **** Author: Jed Piezas
 **** Date: October 9 2018
 **** Description:  Function file for the Taxicab class
 ****               Includes all of the implementation details that were declared in
 ****               header file.
 ************************************************************************************/

#include <cmath>
#include "Taxicab.hpp"

using std::abs;

/******************************************************************
 * This is the constructor function when no parameters are defined.
 * Sets all coordinates and total distance to 0.
 * ***************************************************************/
Taxicab::Taxicab()
{
    xCoordinate = 0;
    yCoordinate = 0;
    totalDistance = 0;    
}

/******************************************************************
 * This is the constructor function when coordinates and distance
 * is defined.
 * Sets all coordinates and total distance according to the
 * parameters passed in.
 * ***************************************************************/
Taxicab::Taxicab(int xCoord, int yCoord, int totalDist)
{
    xCoordinate = xCoord;
    yCoordinate = yCoord;
    totalDistance = totalDist;
}

/******************************************************************
 * This function serves as a getter for the xCoordinate member
 * ***************************************************************/
int Taxicab::getXCoord()
{
    return xCoordinate;
}

/******************************************************************
 * This function serves as a getter for the yCoordinate member
 * ***************************************************************/
int Taxicab::getYCoord()
{
    return yCoordinate;
}

/******************************************************************
 * This function serves as a getter for the totalDistance member
 * ***************************************************************/
int Taxicab::getDistanceTraveled()
{
    return totalDistance;
}

/******************************************************************
 * This function moves the Taxicab xDist units along the x-axis
 * and increments the totalDistance traveled
 * ***************************************************************/
void Taxicab::moveX(int xDist)
{
    xCoordinate += xDist;
    // We use abs to calculate the distance regardless
    // of negative inputs
    totalDistance += abs(xDist);
}

/******************************************************************
 * This function moves the Taxicab yDist units along the y-axis
 * and increments the totalDistance traveled
 * ***************************************************************/
void Taxicab::moveY(int yDist)
{
    yCoordinate += yDist;
    // We use abs to calculate the distance regardless
    // of negative inputs
    totalDistance += abs(yDist);
}
