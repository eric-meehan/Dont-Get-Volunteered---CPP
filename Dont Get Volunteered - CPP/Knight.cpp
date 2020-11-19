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
    // Define MovesMade
    MovesMade = 0;
}

Knight::Knight(int StartingPosition)
{
    // Parameterized constructor
    // Use the provided StartingPosition to define the piece's CurrentPosition
    CurrentPosition.push_back(StartingPosition);
    // Define MovesMade
    MovesMade = 0;
}


// MUTATORS //
void Knight::ExplorePossibleMoves(ChessBoard Board)
{
    // Calculate all of the possible moves from a given position
    // CurrentPosition represents all of the possible current positions, rather than a singular position.
    // Copy CurrentPosition into a temporary variable to allow manipulations of CurrentPosition
    std::vector<int> SourcePosition = CurrentPosition;
    // Empty CurrentPosition
    CurrentPosition.clear();
    // For each position listed in SourcePosition, generate the possible positions for the subsequent move
    int SourceCoordinates[2];
    int DestinationCoordinates[2];
    for (auto each : SourcePosition)
    {
        // Update SourceCoordinates
        Board.CoordinatePosition(SourceCoordinates, each);
        // Test all the possible moves and add them to the CurrentPosition vector
        // Update DestinationCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] + 1;
        DestinationCoordinates[1] = SourceCoordinates[1] + 2;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] + 1;
        DestinationCoordinates[1] = SourceCoordinates[1] - 2;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] - 1;
        DestinationCoordinates[1] = SourceCoordinates[1] - 2;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] - 1;
        DestinationCoordinates[1] = SourceCoordinates[1] + 2;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] + 2;
        DestinationCoordinates[1] = SourceCoordinates[1] + 1;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] + 2;
        DestinationCoordinates[1] = SourceCoordinates[1] - 1;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] - 2;
        DestinationCoordinates[1] = SourceCoordinates[1] - 1;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
        // Update SourceCoordinates
        DestinationCoordinates[0] = SourceCoordinates[0] - 2;
        DestinationCoordinates[1] = SourceCoordinates[1] + 1;
        // Test DestinationCoordinates
        if (Board.IsOnBoard(DestinationCoordinates))
        {
            // Add the numeric position of DestinationCoordinates to the CurrentPosition vector
            CurrentPosition.push_back(Board.NumericPosition(DestinationCoordinates[0], DestinationCoordinates[1]));
        }
    }
    // Increment moves taken
    MovesMade++;
    // Sort the CurrentPosition list to improve searchability
    SortCurrentPositions();
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

bool Knight::operator!=(int Destination) const
{
    // Perform a binary search on the CurrentPosition vector for the Destination
    int First = 0;
    int Last = int(CurrentPosition.size()) - 1;
    int Middle;
    while (First <= Last)
    {
        Middle = (First + Last) / 2;
        if (CurrentPosition[Middle] == Destination)
        {
            return false;
        }
        else if (CurrentPosition[Middle] > Destination)
        {
            Last = Middle - 1;
        }
        else{
            First = Middle + 1;
        }
    }
    return true;
}

int Knight::GetMovesMade()
{
    // Simply return the number of moves taken
    return MovesMade;
}
