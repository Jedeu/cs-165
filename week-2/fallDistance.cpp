/********************************************************************************* 
 **Author: Jed Piezas
 **Date: October 1 2018
 **Description:  Calculates the distance an object has fallen. 
 **              Input: @parameter t for time spent falling
 **              Output: distance the object has fallen given time and gravity
 **********************************************************************************/

#include <cmath>

using std::pow;

double fallDistance( double time )
{
    const double GRAVITY = 9.8;
    return (GRAVITY * pow(time, 2))/2;
}

