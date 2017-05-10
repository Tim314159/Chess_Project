// Chess Final Project
// Huck Kim and Tim Zwart
//
// Single player chess
// 2017

#include <iostream>
#include "bitboards.h"
#include "movegen.h"

using namespace std;

int main()
{
    // Declare chessboard
    Board b;

    // Calculate moves for white and group onto a board
    b.calcMoves(white);
    b.calcBoard(white);

    // Calculate moves for black and group onto a board
    b.calcMoves(black);
    b.calcBoard(black);

    // Output all of the squares that white is attacking
    b.outputBoard(black);

    cout << endl << endl;

    // Output all of the squares that black is attacking
    b.outputBoard(white);

    cout << endl << endl;

    // Output board
    cout << b << endl;

    return 0;
}
