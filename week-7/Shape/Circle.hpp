/************************************************************************************ 
 ******* Author: Jed Piezas
 ******* Date: November 4 2018
 ******* Description:  Header file for the Circle class. It inherits perimeter and area 
 *******               virtual methods from the abstract shape class. It also contains
 *******               a unique radius member as well as a set method for the radius.
 ***************************************************************************************/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle : public Shape
{
    private:
        double radius;
        void setRadius(double);
    public:
        Circle();
        Circle(double);
        virtual double area() override;
        virtual double perimeter() override; 
};
#endif
