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
        bool contains(T) const;
        void add(T);
        void remove(T);
        vector<T> getAsVector();
        // Operator overloads
        ValSet& operator=(const ValSet& right);
        ValSet<T> operator+(const ValSet& right);
        ValSet<T> operator*(const ValSet& right);
        ValSet<T> operator/(const ValSet& right);
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
bool ValSet<T>::contains(T element) const
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
    for (int i = 0; i < numOfElements; i++) {
        if(arrayPointer[i] == element) {
            for (int j = i; j < numOfElements - 1; j++) {
                arrayPointer[j] = arrayPointer[j + 1];
            } 
            numOfElements -= 1;
            arrayPointer[numOfElements] = T();
            break;
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

template <class T>
ValSet<T> ValSet<T>::operator+(const ValSet& right)
{
    ValSet<T> unionSet = *this;
    for (int j = 0; j < right.size(); j++) {
        unionSet.add(right.arrayPointer[j]);
    }
    return unionSet; 
}

template <class T>
ValSet<T> ValSet<T>::operator*(const ValSet& right)
{
    ValSet<T> intersectionSet = *this;
    T itemToCompare;
    for (int i = 0; i < intersectionSet.size(); i++) {
        itemToCompare = intersectionSet.arrayPointer[i];
        if (!right.contains(itemToCompare)) {
            intersectionSet.remove(itemToCompare);
            i -= 1;
        }
    }
    return intersectionSet;
}

template <class T>
ValSet<T> ValSet<T>::operator/(const ValSet& right)
{
    ValSet<T> intersectionSet = *this * right;
    ValSet<T> differenceSet = *this;
    T itemToCompare;
    for (int i = 0; i < differenceSet.size(); i++) {
        itemToCompare = differenceSet.arrayPointer[i];
        if (intersectionSet.contains(itemToCompare)) {
            differenceSet.remove(itemToCompare);
            i -= 1;
        }
    }
    for (int j = 0; j < right.size(); j++) {
        itemToCompare = right.arrayPointer[j];
        if (!intersectionSet.contains(itemToCompare)) {
            differenceSet.add(itemToCompare);
        }
    }
    return differenceSet;
}
