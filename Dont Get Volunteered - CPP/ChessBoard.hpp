/*
 Eric Meehan
 2020-11-18
 
 Class representation of a chess board that can be of any size
*/

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <iostream>

class ChessBoard
{
private:
    int Length;
    int Width;
    int * * Board;
    // Mutators
    void BoardBuilder();
public:
    // Constructors
    ChessBoard();
    ChessBoard(int, int);
    // Accessors
    int NumericPosition(int, int);
    void CoordinatePosition(int[2], int);
    bool IsOnBoard(const int[2]);
};

#endif /* ChessBoard_hpp */
