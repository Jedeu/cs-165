/************************************************************************************ 
 ** Author: Jed Piezas
 ** Date: October 28 2018
 ** Description:  Passes in an array of integers and the size of the array to find
 **               if the array is strictly decreasing. If so, it returns true,
 **               otherwise it will return false.
 *************************************************************************************/

bool isDecreasing(int arr[], int size)
{
    // If size is 1, then we must be at the first element
    // in the array, meaning that it is strictly decreasing
    if (size == 1) {
        return true;
    }
    
    // Check that each integer is off by one as we
    // decrement the size. If it isn't, return false
    if ((arr[size - 1] - 1) != arr[size-2]) {
        return false;
    }
    
    // Recursive call, passing in a smaller size each time
    return isDecreasing(arr, size - 1);
}
