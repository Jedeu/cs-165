/************************************************************************************ 
 ***** Author: Jed Piezas
 ***** Date: October 9 2018
 ***** Description:  Header file for the Team class
 *****               Declares the prototypes and all of its data members including
 *****               the team players and the total points
 *************************************************************************************/

#include "Player.hpp"

// Include guard
#ifndef TEAM_HPP
#define TEAM_HPP

class Team
{
    private:
        Player pointGuard;
        Player shootingGuard;
        Player smallForward;
        Player powerForward;
        Player center;
    public:
        Team();
        Team(Player, Player, Player, Player, Player);
        Player getPointGuard();
        Player getShootingGuard();
        Player getSmallForward();
        Player getPowerForward();
        Player getCenter();
        void setPointGuard();
        void setShootingGuard();
        void setSmallForward();
        void setPowerForward();
        void setCenter();
        int totalPoints();
};
#endif
