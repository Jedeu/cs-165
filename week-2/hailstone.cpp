/********************************************************************************* 
***Author: Jed Piezas
***Date: October 1 2018
***Description:  Returns the number of steps needed to complete a hailstone sequence
***              based on a given positive integer
***              Input: @param start for the starting integer to use
***              Output: The number of steps it took to complete the sequence
***********************************************************************************/

int hailStone( int start )
{
    // Return 0 steps if the start is already 1
    if ( start == 1 ) 
    {
        return 0;
    }
    else
    {
        int counter = 0;
        int currentNum = start;
        // Otherwise continuously loop until we get to 1
        while( currentNum != 1 )
        {
            // Use modulo to see if number is even
            if ( currentNum % 2 == 0 )
            {
                currentNum = currentNum / 2;
            }
            else
            {
                currentNum = currentNum * 3 + 1;
            }
            // Each iteration of the loop, we increment the number of steps taken
            counter++;
        }
        // Return the number of steps in the hailstone sequence
        return counter;
    }
}
