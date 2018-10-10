#include <iostream>
#include "Player.hpp"

using std::cout;
using std::endl;

int main()
{
    Player p1("Charlotte", 24, 10, 7);
    Player p2("Emily", 21, 13, 9);
    Player p3("Anne", 20, 10, 8);
    Player p4("Jane", 19, 10, 10);
    Player p5("Mary", 18, 11, 8);
    if (p1.hasMorePointsThan(p4)) {
       cout << p1.getName() << " has more points than " << p4.getName() << "." << endl;
    }       
    p5.setRebounds(12);

    cout << p5.getRebounds() << endl;
    return 0;
}
