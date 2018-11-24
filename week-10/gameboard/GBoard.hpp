/**************************************************************************************** 
 ********** Author: Jed Piezas
 ********** Date: November 23 2018
 ********** Description:  Header file for the GBoard class. It declares the prototypes
 **********               and data methods for this class
 ******************************************************************************************/

#ifndef GBOARD_HPP
#define GBOARD_HPP

// Enum containing possible game states
enum GameStates {
    X_WON,
    O_WON,
    DRAW,
    UNFINISHED
};

class GBoard
{
    public:
        // Data members
        GameStates gameState;
        char board[15][15];
        // Constructor and instance methods
        GBoard();
        GameStates getGameState();
        bool makeMove(int, int, char);
    private:
        // Size of board
        int size;
        // Helper methods
        void setUpBoard();
        bool boardIsFull();
        bool gameIsOver();
        bool spotIsFilled(int, int);
        void setGameState(int, int, char);
        bool matchVert(int, int, char);
        bool matchHoriz(int, int, char);
        bool matchDiag(int, int, char);
};
#endif
