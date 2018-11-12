/************************************************************************************ 
 ******* Author: Jed Piezas
 ******* Date: November 10 2018
 ******* Description:  Header file for the ValSet class. The class is designed to be
 *******               as generic as possible and contains a constructor, copy constructor,
 *******               destructor, overloaded operators, and some basic methods to get
 *******               information about the ValSet itself and elements contained 
 *******               inside the ValSet 
 ***************************************************************************************/
#include <vector>

#include <iostream>

using std::vector;
using std::cout;
using std::endl;

#ifndef VALSET_HPP
#define VALSET_HPP
template <class T>
class ValSet
{
    public:
        // Data members
        T* arrayPointer;
        // Constructors
        ValSet();
        ValSet(const ValSet&);
        // Destructor
        ~ValSet();
        // Instance methods
        int size() const;
        bool isEmpty();
        bool contains(T);
        void add(T);
        void remove(T);
        vector<T> getAsVector();
        // Operator overloads
        ValSet& operator=(const ValSet& right);
        ValSet& operator+(const ValSet& right);
        ValSet& operator*(const ValSet& right);
        ValSet& operator/(const ValSet& right);
    private:
        int numOfElements;
        int currentSize;
};
#endif

template <class T>
ValSet<T>::ValSet()
{
    currentSize = 10;
    numOfElements = 0;
    arrayPointer = new T[currentSize];
    for (int i = 0; i < currentSize; i++) {
        arrayPointer[i] = T();
    }
}

template <class T>
ValSet<T>::ValSet(const ValSet& original)
{
    numOfElements = original.size();
    currentSize = numOfElements;
    arrayPointer = new T[currentSize];
    for (int i = 0; i < currentSize; i++) {
        arrayPointer[i] = original.arrayPointer[i];
    }
}

template <class T>
ValSet<T>::~ValSet()
{
    delete[] arrayPointer;
}

template <class T>
int ValSet<T>::size() const
{
   return numOfElements; 
}

template <class T>
bool ValSet<T>::isEmpty()
{
    if(numOfElements > 0) {
        return false;
    }
    return true;
}

template <class T>
bool ValSet<T>::contains(T element)
{
    for (int i = 0; i < numOfElements; i++) {
        if (arrayPointer[i] == element) {
            return true;
        }
    }
    return false;
}

template <class T>
void ValSet<T>::add(T element)
{
    if(!this->contains(element)) {
        numOfElements += 1;
        if (arrayPointer[currentSize - 1] != T()) {
            currentSize += 1;
            T* temp = new T[currentSize];
            for (int i = 0; i < numOfElements; i++) {
                temp[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = temp;
            temp = nullptr;
            delete[] temp;
            arrayPointer[numOfElements - 1] = element;
        } else {
            for (int i = 0; i < currentSize; i++) {
                if(arrayPointer[i] == T()) {
                    arrayPointer[i] = element;
                    break;
                }
            } 
        }
    }
}

template <class T>
void ValSet<T>::remove(T element)
{
    if (this->contains(element)) {
        for (int i = 0; i < currentSize; i++) {
            if(arrayPointer[i] == element) {
                for (int j = i; j < currentSize - 2; j++) {
                    arrayPointer[j] = arrayPointer[j + 1];
                } 
                arrayPointer[currentSize - 1] = T();
                numOfElements -= 1;
                break;
            }
        }
    }
}

template <class T>
vector<T> ValSet<T>::getAsVector()
{
    vector<T> newVect;
    for (int i = 0; i < numOfElements; i++) {
        newVect.push_back(arrayPointer[i]);
    }
    return newVect;
}
