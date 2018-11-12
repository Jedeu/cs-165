#include <iostream>
#include "ValSet.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    ValSet<char> mySet;
    mySet.add('A');
    mySet.add('B');
    mySet.add('C');
    mySet.add('D');
    cout << "Size of mySet: " << mySet.size() << endl;
    cout << "mySet has the number A? " << mySet.contains('A') << endl;
    cout << "mySet is empty? " << mySet.isEmpty() << endl;
    cout << "Now about to remove element from mySet" << endl;
    mySet.remove('A');
    cout << "Going to try to remove A again from mySet" << endl;
    mySet.remove('A');
    cout << "mySet has the number 1? " << mySet.contains('A') << endl;
    cout << "mySet is empty? " << mySet.isEmpty() << endl;
    cout << "mySet's new size? " << mySet.size() << endl;
    ValSet<char> mySet2 = mySet;
    cout << "mySet2's size: " << mySet2.size() << endl;
    vector<char> setAsVector = mySet2.getAsVector();
    for (int i = 0; i < setAsVector.size(); i++) {
        cout << setAsVector[i] << endl;
    }
    return 0; 
}
