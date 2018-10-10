/************************************************************************************ 
 ***** Author: Jed Piezas
 ***** Date: October 9 2018
 ***** Description:  Header file for the Player class
 *****               Declares the prototypes and all of its data members including
 *****               the player stats and player name
 *************************************************************************************/

#include <string>

using std::string;

// Include guard
#ifndef PLAYER_HPP
#define PLAYER_HPP

//Definition of Player class
class Player
{
    private:
        string name;
        int points;
        int rebounds;
        int assists;
    public:
        Player();
        Player(string, int, int, int);
        string getName();
        int getPoints();
        int getRebounds();
        int getAssists();
        void setPoints();
        void setRebounds();
        void setAssists();
        bool hasMorePointsThan(Player);
};
#endif
