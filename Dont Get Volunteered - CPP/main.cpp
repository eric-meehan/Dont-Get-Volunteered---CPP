 /*
 Eric Meehan
 2020-11-18
 Don't Get Volunteered
 */

#include "ChessBoard.hpp"
#include "Knight.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    // Required variables for board dimensions, source position, and destination
    int Length;
    int Width;
    int Source;
    int Destination;
    // The user may define the dimensions of the board, source position, and destination as arguments
    if (argc > 1)
    {
        // These arguments will need to be cast as integers
        std::string arg;
        // Get Length from first argument
        arg = argv[1];
        try
        {
            Length = std::stoi(arg);
        }
        catch(std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
        // Get Width from second argument
        arg = argv[2];
        try
        {
            Width = std::stoi(arg);
        }
        catch(std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
        // Get Source from third argument
        arg = argv[3];
        try
        {
            Source = std::stoi(arg);
        }
        catch(std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
        // Get Destination from fourth argument
        arg = argv[4];
        try
        {
            Destination = std::stoi(arg);
        }
        catch(std::invalid_argument)
        {
            std::cout << "Invalid argument" << std::endl;
            return 1;
        }
    }
    // Alternatively, an 8x8 board will be created by default with source position 0 and destination 1
    else
    {
        Length = 8;
        Width = 8;
        Source = 0;
        Destination = 1;
    }
    // Define the ChessBoard
    ChessBoard Board = ChessBoard(Length, Width);
    // Instantiate the Knight
    Knight knight = Knight(Source);
    // Generate a tree of possible moves until the destination is reached
    while (knight != Destination)
    {
        knight.ExplorePossibleMoves(Board);
    }
    // Print the number of moves required to reach that destination
    std::cout << knight.GetMovesMade() << std::endl;
    return 0;
}
