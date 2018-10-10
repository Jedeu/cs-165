#include <iostream>
#include "Box.hpp"

using std::cout;
using std::endl;

int main()
{
    Box box1;
    Box box2(2.4, 7.1, 5.0);
    double volume1 = box1.calcVolume();
    double surfaceArea1 = box1.calcSurfaceArea();
    double volume2 = box2.calcVolume();
    double surfaceArea2 = box2.calcSurfaceArea();
    
    cout << "Volume : " << volume2 << endl;
    cout << "Surface Area: " << surfaceArea2 << endl;
    
    cout << "Volume 1: " << volume1 << endl;
    cout << "Surface Area: " << surfaceArea1 << endl;
    
    box1.setWidth(4.0);

    cout << box1.calcVolume() << " " << box1.calcSurfaceArea() << endl;    
 
    return 0;
}
