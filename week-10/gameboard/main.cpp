#include "GBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    GBoard myBoard;
    myBoard.makeMove(0, 5, 'x');
    myBoard.makeMove(1, 6, 'x');
    myBoard.makeMove(2, 7, 'x');
    myBoard.makeMove(4, 9, 'x');
    myBoard.makeMove(3, 8, 'o');
    myBoard.makeMove(3, 9, 'o');
    myBoard.makeMove(3, 11, 'o');
    myBoard.makeMove(3, 12, 'o');
    myBoard.makeMove(3, 10, 'o');
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
