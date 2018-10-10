/********************************************************************************* 
 * *** Author: Jed Piezas
 * *** Date: October 9 2018
 * *** Description:  Header file for the Box class. It contains a constructor to initialize
 * ***               its height, width, and length.
 * ***               It also defines the prototype for a method to calculate the Box's volume
 * ***               and also a method to calculate the Box's surface area
 * ***********************************************************************************/

// include guards for the header
#ifndef BOX_HPP
#define BOX_HPP

class Box
{
// Private data members
private:
    double height;
    double width;
    double length;

// Public methods and constructor 
public:
    Box();
    Box(double, double, double);
    void setHeight(double);
    void setWidth(double);
    void setLength(double);
    double calcVolume();
    double calcSurfaceArea();
};
#endif
