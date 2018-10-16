/************************************************************************************* 
 ***** Author: Jed Piezas
 ***** Date: October 15 2018
 ***** Description:  Takes in an array of Persons and the size of the array to find
 *****               the standard deviation of all the ages
 ************************************************************************************/

#include <cmath>
#include "Person.hpp"

using std::sqrt;
using std::pow;

double stdDev(Person arr[], int size)
{
    double mean = 0;
    double sum = 0;
    
    // Loop over the array of Persons
    // to get the mean
    for (int i = 0; i < size; i++) {
        sum += arr[i].getAge();
    }
    mean = sum / size;

    double sumSquaredDevs = 0;

    // To get the population standard deviation
    // We need to subtract the age from the mean to
    // get deviations. Then we square them to make
    // them positive and sum them all up    

    for (int i = 0; i < size; i++) {
        double age = arr[i].getAge();
        double deviation = age - mean;
        sumSquaredDevs += pow(deviation, 2);
    }

    // Then we divide the sum of squared deviations
    // by the size. This in turn gives us the variance
    
    double variance = sumSquaredDevs / size;
    
    // The population standard deviation is the
    // square root of the variance
    return sqrt(variance);
}
