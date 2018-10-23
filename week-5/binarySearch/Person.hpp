/************************************************************************************ 
****** Author: Jed Piezas
****** Date: October 15 2018
****** Description:  Header file for the Person class. It contains a constructor to 
******               initialize their name and age.
******               It also defines the prototype for getter methods to its data 
******               members.
**************************************************************************************/

#include <string>

using std::string;

//include guards for the header
#ifndef PERSON_HPP
#define PERSON_HPP

class Person
{
    // Private data members
    private:
        string name;
        double age;
    // Constructor and getter methods
    public:
        Person();
        Person(string, double);
        string getName() const;
        double getAge();
};
#endif
