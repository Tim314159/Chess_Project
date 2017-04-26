// Chess Final Project
// Huck Kim and Tim Zwart
//
// Single player chess
// 2017

#include <iostream>
#include "bitboards.h"

using namespace std;

int main()
{
    Piece whitePawn(5, 5, pawn, white);
    Piece blackPawn(4, 6, pawn, black);
    Piece blackBishop(4, 5, bishop, black);
    pieceBoard b;
    /*b.board[1][1].what_piece = pawn;
    b.board[1][1].side=white;
    b.board[1][1].location.x=1;
    b.board[1][1].location.y=1;
    b.board[2][2].what_piece = pawn;
    b.board[2][2].side=black;
    b.board[2][2].location.x=2;
    b.board[2][2].location.y=2;
    moves(b.board[2][2], b);*/
    b.board[5][5]=whitePawn;
    b.board[4][6]=blackPawn;
    b.board[4][5]=blackBishop;
    b.board[5][5].moves(b);
    b.board[4][6].moves(b);
    b.board[4][5].moves(b);

    cout<<"White Pawn"<<endl;
    for (int i=0; i<b.board[5][5].attack.size(); i++)
    {
        cout << "x: " << b.board[5][5].attack[i].x << endl;
        cout << "y: " << b.board[5][5].attack[i].y << endl;
        cout << endl;
    }
    cout<<"Black Pawn"<<endl;
    for (int i=0; i<b.board[4][6].attack.size(); i++)
    {
        cout << "x: " << b.board[4][6].attack[i].x << endl;
        cout << "y: " << b.board[4][6].attack[i].y << endl;
        cout << endl;
    }
    cout<<"Black Bishop"<<endl;
    for (int i=0; i<b.board[4][5].attack.size(); i++)
    {
        cout << "x: " << b.board[4][5].attack[i].x << endl;
        cout << "y: " << b.board[4][5].attack[i].y << endl;
        cout << endl;
    }

    return 0;
}
