/************************************************************************************ 
 *** Author: Jed Piezas
 *** Date: October 28 2018
 *** Description:  Recursively goes through a vector of integers and uses the values
 ***               to traverse through the vector. If it manages to get to the last
 ***               element in the vector, the function returns true. Otherwise it will
 ***               return false. Assumes that the vector is full of non-negative ints
 ***               and that the last element in the vector is 0.
 **************************************************************************************/

#include <vector>

using std::vector;

// Add function prototypes
bool isSolveable(vector<int>, int);

bool canMoveRightWithoutRepeat(vector<int>, int);

bool canMoveLeftWithoutRepeat(vector<int>, int);

bool vectorPuzzle(vector<int> nums)
{
    int startPosition = nums[0];
    return isSolveable(nums, startPosition);
}

/************************************************
 * Recursive helper method that traverses a
 * vector given a position. It will move right
 * or left a given number of spaces provided
 * that the next spot it lands on is not visited.
 * If it is able to move, it will mark its current
 * spot as visited by making the integer negative.
 * **********************************************/
bool isSolveable(vector<int> nums, int position)
{
    // Base case: return true if we reach the end
    // of the vector
    if (position == nums.size() - 1) {
        return true;
    }
   
    // Initialize currentVal to calculate the next spot
    // if possible 
    int currentVal = nums[position];
    
    // A puzzle is solveable if we don't end up revisiting
    // spots. We try to move to the right of the vector
    // provided that we don't revisit a spot and that
    // we don't go out of bounds of the vector.
    if (canMoveRightWithoutRepeat(nums, position)) {
        int newPosition = position + currentVal;
        // Mark our current spot as visited by making
        // the integer negative
        nums[position] = currentVal * -1;
        // Recursive call until we arrive at the base case
        return isSolveable(nums, newPosition);
    // This is the same as the logic above, except we try
    // and move left if we can't go to the right of the vector
    } else if (canMoveLeftWithoutRepeat(nums, position)) {
        int newPosition = position - currentVal;
        nums[position] = currentVal * -1;
        return isSolveable(nums, newPosition);
    } else {
        // We've reached a point where moving left or right results
        // in visited spots or is out of bounds. The puzzle cannot
        // be solved.
        return false;
    } 
}

/******************************************************************
 * Helper function that determines if it is possible to move
 * to the right of the vector. Checks if the next spot would
 * either go out of bounds or if the spot is new (aka non-negative) 
 * ****************************************************************/
bool canMoveRightWithoutRepeat(vector<int> nums, int position)
{
    int newPosition = position + nums[position];
    // Check that the newPosition is within the bounds of the vector
    // and that the new spot is a non-negative number.
    bool withinBounds = newPosition < (nums.size());
    bool isNewSpot = nums[newPosition] >= 0;

    return withinBounds && isNewSpot;
}


/******************************************************************
 * Helper function that determines if it is possible to move
 * to the left of the vector. Checks if the next spot would
 * either go out of bounds or if the spot is new (aka non-negative) 
 * ****************************************************************/
bool canMoveLeftWithoutRepeat(vector<int> nums, int position)
{
    int newPosition = position - nums[position];
    // Check that the newPosition is within the bounds of the vector
    // and that the new spot is a non-negative number.
    bool withinBounds = newPosition >= 0;
    bool isNewSpot = nums[newPosition] >= 0;
    
    return withinBounds && isNewSpot;
}
