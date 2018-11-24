/***************************************************************************************** 
 ********* Author: Jed Piezas
 ********* Date: November 23 2018
 ********* Description:  Contains the implementation details of the GBoard class.
 *********               Uses prototypes in the GBoard header file.
 *****************************************************************************************/

#include "GBoard.hpp"
#include <cctype>

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
    // Only access the following indices as long as we don't go out of bounds
    // Notice that we don't do else ifs here because we want to check both directions!
    if (row + 4 < size) {
        // We only check the next 4 spots because we already know what
        // piece is played on the current spot
        if (board[row + 1][column] == playerPiece && board[row + 2][column] == playerPiece
                && board[row + 3][column] == playerPiece && board[row + 4][column] == playerPiece) {
            return true;
        }
    }
    // Don't go out of bounds when checking previous rows
    if (row - 4 >= 0) {
        // See above about only checking 4 spots
        if (board[row - 1][column] == playerPiece && board[row - 2][column] == playerPiece
            && board[row - 3][column] == playerPiece && board[row - 4][column] == playerPiece) {
            return true;
        }
    }

    return false;
}

/********************************************************************************
 * Checks if the player has 5 in a row left or rightfrom the last piece. 
 * Returns true if we have a match
 * *****************************************************************************/
bool GBoard::matchHoriz(int row, int column, char playerPiece)
{
    // As in matchVert, we check boundaries before checking if we get 5 in a row since C++
    // doesn't do any bounds checking
    // Again, no else ifs because we want to check both directions
    if (column + 4 < size) {
        // Also just like matchVert, we only check 4 spots because we know that 5th spot was just
        // potentially played
        if (board[row][column + 1] == playerPiece && board[row][column + 2] == playerPiece
                && board[row][column + 3] == playerPiece && board[row][column + 4] == playerPiece) {
            return true;
        }
    }
    // See above, but this is for checking a 5 in the row to the left of the piece.
    if (column - 4 >= 0) { 
        if (board[row][column - 1] == playerPiece && board[row][column - 2] == playerPiece
                && board[row][column - 3] == playerPiece && board[row][column - 4] == playerPiece) {
            return true;
        }
    }

    return false;
}

/********************************************************************************
 * Checks if the player has 5 in a row diagonally.  
 * Returns true if we have a match
 * *****************************************************************************/
bool GBoard::matchDiag(int row, int column, char playerPiece) 
{
    // Again, no else if statements here because we want to check all diagonal directions from
    // the piece that was last played!

    // upper-right diagonals
    // Columns increase and rows decrease
    if (column + 4 < size && row - 4 >= 0) {
        if (board[row - 1][column + 1] == playerPiece && board[row - 2][column + 2] == playerPiece 
                && board[row - 3][column + 3] == playerPiece && board[row - 4][column + 4] == playerPiece) {
            return true;
        }
    } 
    // lower-right diagonals
    // columns increase and rows increase
    if (column + 4 < size && row + 4 < size) {
        if (board[row + 1][column + 1] == playerPiece && board[row + 2][column + 2] == playerPiece
                && board[row + 3][column + 3] == playerPiece && board[row + 4][column + 4] == playerPiece) {
            return true;
        }
    }
    // upper-left diagonals
    // columns decrease and rows decrease
    if (column - 4 >= 0 && row - 4 >= 0) {
        if (board[row - 1][column - 1] == playerPiece && board[row - 2][column - 2] == playerPiece
                && board[row - 3][column - 3] == playerPiece && board[row - 4][column - 4] == playerPiece) {
            return true;
        }
    }
    // lower-left diagonals
    // columns decrease and rows increase
    if (column - 4 >= 0 && row + 4 < size) {
        if (board[row + 1][column - 1] == playerPiece && board[row + 2][column - 2] == playerPiece
                && board[row + 3][column - 3] == playerPiece && board[row + 4][column - 4] == playerPiece) {
            return true;
        }
    }
    
    return false;
}
