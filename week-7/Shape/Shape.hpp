/************************************************************************************ 
 ******* Author: Jed Piezas
 ******* Date: November 4 2018
 ******* Description:  Header file for the shape class. Because this is an abstract
 *******               class, all methods contained are pure virtual functions. This
 *******               will throw a compilation error if you attempt to instantiate this
 *******               class.
 ***************************************************************************************/

#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
    //Pure virtual methods to be inherited by all derived classes 
    public:
        virtual double area() = 0;
        virtual double perimeter() = 0;
};
#endif
