/*************************************************************
 * Program Name: Predator/Prey - Ant Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: A child class of Critter. This contains the
 * move, breed, and starve functions for the ant critters.
 * **********************************************************/

#include "Ant.hpp"

#include <cstdlib> //for rand
#include <vector>
using std::vector;


Ant::Ant(int rowIn, int colIn) : Critter(rowIn, colIn) 
{
	this->bugType = 'O';
}


/*************************************************************
 * Check the surrounding area for empty spaces, then randomly
 * pick a space, move the ant to the space, set the old space
 * to a nullptr, and update the ants internal coordinates.
 * **********************************************************/
void Ant::move(Critter*** boardPtr, int maxRows, int maxCols)
{
	// random direction from 0 to 3
	// 0 = UP 1 = RIGHT 2 = DOWN 3 = LEFT
	breedCounter++;
	int dir = rand() % 4;

	// Check direction
	switch (dir) 
	{
		case UP: 
		{
			//try to move up, check if space is empty (NULL)
			if ((rowPos > 0) && (boardPtr[rowPos - 1][colPos] == nullptr))
			{
				boardPtr[rowPos - 1][colPos] = boardPtr[rowPos][colPos];
				boardPtr[rowPos][colPos] = nullptr;
				rowPos--;
				hasMoved = true;
			}
			break;
		}
		case RIGHT: 
		{
			//try to move right, check if space is empty
			//not sure if colPos < gameBoard.getBoardSize() will work. maybe need a boardCols data member
			if ((colPos < maxCols - 1) && (boardPtr[rowPos][colPos + 1] == nullptr)) 
			{
				boardPtr[rowPos][colPos + 1] = boardPtr[rowPos][colPos];
				boardPtr[rowPos][colPos] = nullptr;
				colPos++;
				hasMoved = true;
			}
			break;
		}
		case DOWN: {
			//try to move down, check if space is empty
			if ((rowPos < maxRows - 1) && (boardPtr[rowPos + 1][colPos] == nullptr)) 
			{
				boardPtr[rowPos + 1][colPos] = boardPtr[rowPos][colPos];
				boardPtr[rowPos][colPos] = nullptr;
				rowPos++;
				hasMoved = true;
			}
			break;
		}
		case LEFT: {
			//try to move left, check if space us empty
			if ((colPos > 0) && (boardPtr[rowPos][colPos - 1] == nullptr)) 
			{
				boardPtr[rowPos][colPos - 1] = boardPtr[rowPos][colPos];
				boardPtr[rowPos][colPos] = nullptr;
				colPos--;
				hasMoved = true;
				}
			break;
		}
	}
}

/********************************************************************
 * Check the surrounding area for empty spaces to place a new ant. If
 * there are empty spaces to use, randomly pick one and place a new ant
 * in that location.
 * *****************************************************************/
void Ant::breed(Critter*** boardPtr, int maxRows, int maxCols)
{
	if (breedCounter == 3)
	{
		vector<int> dir;
		
		//Each direction is tested to see if there is a valid breeding location.
		if ((rowPos > 0) && (boardPtr[rowPos - 1][colPos] == nullptr))
		{ 
			dir.push_back(0);
		}
		if ((colPos < maxCols - 1) && (boardPtr[rowPos][colPos + 1] == nullptr))
		{ 
			dir.push_back(1);
		}
		if ((rowPos < maxRows - 1) && (boardPtr[rowPos + 1][colPos] == nullptr))
		{ 
			dir.push_back(2);
		}
		if ((colPos > 0) && (boardPtr[rowPos][colPos - 1] == nullptr))
		{ 
			dir.push_back(3);
		}

		//Conditional to test if there is a valid direction and avoid dividing by zero.
		if (dir.size() > 0)
		{
			//Randomly chooses a number from the vector corresponding to a direction.
			int temp = rand() % dir.size();

			//Randomly chooses a direction based upon directions available within the vector.
			switch (dir[temp])
			{
				case UP:
					//Creates a new Ant object if all of the conditions are met and sets the breedCounter back to 0.
					boardPtr[rowPos - 1][colPos] = new Ant(rowPos - 1, colPos);
					breedCounter = 0;
					break;
				case RIGHT:
					boardPtr[rowPos][colPos + 1] = new Ant(rowPos, colPos + 1);
					breedCounter = 0;
					break;
				case DOWN:
					boardPtr[rowPos + 1][colPos] = new Ant(rowPos + 1, colPos);
					breedCounter = 0;
					break;
				case LEFT:
					boardPtr[rowPos][colPos - 1] = new Ant(rowPos, colPos - 1);
					breedCounter = 0;
					break;
			}
		}
	}
}