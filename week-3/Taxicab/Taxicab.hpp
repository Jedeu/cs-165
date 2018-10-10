/********************************************************************************* 
 **** Author: Jed Piezas
 **** Date: October 9 2018
 **** Description:  Header file for the Taxicab class
 ****               Declares the prototypes and all of its data members
 ************************************************************************************/

// Include guard
#ifndef TAXICAB_HPP
#define TAXICAB_HPP

// Defines all the data members, getter, and setter methods
class Taxicab
{
private:
    int xCoordinate;
    int yCoordinate;
    int totalDistance;
public:
    Taxicab();
    Taxicab(int, int, int=0);
    int getXCoord();
    int getYCoord();
    int getDistanceTraveled();
    void moveX(int);
    void moveY(int);
};
#endif
