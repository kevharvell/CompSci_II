/*************************************************************
 * Program Name: Predator/Prey - Doodlebug Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: A child class of Critter. This contains the
 * move(and eat ants), breed, and starve functions for the 
 * doodlebug critters.
 * **********************************************************/

#include "Doodlebug.hpp"

#include <cstdlib>
#include <vector>
using std::vector;

Doodlebug::Doodlebug(int rowIn, int colIn) : Critter(rowIn, colIn)
{
    this->bugType = 'X';
    this->starveCounter = 0;
}

int Doodlebug::getStarveCounter() {
	return this->starveCounter;
}

/*************************************************************************
 * Check surround areas for ants. Attempt to eat a surround ant. If no
 * surrounding ants are found, do a base move to a new location.
 * **********************************************************************/
void Doodlebug::move(Critter*** boardPtr, int maxRows, int maxCols) {
    breedCounter++;
    vector<int> potentialMoves;

    //Check surrounding spaces for ants
    if ((rowPos > 0) && (boardPtr[rowPos -1][colPos] != nullptr)) {
        if (boardPtr[rowPos -1][colPos]->getBugType() == 'O') {
            potentialMoves.push_back(0);
        }
    }
    if ((colPos < maxCols -1) && (boardPtr[rowPos][colPos + 1] != nullptr)) {
        if (boardPtr[rowPos][colPos + 1]->getBugType() == 'O') {
            potentialMoves.push_back(1);
        }
    }
    if ((rowPos < maxRows - 1) && (boardPtr[rowPos + 1][colPos] != nullptr)) {
        if (boardPtr[rowPos + 1][colPos]->getBugType() == 'O') {
            potentialMoves.push_back(2);
        }
    }
    if ((colPos > 0) && (boardPtr[rowPos][colPos - 1] != nullptr)) {
        if (boardPtr[rowPos][colPos - 1]->getBugType() == 'O') {
            potentialMoves.push_back(3);
        }
    }

    //Attempt to eat surrounding ants
    if (potentialMoves.size() > 0) {
        int temp = (std::rand() % potentialMoves.size());
        switch (potentialMoves[temp]) {
            case UP:
            {
                delete boardPtr[rowPos - 1][colPos];                        //Delete the ant
                boardPtr[rowPos - 1][colPos] = boardPtr[rowPos][colPos];    //Move the doodlebug to new position
                boardPtr[rowPos][colPos] = nullptr;                         //clear the old position
                rowPos--;                                                   //update coordinates
                hasMoved = true;                                            //set moved flag to true
                starveCounter = 0;                                          //update starve counter
                break;
            }

            case RIGHT:
            {
                delete boardPtr[rowPos][colPos + 1];
                boardPtr[rowPos][colPos + 1] = boardPtr[rowPos][colPos];
                boardPtr[rowPos][colPos] = nullptr;
                colPos++;
                hasMoved = true;
                starveCounter = 0;
                break;
            }

            case DOWN:
            {
                delete boardPtr[rowPos + 1][colPos];
                boardPtr[rowPos + 1][colPos] = boardPtr[rowPos][colPos];
                boardPtr[rowPos][colPos] = nullptr;
                rowPos++;
                hasMoved = true;
                starveCounter = 0;
                break;
            }

            case LEFT:
            {
                delete boardPtr[rowPos][colPos - 1];
                boardPtr[rowPos][colPos - 1] = boardPtr[rowPos][colPos];
                boardPtr[rowPos][colPos] = nullptr;
                colPos--;
                hasMoved = true;
                starveCounter = 0;
                break;
            }
        }
    } else {
        //Move normally
        int dir = rand() % 4;
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
                starveCounter++;
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
                starveCounter++;
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
                starveCounter++;
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
                starveCounter++;
			    break;
		    }
	    }
    }
}

/*********************************************************************
 * If doodlebug has been alive for 8 turns, check the surrounding
 * cells for a blank space, and attempt to generate a new doodlebug in
 * a blank space. If no spaces are available, the bug will not breed.
 * ******************************************************************/
void Doodlebug::breed(Critter*** boardPtr, int maxRows, int maxCols) {
	if (breedCounter == 8)
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
					//Creates a new doodlebug object if all of the conditions are met and sets the breedCounter back to 0.
					boardPtr[rowPos - 1][colPos] = new Doodlebug(rowPos - 1, colPos);
					breedCounter = 0;
					break;
				case RIGHT:
					boardPtr[rowPos][colPos + 1] = new Doodlebug(rowPos, colPos + 1);
					breedCounter = 0;
					break;
				case DOWN:
					boardPtr[rowPos + 1][colPos] = new Doodlebug(rowPos + 1, colPos);
					breedCounter = 0;
					break;
				case LEFT:
					boardPtr[rowPos][colPos - 1] = new Doodlebug(rowPos, colPos - 1);
					breedCounter = 0;
					break;
			}
		}
	}
}
