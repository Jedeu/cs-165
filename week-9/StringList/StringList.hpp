/**************************************************************************************** 
 ******** Author: Jed Piezas
 ******** Date: November 18 2018
 ******** Description:  Header file for the StringList class. It contains a copy
 ********               constructor, destructor, and a default constructor.
 ********               It also has methods that help with manipulating the StringList
 ****************************************************************************************/

#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef STRINGLIST_HPP
#define STRINGLIST_HPP

class StringList
{
    private:   
        struct ListNode 
        {
            string value;
            ListNode *next;
            ListNode(string value, ListNode *next = nullptr)
            {
                this->value = value;
                this->next = next;
            }
        };
        // List head pointer
        ListNode *head; 
    public:
        StringList();
        // Destructor
        ~StringList();
        void add(string);
        int positionOf(string);
        bool setNodeVal(int, string);
        vector<string> getAsVector(); 
        // Copy constructor
        StringList(const StringList&);
    private:
       int size;
};

#endif
