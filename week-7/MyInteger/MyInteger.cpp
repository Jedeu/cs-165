/************************************************************************************** 
 ****** Author: Jed Piezas
 ****** Date: November 4 2018
 ****** Description:  Contains the implementation details of the MyInteger class.
 ******               Uses prototypes in the MyInteger header file.
 **************************************************************************************/

#include "MyInteger.hpp"

/****************************************************
 * Overrides the = operator so that it creates a new
 * dynamic pointer for pInteger. Ensures that two objects
 * are not simply assigned, which would result in having both
 * of their pIntegers referencing the same pointer
 * **************************************************/
MyInteger& MyInteger::operator=(const MyInteger& right)
{
    if (this != &right) {
        delete pInteger;
        pInteger = new int(right.getMyInt());
        return *this;
    }
}

MyInteger::MyInteger()
{
    pInteger = new int(0);
}

/****************************************************
 * Constructor function that takes in an integer
 * and creates a dynamic pointer with that number,
 * assigning it to the pInteger member.
 * **************************************************/
MyInteger::MyInteger(int num)
{
    pInteger = new int(num);
}


/****************************************************
 * Copy Constructor that takes in a MyInteger instance
 * and uses its pInteger value to create a new 
 * dynamic pointer and assign it to its pInteger member.
 * This circumvents problems with the default copy
 * constructor having two instances of MyInteger
 * referencing the same pointer.
 * **************************************************/

MyInteger::MyInteger(const MyInteger& myInt)
{
    pInteger = new int(myInt.getMyInt());
}

/****************************************************
 * Destructor function that deletes the dynamically
 * allocated pointer.
 * **************************************************/
 
MyInteger::~MyInteger()
{
    delete pInteger;
}

void MyInteger::setMyInt(int value)
{
    // Need to de-reference the pointer to assign
    // the value to the pointer's value and not the address
    *pInteger = value; 
}

int MyInteger::getMyInt() const 
{
    return *pInteger;
}
