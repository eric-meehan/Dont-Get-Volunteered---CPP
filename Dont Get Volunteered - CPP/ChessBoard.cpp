/*
 Eric Meehan
 2020-11-18
 
 Class implementation of a chess board that can be of any size
*/

#include "ChessBoard.hpp"

// CONSTRUCTORS //
ChessBoard::ChessBoard()
{
   // Default constructor
   // Ask the user to define the length and width of the board
   std::cout << "Enter the length of the board: " << std::endl;
   std::cin >> Length;
   std::cout << "Enter the width of the board: " << std::endl;
   std::cin >> Width;
   // Use these parameters to build the chess board
   BoardBuilder();
}

ChessBoard::ChessBoard(int length, int width)
{
   // Parameterized constructor
   // Use the provided length and width to define the chess board
   Length = length;
   Width = width;
   // Use these parameters to build the chess board
   BoardBuilder();
}


// MUTATORS //

void ChessBoard::BoardBuilder()
{
   // Create a matrix to represent the chess board
   Board = new int * [Length];
   for (int i = 0; i < Length; i++)
   {
       Board[i] = new int[Width];
   }
   // Give each cell a unique number
   for (int i = 0; i < Length; i++)
   {
       for (int n = 0; n < Width; n++)
       {
           Board[i][n] = n + (Width * i);
       }
   }
    // Note that since the board exists for the duration of runtime, memory leaks are not a concern.
}


// ACCESSORS //

int ChessBoard::NumericPosition(int x, int y)
{
    return Board[y][x];
}

void ChessBoard::CoordinatePosition(int coordinates[2], int numeric)
{
    // Converts a numeric position to a coordinate position
    bool Found = false;
    for (int i = 0; i < Length; i++)
    {
       for (int n = 0; n < Width; n++)
       {
           if (Board[i][n] == numeric)
           {
               coordinates[0] = n;
               coordinates[1] = i;
               Found = true;
               break;
           }
       }
        if (Found)
        {
            break;
        }
    }
}

bool ChessBoard::IsOnBoard(const int position[2])
{
    // Confirms that a piece does not move outside the perimeter of the board
    return position[0] >= 0 and position[0] < Width and position[1] >= 0 and position[1] < Length;
}
