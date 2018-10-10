/********************************************************************************* 
 ***** Author: Jed Piezas
 ***** Date: October 9 2018
 ***** Description:  Function file for the Taxicab class
 *****               Includes all of the implementation details that were declared in
 *****               header file.
 *************************************************************************************/

#include <string>
#include "Player.hpp"

using std::string;

Player::Player()
{
    name = "";
    points = -100;
    rebounds = -100;
    assists = -100;
}

Player::Player(string playerName, int playerPoints, int playerRebounds, int playerAssists)
{
    name = playerName;
    points = playerPoints;
    rebounds = playerRebounds;
    assists = playerAssists;
}

string Player::getName()
{
    return name;
}

int Player::getPoints()
{
    return points;
}

int Player::getRebounds()
{
    return rebounds;
}

int Player::getAssists()
{
    return assists;
}

void Player::setPoints(int newPoints)
{
    points = newPoints;
}

void Player::setRebounds(int newRebounds)
{
    rebounds = newRebounds;
}

void Player::setAssists(int newAssists)
{
    assists = newAssists;
}

bool Player::hasMorePointsThan(Player otherPlayer)
{
    return points > otherPlayer.getPoints();
}
