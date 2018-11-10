/************************************************************************************ 
 ******** Author: Jed Piezas
 ******** Date: November 10 2018
 ******** Description:  Header file for the Circle class. It inherits perimeter and area 
 ********               virtual methods from the abstract shape class. It also contains
 ********               a unique radius member as well as a set method for the radius.
 ****************************************************************************************/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle
{
    private:
        static double maxRadius; 
    public:
        // constructors
        Circle();
        Circle(double);
        double radius;
        double calcArea();
        // static member and method
        static void setMaxRadius(double);
        // IllegalRadius exception class
        class IllegalRadius
        {
            public:
                double badRadius;
                // constructor used to extract data
                IllegalRadius(double radius)
                {
                    badRadius = radius;
                }
        };
};
#endif
