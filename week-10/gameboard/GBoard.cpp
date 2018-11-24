/***************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 23 2018
 ********* Description:  Contains the implementation details of the GBoard class.
 *********               Uses prototypes in the GBoard header file.
 *****************************************************************************************/

#include "GBoard.hpp"
#include <cctype>

#include <iostream>
using std::cout;
using std::endl;

using std::tolower;

GBoard::GBoard()
{
    size = 15;
    setUpBoard();    
    gameState = UNFINISHED;
}

/***********************************
 * Returns the game's current state
 * *********************************/
GameStates GBoard::getGameState()
{
    return gameState;
}

/********************************************************************
 * Passes in the row, column, and the player's piece to 
 * update the board. Checks first if the spot is taken or
 * if the game is over before making the move and updating the
 * state. Returns true if the operation succeeds, or false otherwise
 * ******************************************************************/
bool GBoard::makeMove(int row, int column, char playerPiece)
{

    if (gameIsOver() || spotIsFilled(row, column)) {
        return false;
    } else {
        board[row][column] = playerPiece;

        setGameState(row, column, playerPiece);
        
        return true;
    }
}

/********************************************************
 * Helper method to set up a 15 x 15 board. Initializes
 * all empty spots with a '.'
 * *****************************************************/
void GBoard::setUpBoard()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = '.';
        }
    } 
}

/***********************************************
 * Helper method to check if the board is full
 * *********************************************/
bool GBoard::boardIsFull()
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Return out of loop the moment
            // we run into an empty slot on the board
            if (board[i][j] == '.') {
                return false;
            }
        }
    }
    // If the loop finished without returning, it must be full
    return true;
}

/*********************************************************
 * Helper method to see if game is in one of three states.
 * Used to see if making a move is a legal operation
 * ******************************************************/
bool GBoard::gameIsOver()
{
    return gameState == X_WON || gameState == O_WON || gameState == DRAW;
}

/*********************************************************************
 * Helper method to see ensure the spot is empty before making a move
 * ******************************************************************/
bool GBoard::spotIsFilled(int row, int column)
{
    return board[row][column] != '.';
}

/***********************************************************************************
 * Updates the game's state by checking if a player has won or if the board is full
 * ********************************************************************************/
void GBoard::setGameState(int row, int column, char playerPiece)
{
    // Check if we have 5 in a row vertically, horizontally, or diagonally
    if (matchVert(row, column, playerPiece) || matchHoriz(row, column, playerPiece) || matchDiag(row, column, playerPiece)) {
        // If we do, check who played the most recent move. They must be the winner
        if (tolower(playerPiece) == 'x') {
            gameState = X_WON;
        } else {
            gameState = O_WON;
        }
    // Otherwise, check if the board is full and call it a draw
    } else if (boardIsFull()) {
        gameState = DRAW;
    }
}

/********************************************************************************
 * Checks if the player has 5 in a row vertically up or down from the last piece. 
 * Returns true if we have a match
 * *****************************************************************************/
bool GBoard::matchVert(int row, int column, char playerPiece)
{
    // We use a counter to handle the edge-case that
    // the piece that completes the series of 5 is not the first or last
    int counter = 0;

    // Only access the following indices as long as we don't go out of bounds
    // Notice that we don't do else ifs here because we want to check both directions! 
    // We only check the next 4 spots because we already know what
    // piece is played on the current spot
    for (int i = row + 1; i < row + 5; i++) {
        if (board[i][column] == playerPiece && i < size) {
            counter++;
        } else {
            // Break in case we encounter the other player's stuff or go out of bounds
            break;
        }
    }
    
    // Same logic as above but going up the board instead
    for (int i = row - 1; i > row - 5; i--) {
        if (board[i][column] == playerPiece && i >= 0) {
            counter++;
        } else {
            break;
        }
    }

    if (counter == 4) {
        return true;
    } else {
        return false;
    }
}

/********************************************************************************
 * Checks if the player has 5 in a row left or right from the last piece. 
 * Uses similar logic as matchVert counting the number of pieces it finds adjacent
 * Returns true if we have a match
 * *****************************************************************************/
bool GBoard::matchHoriz(int row, int column, char playerPiece)
{
    int counter = 0;

    // Again, no else ifs because we want to check both directions
    // Also just like matchVert, we only check for 4 spots while still staying in the bounds
    // of the board since we know the last piece played 
    for (int i = column + 1; i < column + 5; i++) {
        if (board[row][i] == playerPiece && i < size) {
            counter++;
        } else {
            break;
        }
    }

    // See above, but this is for checking a 5 in the row to the left of the piece.
    for (int i = column - 1; i > column - 5; i--) {
        if (board[row][i] == playerPiece && i >= 0) {
            counter++;
        } else {
            break;
        }
    }

    if (counter == 4) {
        return true;
    } else {
        return false;
    }
}

/********************************************************************************
 * Checks if the player has 5 in a row diagonally. This works differently from
 * horizontal or vertical because we have to check '/' diagonals and '\' diagonals.
 * After we check one diagonal, we reset the counter to 0 before checking the other
 * one. 
 * Returns true if we have a match.
 * *****************************************************************************/
bool GBoard::matchDiag(int row, int column, char playerPiece) 
{
    int counter = 0;
     
    // '/' diagonals
    // For the upper-right portion, rows increase and columns decrease
    for (int i = row - 1, j = column + 1; i > row - 5 && j < column + 5; i--, j++) {
        if (board[i][j] == playerPiece && i >= 0 && j < size) {
            counter++;
        } else {
            break;
        }
    }  
    // For the lower-left portion, it's the opposite.
    for (int i = row + 1, j = column - 1; i < row + 5 && j > column - 5; i++, j--) {
        if (board[i][j] == playerPiece && i < size && j >= 0) {
            counter++;
        } else {
            break;
        }
    }

    // Check if we found 4 pieces to make '/'. If not, reset counter to 0 and check other diagonal
    if (counter == 4) {
        return true;
    } else {
        counter = 0;
    }

    // '\' diagonals
    // For the lower-right portion, columns increase and rows increase
    for (int i = row + 1, j = column + 1; i < row + 5 && j < column + 5; i++, j++) {
        if (board[i][j] == playerPiece && i < size && j < size) {
            counter++;
        } else {
            break;
        }
    } 
    // For the upper-left portion, it's the opposite
    for (int i = row - 1, j = column - 1; i > row - 5 && j > column - 5; i--, j--) {
        if(board[i][j] == playerPiece && i >= 0 && j >= 0) {
            counter++;
        } else {
            break;
        }
    }
  
    // Final check if counter is 4 
    if (counter == 4) {
        return true;
    } 
    
    // Otherwise return false for the whole method call
    return false;
       
}
