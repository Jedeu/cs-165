/************************************************************************************ 
****** Author: Jed Piezas
****** Date: October 22 2018
****** Description:  Uses the bubble sort algorithm to sort an array of Boxes
******               from largest volume to smallest volume
**************************************************************************************/

#include "Box.hpp"

void boxSort(Box array[], int size)
{
    Box temp;
    bool madeAswap;

    do {
        // Loop until no swaps are made while traveling through the array
        madeAswap = false;
        for (int count = 0; count < (size - 1); count++) {
            // Swap the place of two Boxes if the former's volume is less than
            // the latter's
            if (array[count].calcVolume() < array[count + 1].calcVolume()) {
                temp = array[count + 1];
                array[count + 1] = array[count];
                array[count] = temp;
                madeAswap = true;
            }
        }
    } while (madeAswap);
}
