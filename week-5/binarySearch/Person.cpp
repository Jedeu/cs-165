/************************************************************************************ 
 ****** Author: Jed Piezas
 ****** Date: October 15 2018
 ****** Description:  Contains the implementation details of the Person class.
 ******               Uses prototypes in the Person header file.
 **************************************************************************************/

#include "Person.hpp"
#include <string>

using std::string;

Person::Person()
{
    name = "";
    age = 0.0;
}

/**********************************************
 *** This is the constructor for the Person
 *** when parameters are passed in
 *** Sets name and age based on specified
 *** parameter.
 **********************************************/
Person::Person(string newName, double newAge)
{
    name = newName;
    age = newAge; 
}

string Person::getName() const
{
    return name;
}

double Person::getAge()
{
    return age;
}
