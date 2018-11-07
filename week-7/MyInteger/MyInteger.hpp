/************************************************************************************ 
 ****** Author: Jed Piezas
 ****** Date: November 4 2018
 ****** Description:  Header file for the MyInteger class. It contains a constructor to 
 ******               initialize the integer and an overloaded copy constructor to
 ******               prevent two MyInteger classes from pointing to the same value.
 ******               It also has a destructor to deallocate memory when it is destroyed.
 ******               Finally, it also defines the prototype for getter and setter methods  
 ******               to its data members.
 **************************************************************************************/

#ifndef MYINTEGER_HPP
#define MYINTEGER_HPP

class MyInteger
{
    private:
        int* pInteger;
    public:
        // = operator override
        MyInteger& operator=(const MyInteger& right);
        MyInteger();
        MyInteger(int);
        // Copy constructor to handle dynamic integers
        MyInteger(const MyInteger&);
        ~MyInteger();
        int getMyInt() const;
        void setMyInt(int);
        
};
#endif
