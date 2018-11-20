#include <iostream>
#include <string>
#include <vector>
#include "StringList.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    StringList myList;
    myList.add("you say goodbye");
    myList.add("and I say hello");
    cout << "Position of 'you say goodbye' is " << myList.positionOf("you say goodbye") << endl;
    cout << "Position of 'and I say hello' is " << myList.positionOf("and I say hello") << endl;
    cout << "Position of something that doesn't exist is " << myList.positionOf("hey there boo bear") << endl;
    bool isInserted = myList.setNodeVal(1, "hello hello!");
    cout << "Was it inserted ? " << isInserted << endl;
    bool isInserted2 = myList.setNodeVal(3, "This won't get inserted");
    cout << "Was inserted2 inserted? " << isInserted2 << endl;
    vector<string> myVect = myList.getAsVector();
    for (int i = 0; i < myVect.size(); i++) {
        cout << myVect[i] << endl;
    }
    cout << myVect.size() << endl;
    StringList myList2 = myList;
    vector<string> myVect2 = myList2.getAsVector();
    for (int i = 0; i < myVect2.size(); i++) {
        cout << myVect2[i] << endl;
    }
    return 0;
}       
