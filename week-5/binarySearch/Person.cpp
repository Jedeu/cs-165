/************************************************************************************ 
 ***** Author: Jed Piezas
 ***** Date: October 21 2018
 ***** Description:  Contains the implementation details of the Person class.
 *****               Uses prototypes in the Person header file.
 *************************************************************************************/

#include "Person.hpp"
#include <string>

using std::string;

Person::Person()
{
    name = "";
}

/**********************************************
 *** This is the constructor for the Person
 *** when parameters are passed in
 *** Sets name based on specified
 *** parameter.
 **********************************************/

Person::Person(string newName)
{
    name = newName; 
}

string Person::getName() const
{
    return name;
}
