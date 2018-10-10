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
        
        Player makeNewPlayer();
    public:
        Team();
        Team(Player, Player, Player, Player, Player);
        Player getPointGuard();
        Player getShootingGuard();
        Player getSmallForward();
        Player getPowerForward();
        Player getCenter();
        void setPointGuard(Player);
        void setShootingGuard(Player);
        void setSmallForward(Player);
        void setPowerForward(Player);
        void setCenter(Player);
        int totalPoints();
};
#endif
