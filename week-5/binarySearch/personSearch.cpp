/************************************************************************************ 
 ***** Author: Jed Piezas
 ****** Date: October 21 2018
 ****** Description:  Takes in a constant vector of Persons and a name.
 ******               Uses binary search to return the index of the Person's position
 **************************************************************************************/

#include "Person.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

int personSearch(const vector<Person>& persons, string name)
{
    int first = 0;
    int last = persons.size() - 1;
    int middle;
    // Set to -1 to show that the person is not in the sorted vector
    int position = -1;
    bool found = false;
    
    // Loop while not found and we haven't exhausted the vector
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        // If the middle vector's name is the person we're looking for
        // Assign the position to middle and stop the loop
        if (persons[middle].getName() == name) {
            found = true;
            position = middle;
        // Otherwise we either loop to the left of middle if we overshot
        } else if (persons[middle].getName() > name) {
            last = middle - 1;
        // Or loop to the right if the name to search comes later in the vector
        } else {
            first = middle + 1;   
        }
    }
    return position;
}
