#ifndef BITBOARDS_H_INCLUDED
#define BITBOARDS_H_INCLUDED

#include "libraries.h"

enum chess_piece {king = 0, queen = 1, rook = 2, bishop = 3, knight = 4, pawn = 5, blank};
enum colour {white = 0, black = 1, none};
enum moveStates {stalemate = 1, checkmate = 2, illegal = 3, takeKing = 4};
enum gameState {whiteWins = 0, blackWins = 1, draw = 2, continuing = 3};

struct node;

// Coordinate system
struct coord
{
    int x;
    int y;
};

struct move_store
{
    coord start_loc;
    coord end_loc;
    int eval;
};

// Pieces that are attacked, used in Piece class
struct attacked
{
    vector <coord> attack_coord;
    vector <chess_piece> which_piece;
};

// Convert an x and a y value to a coordinate
coord toCoord(int x, int y);

class Board;

class Piece
{
    // Friends
    friend class Board;
private:
    // Direction that the piece would move in if it was a pawn
    int dir;

    // Can the piece castle (kings and rooks can't after moving)
    bool castle;

    // Can en passant be used on the piece
    bool enpassant;
public:
    // Constructors
    Piece(coord, chess_piece, colour);
    Piece();

    // Find possible moves
    void moves(Board &board);

    // Saves the movement
    vector <coord> movement;

    // Saves the squares that the piece can control
    vector <coord> control;

    // Saves what pieces it can attack
    attacked attack_option;

    // Whic colour the piece is
    colour side;

    // What type of piece it is
    chess_piece what_piece;

    // The location of the piece
    coord location;

    // Testing functions
    void testing();
    void piece_clear();

    void operator =(const Piece& startLoc);
};

// 8x8 board of pieces
class Board
{
    // Friends
    friend ostream & operator<<(ostream & stream, Board &b);
    friend class Piece;
    friend int breadth_search(node *parent, int maxPly, int currPly, move_store thisMove, colour calcSide, bool first);
    friend int breadth_search(Board b, int maxPly, int currPly, move_store thisMove, colour calcSide, move_store* chosenMove);
    friend gameState getMove(colour side, node *& n);
private:


    // Board of pieces
    Piece board[8][8];

    // Squares that are controlled
    int whiteControl[8][8];
    int blackControl[8][8];

    // Count of pieces
    int w[6];
    int b[6];

public:
    //List of Coord that are being attacked

    vector <coord> white_attack;
    vector <coord> black_attack;

    // Output control board
    void outputBoard(colour side);

    // Reset the board to the starting configuration
    void reset();

    // Calculate control board
    void calcBoard(colour side);

    //
    void generate_move(colour side);

    // Store all moves
    vector<move_store> moves;

    // Store what the AI considers to be the best move
    int bestMove;

    // Calculate all possible moves from a position
    void calcMoves(colour side);

    void do_move(move_store thisMove);

    // Evaluate board
    void evalBoard();
    int score;

    // Test a piece on the board
    void testing(int x, int y);

    void depth_search(int ply, int current_ply, colour side);

    void calculate(colour side);

    void operator =(const Board& startLoc);

    // Computer moves
    //void compMove(colour side, node *n);
};

struct node
{
    node* trunk;
    vector<node*> branches;
    Board container;
};

// Destroy a section of a tree, starting with a node and deleting everything after it
void destroy(node *& n);

void convert(coord position);
coord convert(string s);
move_store convert(coord start, coord finish);

// Output board
ostream & operator<<(ostream & stream, Board &b);
ostream & operator<<(ostream & stream, vector<coord>);
bool operator==(coord first, coord second);
bool operator==(move_store first, move_store second);
#endif // BITBOARDS_H_INCLUDED
