#include "GBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    GBoard myBoard;
    myBoard.makeMove(0, 0, 'x');
    myBoard.makeMove(0, 0, 'o');
    myBoard.makeMove(9, 9, 'x');
    myBoard.makeMove(2, 1, 'o');
    myBoard.makeMove(8, 8, 'x');
    myBoard.makeMove(3, 3, 'o');
    myBoard.makeMove(7, 7, 'x');
    myBoard.makeMove(4, 2, 'o');
    myBoard.makeMove(6, 6, 'x');
    myBoard.makeMove(7, 2, 'o');
    myBoard.makeMove(7, 2, 'x');
    myBoard.makeMove(5, 5, 'x');
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cout << myBoard.board[i][j];
        }
        cout << endl;
    }
    cout << "This is the game's current board state" << endl;
    cout << myBoard.getGameState() << endl;
    return 0;
}
