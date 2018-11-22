#include "Point.hpp"
#include "LineSegment.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Point p1(4.3, 7.52);
    Point p2(-17.0, 1.5);
    cout << p1.getXCoord() << endl;
    cout << p1.getYCoord() << endl;
    cout << p2.getXCoord() << endl;
    cout << p2.getYCoord() << endl;
    cout << p1.distanceTo(p2) << endl; 

    Point p3(5.0, 8.52);
    
    LineSegment ls1(&p1, &p2);
    cout << ls1.length() << endl;
    cout << ls1.slope() << endl;

    LineSegment ls2(&p1, &p3);
    cout << ls2.length() << endl;
    cout << ls2.slope() << endl;

    Point p4(-100, 5000);
    p4.setXCoord(5.1);
    p4.setYCoord(4.2);
    cout << p4.getXCoord() << endl;
    cout << p4.getYCoord() << endl;
    return 0;
}
