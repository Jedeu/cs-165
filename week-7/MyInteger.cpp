/************************************************************************************** 
 ****** Author: Jed Piezas
 ****** Date: November 4 2018
 ****** Description:  Contains the implementation details of the MyInteger class.
 ******               Uses prototypes in the MyInteger header file.
 **************************************************************************************/

#include "MyInteger.hpp"

MyInteger& MyInteger::operator=(const MyInteger& right)
{
    if (this != &right) {
        int numToCopy = right.getMyInt();
        delete pInteger;
        pInteger = new int(numToCopy);
        return *this;
    }
}

MyInteger::MyInteger()
{
    pInteger = new int(0);
}

MyInteger::MyInteger(int num)
{
    pInteger = new int(num);
}

MyInteger::MyInteger(const MyInteger& myInt)
{
    pInteger = new int(myInt.getMyInt());
}

MyInteger::~MyInteger()
{
    delete pInteger;
}

void MyInteger::setMyInt(int value)
{
    *pInteger = value; 
}

int MyInteger::getMyInt() const 
{
    return *pInteger;
}
