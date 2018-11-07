 /*************************************************************************************** 
 ******** Author: Jed Piezas
 ******** Date: November 4 2018
 ******** Description:  Header file for the Rectangle class. It inherits perimeter and area 
 ********               virtual methods from the abstract shape class. It also contains
 ********               a unique length and width members and setter methods for each member.
 ****************************************************************************************/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle : public Shape
{
    protected:
        double length;
        double width;
    public:
        Rectangle();
        Rectangle(double, double);
        virtual void setLength(double);
        virtual void setWidth(double);
        virtual double area() override;
        virtual double perimeter() override;
};
#endif
