/************************************************************************************ 
 ***** Author: Jed Piezas
 ***** Date: October 15 2018
 ***** Description:  Takes an array of integers and the array's size to determine the
 *****               median of all the numbers. Able to handle an odd number and an
 *****               even number of integers in the array.
 *************************************************************************************/

#include <algorithm>

using std::sort;

double findMedian(int arr[], int size)
{
    double median;
    // Mutates the array and sorts it in ascending order
    sort(arr, arr + size);   
    if (size % 2 == 0) {
        // If there are an even number of integers,
        // The median is the mean of the two middle integers
        // We have to subtract 1 because arrays start at 0
        int num1 = arr[(size/2) - 1];
        int num2 = arr[(size/2)]; 
        median = (num1 + num2) / 2.0;
    } else {
        // Integer division of size/2
        // will round the result down to the correct 
        // index of the array
        median = arr[(size/2)]; 
    }

    return median; 
}
