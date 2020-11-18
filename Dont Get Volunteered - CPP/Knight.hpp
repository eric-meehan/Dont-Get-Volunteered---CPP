/*
 Eric Meehan
 2020-11-18
 
 Class representation of a knight
*/

#ifndef Knight_hpp
#define Knight_hpp

#include "ChessBoard.hpp"
#include <iostream>
#include <vector>

class Knight
{
private:
    std::vector<int> CurrentPosition;
    int MovesTaken;
public:
    // Constructors
    Knight();
    Knight(int);
    // Mutators
    void ExplorePossibleMoves(ChessBoard);
    void SortCurrentPositions();
    // Accessors
    bool IsValidMove(int, int, ChessBoard);
    bool DestinationReached(int);
};

#endif /* Knight_hpp */
