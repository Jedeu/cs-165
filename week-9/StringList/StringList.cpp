/************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 18 2018
 ********* Description:  Contains the implementation details of the StringList class.
 *********               Uses prototypes in the StringList header file.
 **************************************************************************************/

#include <vector>
#include <string>
#include "StringList.hpp"

using std::vector;
using std::string;

StringList::StringList()
{
    head = nullptr;
    size = 0;
}

StringList::~StringList()
{
    ListNode *nodePtr = head;
    while (nodePtr != nullptr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

/**************************************************
 * Adds a new word to the end of the StringList
 * ************************************************/
void StringList::add(string word)
{
    // Handle empty StringLists
    if (head == nullptr) {
        head = new ListNode(word);
    } else {
        // Otherwise travel the linked list until we reach the tail and add a new ListNode
        ListNode* nodePtr = head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = new ListNode(word);
    }
    // Increase the size
    size++;
}

/**************************************************
 * Returns the zero-based position of a given word. 
 * If the word does not exist in the StringList, 
 * it will return -1.
 * ************************************************/
int StringList::positionOf(string word)
{
    ListNode* nodePtr = head;
    bool isFound = false;
    int position = 0;
    while (nodePtr)
    {
        // Keep looping until we find the word
        // Change the flag and break out of the loop
        if (nodePtr->value == word) {
            isFound = true;
            break;
        } else {
            // Otherwise, we keep on going and
            // increase the position by 1 every time
            nodePtr = nodePtr->next;
            position++;
        }
    }
    // Handle the case when we don't find the word
    if(!isFound) {
        position = -1;
    }
    return position;
}

/**************************************************
 * Inserts a word at a given position and then
 * returns true. If the position given is greater
 * or equal to the size of the StringList, simply
 * return false.
 * ************************************************/
bool StringList::setNodeVal(int position, string word)
{
    if (position >= size) {
        return false;
    }

    bool isInserted = false;
    
    // Handle the case when there is only one
    // element in the StringList 
    if (position == 0) {
        // reset the head to a new ListNode with its
        // next pointer set to the old address of head.
        head = new ListNode(word, head);
        // Always increment size every time we add a new element
        size++;
        isInserted = true;
    } else { 
        // Otherwise we travel through the StringList
        // up to the point just before the position
        ListNode* previousNodePtr = head;
        ListNode* nodePtr = head->next;
        for (int i = 0; i < position - 1; i++) {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Insert the new ListNode and set it in-between
        // the element before its position and the old 
        // element that was at that position.
        previousNodePtr->next = new ListNode(word, nodePtr);
        // Always increment size every time we add a new element
        size++;
        isInserted = true;
    }
    
    return isInserted;
}

/**************************************************
 * Returns a vector containing the same size, values
 * and order as the StringList.
 * ************************************************/
vector<string> StringList::getAsVector()
{
    vector<string> vect;
    ListNode* nodePtr = head;
    while (nodePtr) {
        vect.push_back(nodePtr->value);
        nodePtr = nodePtr->next;
    }
    return vect;
}

/**************************************************
 * Copy constructor that makes a deep copy of
 * the RHS' StringList.
 * ************************************************/
StringList::StringList(const StringList& right)
{
    // Handle the case that the original StringList is empty.
    if (right.head == nullptr) {
        head = nullptr;
    } else {
        // Otherwise we create a new head using the original's head
        // then set the stage to iterate through this StringList and right's
        // StringList, copying values from the latter to the former.
        head = new ListNode(right.head->value);
        ListNode* nodePtr = head;
        ListNode* rightPtr = right.head->next;
        while (rightPtr) {
            nodePtr->next = new ListNode(rightPtr->value);
            // Don't forget to increment size every time we add a value
            size++;
            rightPtr = rightPtr->next;
            nodePtr = nodePtr->next;
        } 
    }
}
