 /*************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 4 2018
 ********* Description:  Header file for the Square class. It inherits perimeter and area 
 *********               virtual methods from the abstract shape class as well as 
 *********               length, width, and setter methods from the Rectangle class. This
 *********               violates the Liskov substitution principle for educational(?)
 *********               purposes.
 *****************************************************************************************/

#include "Rectangle.hpp"

#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square : public Rectangle
{
    private:
        double length;
        double width;
    public:
        Square();
        Square(double);
        virtual void setLength(double) override;
        virtual void setWidth(double) override;
};
#endif
