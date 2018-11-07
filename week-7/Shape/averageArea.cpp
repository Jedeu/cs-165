/************************************************************************************ 
 ***** Author: Jed Piezas
 ***** Date: October 22 2018
 ***** Description:  Uses a vector of Shape pointers to calculate the average area
 *****               of all the shapes in the vector
 *************************************************************************************/

#include <vector>
#include <memory>
#include "Shape.hpp"

using std::vector;
using std::shared_ptr;

double averageArea(vector<shared_ptr<Shape>> shapes)
{       
    double totalArea = 0;
    // Loop through the vector to get the total area
    for (int i = 0; i < shapes.size(); i++) {
       totalArea += shapes[i]->area(); 
    }
    // Get the average by dividing the total by number of shapes
    return totalArea / shapes.size();
}
