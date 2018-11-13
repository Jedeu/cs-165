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
/************************************************************
 * Default constructor which initializes a pointer-to-T
 * array with size 10, numberofElements to 0, and the default
 * values of each element within the pointer array
 * **********************************************************/
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

/************************************************************
 * Copy constructor which uses the values of another ValSet
 * to make a new Dynamic Array. Initializes the new ValSet's
 * currentSize and numOfElements to the
 * original's number of elements
 * **********************************************************/
template <class T>
ValSet<T>::ValSet(const ValSet& original)
{
    numOfElements = original.size();
    currentSize = numOfElements;
    // Really important step so that the new ValSet's
    // arrayPointer does not point to the other ValSet's 
    // arrayPointer's address!
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

/************************************************************
 * Returns the number of elements in the ValSet 
 * **********************************************************/
template <class T>
int ValSet<T>::size() const
{
   return numOfElements; 
}

/************************************************************
 * Returns if the ValSet is empty or not by checking its
 * number of elements 
 * **********************************************************/
template <class T>
bool ValSet<T>::isEmpty()
{
    if(numOfElements > 0) {
        return false;
    }
    return true;
}

/************************************************************
 * Loops through the ValSet's arrayPointer and checks if
 * the element passed in exists inside of it.
 * **********************************************************/
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

/************************************************************
 * Adds a new element to the ValSet's arrayPointer if it
 * doesn't already exist in the arrayPointer. 
 * If arrayPointer is full, then we increase the size of it
 * before adding the new element in. Also increments
 * the numOfElements present in ValSet.
 * **********************************************************/
template <class T>
void ValSet<T>::add(T element)
{
    // Don't execute any adding logic if the element already
    // exists in the arrayPointer.
    if(!this->contains(element)) {
        // If we've reached our current size limit, then
        // we need to create a new dynamic array with a larger size.
        if (numOfElements == currentSize) {
            currentSize += 1;
            T* temp = new T[currentSize];
            for (int i = 0; i < numOfElements; i++) {
                temp[i] = arrayPointer[i];
            }
            arrayPointer = nullptr;
            delete[] arrayPointer;
            arrayPointer = temp;
            temp = nullptr;
            delete[] temp;
            // Finally add the new element to the arrayPointer
            arrayPointer[currentSize - 1] = element;
        } else {
            // If the arrayPointer isn't full, then add
            // it at the next available spot 
            for (int i = 0; i < currentSize; i++) {
                if(arrayPointer[i] == T()) {
                    arrayPointer[i] = element;
                    break;
                }
            } 
        }
        numOfElements += 1;
    }
}

/************************************************************
 * Removes the element from the arrayPointer.
 * If it manages to find the element, it moves all subsequent
 * elements in arrayPointer down on index and resets the last
 * index's value to the default type's value.
 * **********************************************************/
template <class T>
void ValSet<T>::remove(T element)
{
    for (int i = 0; i < numOfElements; i++) {
        if(arrayPointer[i] == element) {
            // We've found the element to remove, now we must
            // loop over the remaining items and move them down
            // the arrayPointer by 1
            for (int j = i; j < numOfElements - 1; j++) {
                arrayPointer[j] = arrayPointer[j + 1];
            } 
            // Keep track of numOfElements as always
            numOfElements -= 1;
            // Reset the extra space's value to default
            arrayPointer[numOfElements] = T();
            break;
        }
    } 
}

/************************************************************
 * Returns the elements in the ValSet as a vector.
 * **********************************************************/
template <class T>
vector<T> ValSet<T>::getAsVector()
{
    vector<T> newVect;
    for (int i = 0; i < numOfElements; i++) {
        newVect.push_back(arrayPointer[i]);
    }
    return newVect;
}

/************************************************************
 * Overrides the + operator so that adding two different ValSets
 * will return a ValSet containing the union of the two 
 * i.e. All values found in either of the two sets.
 * **********************************************************/
template <class T>
ValSet<T> ValSet<T>::operator+(const ValSet& right)
{
    ValSet<T> unionSet = *this;
    // Add all elements in the RHS to this arrayPointer's
    // ValSet::add takes care of adding unique values so no need
    // to check here.
    for (int j = 0; j < right.size(); j++) {
        unionSet.add(right.arrayPointer[j]);
    }
    return unionSet; 
}

/************************************************************
 * Overrides the * operator so that multiplying two different ValSets
 * will return a ValSet containing the intersection of the two
 * i.e. All values exclusively found in the first AND second set
 * **********************************************************/
template <class T>
ValSet<T> ValSet<T>::operator*(const ValSet& right)
{
    ValSet<T> intersectionSet = *this;
    T itemToCompare;
    for (int i = 0; i < intersectionSet.size(); i++) {
        itemToCompare = intersectionSet.arrayPointer[i];
        // Only keep elements that are found in both ValSets
        if (!right.contains(itemToCompare)) {
            intersectionSet.remove(itemToCompare);
            // Because remove moves all values down the index by 1,
            // we must reset the iterand by 1 to not miss any values.
            i -= 1;
        }
    }
    return intersectionSet;
}

/************************************************************
 * Overrides the / operator so that dividing two different ValSets
 * will return a ValSet containing the difference of the two sets
 * i.e. All values found in the first XOR second set.
 * **********************************************************/
template <class T>
ValSet<T> ValSet<T>::operator/(const ValSet& right)
{
    // Reference point to see what values are shared between
    // two ValSets
    ValSet<T> intersectionSet = *this * right;
    ValSet<T> differenceSet = *this;
    T itemToCompare;
    // Removes all shared values in the intersectionSet 
    for (int i = 0; i < differenceSet.size(); i++) {
        itemToCompare = differenceSet.arrayPointer[i];
        if (intersectionSet.contains(itemToCompare)) {
            differenceSet.remove(itemToCompare);
            i -= 1;
        }
    }
    // Adds all unique values from the RHS to the 
    // intersectionSet
    for (int j = 0; j < right.size(); j++) {
        itemToCompare = right.arrayPointer[j];
        if (!intersectionSet.contains(itemToCompare)) {
            differenceSet.add(itemToCompare);
        }
    }
    return differenceSet;
}
