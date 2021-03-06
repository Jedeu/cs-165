#include <iostream>
#include "ValSet.hpp"
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    ValSet<double> mySet;
    mySet.add(1.2);
    mySet.add(2.3);
    mySet.add(3.4);
    mySet.add(4.5);
    cout << "mySet is empty? " << mySet.isEmpty() << endl;
    cout << "mySet's new size? " << mySet.size() << endl;
    cout << "Going to try and add 1.2 again" << endl;
    cout << "mySet's size? " << mySet.size() << endl;
    cout << "Removing 4.5 from mySet" << endl;
    mySet.remove(4.5);
    cout << "mySet's new size? " << mySet.size() << endl;
    cout << "Re-adding 4.5 for testing" << endl;
    mySet.add(4.5);
    ValSet<double> mySet2;
    mySet2.add(5.6);
    mySet2.add(1.2);
    mySet2.add(3.4);
    mySet2.add(6.7);
    ValSet<double> mySetCombo = mySet + mySet2;
    cout << "mySetCombo's size: " << mySetCombo.size() << endl;
    cout << "mySetCombo is empty? : " << mySetCombo.isEmpty() << endl;
    for (int i = 0; i < mySetCombo.size(); i++) {
        cout << mySetCombo.arrayPointer[i] << endl;
    }
    ValSet<double> mySetIntersect = (mySet * mySet2);
    cout << "mySetIntersect's size: " << mySetIntersect.size() << endl;
    cout << "mySetIntersect is empty? : " << mySetIntersect.isEmpty() << endl;
    cout << "Here are mySetIntersect's elements!" << endl;
    for (int i = 0; i < mySetIntersect.size(); i++) {
        cout << mySetIntersect.arrayPointer[i] << endl;
    }
    cout << "Here are mySetDifference's elements!" << endl;
    ValSet<double> mySetDifference = mySet / mySet2;
    for (int i = 0; i < mySetDifference.size(); i++) {
        cout << mySetDifference.arrayPointer[i] << endl;
    } 
    vector<double> vectorDifference = mySetDifference.getAsVector();
    for (int i = 0; i < vectorDifference.size(); i++) {
        cout << vectorDifference[i] << endl;
    }
    return 0; 
}
