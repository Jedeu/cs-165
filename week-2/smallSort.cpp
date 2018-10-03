/********************************************************************************* 
 ***Author: Jed Piezas
 ***Date: October 1 2018
 ***Description:  Sorts three integers from smallest to largest and updates their values
 ***              by reference.
 ***              Input: @parameter first for the first integer
 ***                     @parameter second for the second integer
 ***                     @parameter third for the third integer
 ***              Output: void
 ***********************************************************************************/

void smallSort( int &first, int &second, int &third )
{
    // Create a placeholder variable
    int temp;
    
    // Swap the position of third and second
    // if second is bigger than third
    if ( second > third ) 
    {
        temp = second;
        second = third;
        third = temp;
    }
    
    // Swap the position of first and third
    // if first is bigger than third
    if ( first > third ) 
    {
        temp = third;
        third = first;
        first = temp;
    }
    
    // Swap the position of first and second
    // if first is bigger than second
    if ( first > second ) 
    {
        temp = first;
        first = second;
        second = temp;
    }
}
