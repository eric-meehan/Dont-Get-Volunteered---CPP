/*
 Eric Meehan
 2020-11-18
 
 Class implementation of a knight
*/

#include "Knight.hpp"


// CONSTRUCTORS //
Knight::Knight()
{
    // Default constructor
    // Ask the user to define the starting position of the Knight
    int StartingPosition;
    std::cout << "Enter the starting position of the knight: " << std::endl;
    std::cin >> StartingPosition;
    // Set the CurrentPosition to the StartingPosition
    CurrentPosition.push_back(StartingPosition);
    // Define MovesTaken
    MovesTaken = 0;
}

Knight::Knight(int StartingPosition)
{
    // Parameterized constructor
    // Use the provided StartingPosition to define the piece's CurrentPosition
    CurrentPosition.push_back(StartingPosition);
    // Define MovesTaken
    MovesTaken = 0;
}


// MUTATORS //
void Knight::ExplorePossibleMoves(ChessBoard Board)
{
    // Calculate all of the possible moves from a given position
    // Copy CurrentPosition into a temporary variable to allow manipulations of CurrentPosition
    std::vector<int> SourcePosition = CurrentPosition;
    // Empty CurrentPosition
    CurrentPosition.clear();
    // For each position listed in SourcePosition, generate the possible positions for the subsequent move
    for (auto each : SourcePosition)
    {
        // Convert the numeric position to coordinates
        int *coordinates = nullptr;
        Board.CoordinatePosition(coordinates, each);
        // Test the possible moves and add them to the CurrentPosition vector
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] + 1, coordinates[1] + 2), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] + 1, coordinates[1] + 2));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] + 1, coordinates[1] - 2), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] + 1, coordinates[1] - 2));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] - 1, coordinates[1] - 2), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] - 1, coordinates[1] - 2));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] - 1, coordinates[1] + 2), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] - 1, coordinates[1] + 2));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] + 2, coordinates[1] + 1), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] + 2, coordinates[1] + 1));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] + 2, coordinates[1] - 1), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] + 2, coordinates[1] - 1));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] - 2, coordinates[1] + 1), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] - 2, coordinates[1] + 1));
        }
        if (IsValidMove(Board.NumericPosition(coordinates[0], coordinates[1]), Board.NumericPosition(coordinates[0] - 2, coordinates[1] - 1), Board))
        {
            CurrentPosition.push_back(Board.NumericPosition(coordinates[0] - 2, coordinates[1] - 1));
        }
    }
    // Increment moves taken
    MovesTaken++;
}

void Knight::SortCurrentPositions()
{
    // Use a bubble sort to organize CurrentPosition vector
    int temp;
    for (int i = 1; i < CurrentPosition.size(); i++)
    {
        for (int n = 0; n < CurrentPosition.size() - i; n++)
        {
            if (CurrentPosition[n] > CurrentPosition[n + 1])
            {
                temp = CurrentPosition[n];
                CurrentPosition[n] = CurrentPosition[n + 1];
                CurrentPosition[n + 1] = temp;
            }
        }
    }
}


// ACCESSORS //

bool Knight::IsValidMove(int source, int destination, ChessBoard Board)
{
    // Confirm that the destination position will be on the board
    if (!Board.IsOnBoard(destination)) {
        return false;
    }
    // Convert the numeric positions of source and destination to coordinates
    int *SourceCoordinates = nullptr;
    Board.CoordinatePosition(SourceCoordinates, source);
    int *DestinationCoordinates = nullptr;
    Board.CoordinatePosition(DestinationCoordinates, destination);
    // Confirm that moving from the source to the destination does not require warping over the edges
    bool HasWarped = (
                   (SourceCoordinates[0] - DestinationCoordinates[0] == 1 && SourceCoordinates[1] - DestinationCoordinates[1] == 2) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == 2 && SourceCoordinates[1] - DestinationCoordinates[1] == 1) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == -1 && SourceCoordinates[1] - DestinationCoordinates[1] == -2) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == -2 && SourceCoordinates[1] - DestinationCoordinates[1] == -1) ||
                   (DestinationCoordinates[0] - SourceCoordinates[0] == 1 && DestinationCoordinates[1] - SourceCoordinates[1] == 2) ||
                   (DestinationCoordinates[0] - SourceCoordinates[0] == 2 && DestinationCoordinates[1] - SourceCoordinates[1] == 1) ||
                   (DestinationCoordinates[0] - SourceCoordinates[0] == -1 && DestinationCoordinates[1] - SourceCoordinates[1] == -2) ||
                   (DestinationCoordinates[0] - SourceCoordinates[0] == -2 && DestinationCoordinates[1] - SourceCoordinates[1] == -1) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == 1 && SourceCoordinates[1] - DestinationCoordinates[1] == -2) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == -1 && SourceCoordinates[1] - DestinationCoordinates[1] == 2) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == 2 && SourceCoordinates[1] - DestinationCoordinates[1] == -1) ||
                   (SourceCoordinates[0] - DestinationCoordinates[0] == -2 && SourceCoordinates[1] - DestinationCoordinates[1] == 1)
                   );
    return !HasWarped;
}

bool Knight::DestinationReached(int Destination)
{
    // Perform a binary search on the CurrentPosition vector for the Destination
    int First = 0;
    int Last = CurrentPosition.size() - 1;
    int Middle;
    while (First <= Last)
    {
        Middle = (First + Last) / 2;
        if (CurrentPosition[Middle] == Destination)
        {
            return true;
        }
        else if (CurrentPosition[Middle] > Destination)
        {
            Last = Middle - 1;
        }
        else{
            First = Middle + 1;
        }
    }
    return false;
}
