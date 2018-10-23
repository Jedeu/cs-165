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
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (persons[middle].getName() == name) {
            found = true;
            position = middle;
        } else if (persons[middle].getName() > name) {
            last = middle - 1;
        } else {
            first = middle + 1;   
        }
    }
    return position;
}
