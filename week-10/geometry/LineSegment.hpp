/**************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 21 2018
 ********* Description:  Header file of the LineSegment class. It declares the constructor
 *********               and all prototype methods.
 *****************************************************************************************/

#include "Point.hpp"

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

class LineSegment
{
    public:
        LineSegment(Point*, Point*);
        void setEnd1(Point*);
        Point* getEnd1();
        void setEnd2(Point*);
        Point* getEnd2();
        double length();
        double slope();     
    private:
        Point* point1;
        Point* point2;
};
#endif
