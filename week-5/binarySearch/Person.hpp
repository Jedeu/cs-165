/************************************************************************************ 
 ****** Author: Jed Piezas
 ****** Date: October 21 2018
 ****** Description:  Header file for the Person class. It contains a constructor to 
 ******               initialize their name
 ******               It also defines the prototype for getter methods to its data 
 ******               members.
 **************************************************************************************/

#include <string>

using std::string;

#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
    private:
        string name;
    public:
        Person();
        Person(string);
        string getName() const;
};
#endif
