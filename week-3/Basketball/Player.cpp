/********************************************************************************* 
 ***** Author: Jed Piezas
 ***** Date: October 9 2018
 ***** Description:  Function file for the Player class
 *****               Includes all of the implementation details that were declared in
 *****               header file.
 *************************************************************************************/

#include <string>
#include "Player.hpp"

using std::string;
/******************************************************************
 ** This is the constructor function when no parameters are defined.
 ** Sets the name to a blank string and all stats to -100
 *****************************************************************/
Player::Player()
{
    name = "";
    points = -100;
    rebounds = -100;
    assists = -100;
}

/******************************************************************
 ** This is the constructor function when parameters are passed in
 ** Sets the name and stats to those parameters
 *****************************************************************/
Player::Player(string playerName, int playerPoints, int playerRebounds, int playerAssists)
{
    name = playerName;
    points = playerPoints;
    rebounds = playerRebounds;
    assists = playerAssists;
}

/******************************************************************
 ** This function serves as a getter for the player's name
 *****************************************************************/
string Player::getName()
{
    return name;
}

/******************************************************************
 ** This function serves as a getter for the player's points
 *****************************************************************/
int Player::getPoints()
{
    return points;
}

/******************************************************************
 ** This function serves as a getter for the player's rebounds
 *****************************************************************/
int Player::getRebounds()
{
    return rebounds;
}

/******************************************************************
 ** This function serves as a getter for the player's assists
 *****************************************************************/
int Player::getAssists()
{
    return assists;
}

/******************************************************************
 ** This function sets the points of the player based on the
 ** points argument passed in
 *****************************************************************/
void Player::setPoints(int newPoints)
{
    points = newPoints;
}

/******************************************************************
 ** This function sets the rebounds of the player based on the
 ** rebounds argument passed in
 *****************************************************************/
void Player::setRebounds(int newRebounds)
{
    rebounds = newRebounds;
}

/******************************************************************
 ** This function sets the assists of the player based on the
 ** assists argument passed in
 *****************************************************************/
void Player::setAssists(int newAssists)
{
    assists = newAssists;
}

/******************************************************************
 ** This function compares points between this player and another
 ** player and determines if this player has more points
 *****************************************************************/
bool Player::hasMorePointsThan(Player otherPlayer)
{
    // Uses getter from otherPlayer's object to compare points
    return points > otherPlayer.getPoints();
}
