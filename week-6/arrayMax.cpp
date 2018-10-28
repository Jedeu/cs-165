/************************************************************************************ 
 * Author: Jed Piezas
 * Date: October 28 2018
 * Description:  Passes in an array of integers and uses recursion to determine
 *               the largest integer.
 ************************************************************************************/

// Add function prototypes
int findMax(int, int);

int arrayMax(int arr[], int size)
{
    // Base case
    // If size is 1 then we have gone through the whole array
    if (size == 1) {
        return arr[0];
    }
    return findMax(arr[size-1], arrayMax(arr, size - 1));
}

/***********************************************
 * Helper method used to find the largest number.
 * Passes in two integers and returns the larger
 * of the two.
 * *********************************************/
int findMax(int first, int second)
{
    if (first > second) {
        return first;
    } else {
        return second;
    }
}
