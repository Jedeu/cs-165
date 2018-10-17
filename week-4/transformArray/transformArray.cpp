/************************************************************************************* 
 ****** Author: Jed Piezas
 ****** Date: October 15 2018
 ****** Description:  Takes in a dynamically allocated array of integers and mutates it
 ******               to an array containing the original numbers followed by double
 ******               the number in its respective order
 *************************************************************************************/

#include <iostream>

using std::cout;
using std::endl;

void transformArray(int*& arr, int size)
{
    int DOUBLED_SIZE = size * 2;

    // Create a new dynamically allocated array of double the size
    int* temp = new int[DOUBLED_SIZE];
    
    for (int i = 0; i < size; i++) {
        // Copy the original values of arr to temp
        temp[i] = arr[i];
        // Calculate the incremented number by one
        // and assign it to its i + sizeth position
        int incrByOne = arr[i] + 1;
        temp[i + size] = incrByOne;
    }
   
    // Delete the array and set to null pointer; 
    delete [] arr;
    arr = nullptr;
    
    // Point the temp array to the array pointer
    arr = temp;
}
