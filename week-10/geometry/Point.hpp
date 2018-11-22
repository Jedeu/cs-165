/**************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 21 2018
 ********* Description:  Header file for the Point class. It declares the prototypes
 *********               and data methods for this class
 *****************************************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
    public:
        Point();
        Point(double, double);
        double getXCoord();
        void setXCoord(double);
        double getYCoord();
        void setYCoord(double);
        double distanceTo(Point);
    private:
        double xCoord;
        double yCoord;
};
#endif
