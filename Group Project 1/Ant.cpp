#include "Ant.hpp"

Ant::Ant(int xPos, int yPos, char bugType, int numSteps)
{
	this->bugType = bugType;
	this->numSteps = numSteps;
	this->xPos = xPos;
	this->yPos = yPos;
}
void Ant::move(Game gameBoard)
{
	boardPtr = gameBoard.getBoard();
	//random direction from 0 to 3
	//0 = UP 1 = RIGHT 2 = DOWN 3 = LEFT
	dir = (Orientation)(rand() % 3);

	switch (dir)
	{
	case 0:
		//try to move up, check if space is empty (NULL)
		if ((rowPos > 0 ) && (boardPtr[rowPos - 1][colPos] = NULL))
		{
			//ant moves up 1 column
			boardPtr[rowPos - 1][colPos] = boardPtr[rowPos][colPos];
			//set old space to NULL
			boardPtr[rowPos][colPos] = NULL;
			//set new row
			rowPos--;
		}
		break;
	case 1:
		//try to move right, check if space is empty
		//not sure if colPos < gameBoard.getBoardSize() will work. maybe need a boardCols data member
		if ((colPos < gameBoard.getBoardSize()) && (boardPtr[rowPos][colPos+1] = NULL))
		{
			boardPtr[rowPos][colPos+1] = boardPtr[rowPos][colPos];
			boardPtr[rowPos][colPos] = NULL;
			colPos++;
		}
		break;
	case 2:
		//try to move down, check if space is empty
		if ((rowPos < gameBoard.getBoardSize()) && (boardPtr[rowPos + 1][colPos] = NULL))
		{
			boardPtr[rowPos+1][colPos] = boardPtr[rowPos][colPos];
			boardPtr[rowPos][colPos] = NULL;
			rowPos++;
		}
		break;
	case 3:
		//try to move left, check if space us empty
		if ((colPos < gameBoard.getBoardSize()) && (boardPtr[rowPos][colPos - 1] = NULL))
		{
			boardPtr[rowPos][colPos - 1] = boardPtr[rowPos][colPos];
			boardPtr[rowPos][colPos] = NULL;
			colPos--;
		}
		break;
	default:
		break;
	}

	numSteps++;
}
void Ant::breed()
{
	//random direction from 0 to 3
	//0 = UP 1 = RIGHT 2 = DOWN 3 = LEFT
	dir = (Orientation)(rand() % 3);
	//breeding occurs every 3 days
	if (numSteps != 0 && numSteps % 3 == 0)
	{
		//random direction of breeding
		switch (dir)
		{
		case 0:
			if ((rowPos > 0) && (boardPtr[rowPos - 1][colPos] = NULL))
			{
				//instantiate new ant object with values
				Ant *lilAnt = new Ant(rowPos - 1, colPos, 'O', 0);
			}
			break;

		case 1:
			if ((colPos < gameBoard.getBoardSize()) && (boardPtr[rowPos][colPos + 1] = NULL))
			{
				Ant *lilAnt = new Ant(rowPos, colPos + 1, 'O', 0);
			}
			break;
			
		case 2:
			if ((rowPos < gameBoard.getBoardSize()) && (boardPtr[rowPos + 1][colPos] = NULL))
			{
				Ant *lilAnt = new Ant(rowPos + 1, colPos, 'O', 0);
			}
			break;

		case 3:
			if ((colPos < gameBoard.getBoardSize()) && (boardPtr[rowPos][colPos - 1] = NULL))
			{
				Ant *lilAnt = new Ant(rowPos, colPos - 1, 'O', 0);
			}
			break;
		}
	}
}

char Ant::getBugType()
{
	return this->bugType;
}