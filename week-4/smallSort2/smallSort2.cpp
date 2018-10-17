/************************************************************************************ 
 ****** Author: Jed Piezas
 ****** Date: October 15 2018
 ****** Description:  Takes the addresses of 3 ints and sorts the ints at those 
 ******               addresses in ascending order.
 **************************************************************************************/

void smallSort2(int* first, int* second, int* third)
{
    int temp;
    
    // Swap the values of first and second
    // if first is bigger than second
    if (*first > *second) {
        temp = *first;
        *first = *second;
        *second = temp;
    }
    
    // Swap the values of first and third
    // if first is bigger than third
    if (*first > *third) {
        temp = *third;
        *third = *first;
        *first = temp;
    }
    
    // Swap the values of second and third
    // if second is bigger than third
    if (*second > *third) {
        temp = *second;
        *second = *third;
        *third  = temp;
    }
}       
