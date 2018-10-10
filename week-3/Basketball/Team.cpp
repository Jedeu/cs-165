/********************************************************************************* 
 ***** Author: Jed Piezas
 ***** Date: October 9 2018
 ***** Description:  Function file for the Team class
 *****               Includes all of the implementation details that were declared in
 *****               header file.
 *************************************************************************************/

#include "Player.hpp"
#include "Team.hpp"

/******************************************************************
 ** This is the constructor function when no parameters are defined.
 ** Sets each team player to an empty player object
 *****************************************************************/
Team::Team()
{
    pointGuard = makeNewPlayer();
    shootingGuard = makeNewPlayer();
    smallForward = makeNewPlayer();
    powerForward = makeNewPlayer();
    center = makeNewPlayer();
}

/******************************************************************
 ** This is the constructor function when the player
 ** parameters are defined.
 ** Sets each team player to an specified player object
 *****************************************************************/
Team::Team(Player teamPg, Player teamSg, Player teamSf, Player teamPf, Player teamC)
{
    pointGuard = teamPg;
    shootingGuard = teamSg;
    smallForward = teamSf;
    powerForward = teamPf;
    center = teamC;
}

/******************************************************************
 ** This function serves as the getter for the team point guard
 *****************************************************************/
Player Team::getPointGuard()
{
    return pointGuard;
}

/******************************************************************
 ** This function serves as the getter for the team shooting guard
 *****************************************************************/
Player Team::getShootingGuard()
{
    return shootingGuard;
}

/******************************************************************
 ** This function serves as the getter for the team 
 ** small forward
 *****************************************************************/
Player Team::getSmallForward()
{
    return smallForward;
}

/******************************************************************
 ** This function serves as the getter for the team 
 ** power forward
 *****************************************************************/
Player Team::getPowerForward()
{
    return powerForward;
}

/******************************************************************
 ** This function serves as the getter for the team 
 ** center
 *****************************************************************/
Player Team::getCenter()
{
    return center;
}

/******************************************************************
 ** This function sets the team point guard to a new point guard
 *****************************************************************/
void Team::setPointGuard(Player newPg)
{
    pointGuard = newPg;
}

/******************************************************************
 ** This function sets the team shooting guard to a new
 ** shooting guard
 *****************************************************************/
void Team::setShootingGuard(Player newSg)
{
    shootingGuard = newSg;
}

/******************************************************************
 ** This function sets the team small forward to a new
 ** small forward
 *****************************************************************/
void Team::setSmallForward(Player newSf)
{
    smallForward = newSf;
}

/******************************************************************
 ** This function sets the team power forward to a new
 ** power forward
 *****************************************************************/
void Team::setPowerForward(Player newPf)
{
    powerForward = newPf;
}

/******************************************************************
 ** This function sets the team center to a new center
 *****************************************************************/
void Team::setCenter(Player newC)
{
    center = newC;
}

/******************************************************************
 ** This function returns the sum of the team's points
 *****************************************************************/
int Team::totalPoints()
{
    // Get the points of each member in the team
    int pgPoints = pointGuard.getPoints();
    int sgPoints = shootingGuard.getPoints();
    int sfPoints = smallForward.getPoints();
    int pfPoints = powerForward.getPoints();
    int cPoints = center.getPoints();
    
    // Return the sum of all of those points
    return pgPoints + sgPoints + sfPoints + pfPoints + cPoints;
}

/******************************************************************
 ** This function is used to instantiate a Player object for the
 ** Team class' default constructor
 *****************************************************************/
Player Team::makeNewPlayer()
{
    // Initialize a new Player object and return it
    Player newPlayer;
    return newPlayer;
}
