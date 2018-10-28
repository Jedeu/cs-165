/************************************************************************************ 
 ******* Author: Jed Piezas
 ******* Date: October 28 2018
 ******* Description:  Passes in an array of doubles and the size of an array
 *******               and recursively calls itself to return the sum of values in the
 *******               array.
 ***************************************************************************************/

double summer(double arr[], int size)
{
    // Base case
    if (size < 0) {
        return 0;
    }
    
    // Recursive call, reducing size by 1 until we
    // hit the base case
    return arr[size - 1] + summer(arr, size - 1);
}
