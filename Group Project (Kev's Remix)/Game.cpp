/*************************************************************
 * Program Name: Predator/Prey - Game Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: This contains the primary functions of the
 * predator/prey simulation, including board creation, critter
 * creation and manipulation, and turn control.
 * **********************************************************/

#include <cstdlib> //for rand
#include <iostream>

#include "Game.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

using std::cout;
using std::endl;

Game::Game()
{
    timeStep = 0;
    rows = 0;
    cols = 0;
    moveCount = 0;
}

/****************************************************
 * Delete each dynamically allocated object on the
 * board, then delete the dynamically allocated pointer
 * arrays.
 * *************************************************/
Game::~Game()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] != nullptr)
            {
                delete board[i][j];
                board[i][j] = nullptr;
            }
        }
        if (board[i] != nullptr)
        {
            delete[] board[i];
            board[i] = nullptr;
        }
    }
    delete[] board;
    board = nullptr;
}

/*
Critter*** Game::getBoard() {
    return board;
}
*/

/************************************************
 * Generate the board for critters to be placed on.
 * Initialize each space to a null pointer.
 * *********************************************/
void Game::createBoard() {
    board = new Critter** [rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Critter* [cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board[i][j] = nullptr;
        }
    }
}

/*************************************************
 * Print the board to the console.
 * - = blank space
 * X = doodlebug
 * O = ant
 * **********************************************/
void Game::printBoard() {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board[i][j] != nullptr)
            {
                cout << board[i][j]->getBugType();
            }
            else
            {
                cout << " ";
            }

        }
        cout << endl;
    }
}

/**************************************************
 * Prompt the user to enter the number of steps for
 * the simulation and initialize the entered value.
 * ***********************************************/
void Game::setTimeStep()
{
	//this->timeStep = n;
    cout << "Please enter the number of turns for the simulation to run (0 to 1000): ";
    this->timeStep = validate.getInt(0, 1000);
}

int Game::getTimeStep()
{
	return this->timeStep;
}

/*************************************************
 * Prompt the user to enter the number of rows for
 * the simulation board and initialize the value.
 * **********************************************/
void Game::setRows()
{
	//this->rows = n;
    cout << "Please enter number of rows for the board (20 to 100): ";
    this->rows = validate.getInt(20, 100);
}

int Game::getRows()
{
	return this->rows;
}

/***********************************************
 * Prompt the user to enter the numbers of columns
 * for the simulation board and initialize the value.
 * *********************************************/
void Game::setCols()
{
	//this->cols = n;
    cout << "Please enter number of columns for the board (20 to 100): ";
    this->cols = validate.getInt(20, 100);
}

int Game::getCols()
{
	return this->cols;
}

/******************************************************
 * Create a single ant object at a specified location
 * ****************************************************/
void Game::createAnt(int row, int col) {
    board[row][col] = new Ant(row, col);
}

/**********************************************************
 * Create a single doodlebug object at a specified location
 * *******************************************************/
void Game::createDoodlebug(int row, int col) {
    board[row][col] = new Doodlebug(row, col);
}

/**********************************************************
 * Place the specified number of critters on the board
 * at random locations.
 * *******************************************************/
void Game::placeCritters(int numCritters, char type) {
    int critterCounter = 0;
    while (critterCounter < numCritters) {
        int m = rand() % this->getRows();
        int n = rand() % this->getCols();

        if (board[m][n] == nullptr) {
            if (type == 'X') {
                this->createDoodlebug(m,n);
                critterCounter++;
            }

            if (type == 'O') {
                this->createAnt(m,n);
                critterCounter++;
            }
        }
    }
}

/**************************************************************************
 * Interate through the board and move all doodlebugs first, starve and breed.
 * Then attempt to move all ants and breed the remaining.
 * ***********************************************************************/
void Game::makeMoves() {
    moveAllDoodlebugs();
    starveAllDoodlebugs();
    breedAllDoodlebugs();
    moveAllAnts();
    breedAllAnts();
    resetHasMovedFlags();
}

/***********************************************************
 * Iterate through the board and attempt to move all
 * doodlebugs that haven't already been moved.
 * ********************************************************/
void Game::moveAllDoodlebugs() {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != nullptr) {
				if (board[i][j]->getHasMoved() == false && board[i][j]->getBugType() == 'X') {
					board[i][j]->move(board, rows, cols);
				}
			}
		}
	}
}

/*********************************************************
 * Iterate through the board and attempt to move all ants
 * that haven't already been moved.
 * ******************************************************/
void Game::moveAllAnts() {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != nullptr) {
				if (board[i][j]->getHasMoved() == false && board[i][j]->getBugType() == 'O') {
					board[i][j]->move(board, rows, cols);
				}
			}
		}
	} 
}

/*******************************************************
 * Iterate through the board and kill any doodlebugs that
 * have failed to eat an ant after 3 moves.
 * ****************************************************/
void Game::starveAllDoodlebugs() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (board[i][j] != nullptr) {
                if (board[i][j]->getBugType() == 'X') {
                    if (board[i][j]->getStarveCounter() == 3) {
                        delete board[i][j];
                        board[i][j] = nullptr;
                    }
                }
            }
        }
    }
}

/******************************************************
 * Iterate through the board and attempt to breed any
 * remaining ants that have survived for the past
 * 3 turns.
 * ****************************************************/
void Game::breedAllAnts() {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != nullptr) {
                if (board[i][j]->getBugType() == 'O')
                {
                    board[i][j]->breed(board, rows, cols);
                }
			}
		}
	}
}

/*****************************************************
 * Iterate through the board and attempt to breed any
 * remaining doodlebugs that have survived for at least
 * 8 turns.
 * ***************************************************/
void Game::breedAllDoodlebugs() {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != nullptr) {
                if (board[i][j]->getBugType() == 'X')
                {
                    board[i][j]->breed(board, rows, cols);
                }
			}
		}
	}
}

/****************************************************
 * Iterate through the board and reset the hasMoved
 * flag for all critters in preparation for the next
 * turn.
 * *************************************************/
void Game::resetHasMovedFlags() {
    for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] != nullptr) {
				board[i][j]->setHasMovedFalse();
			}
		}
	}
}

/*****************************************************
 * Get the number of ants from the user and place the
 * appropriate amount of ants on the board.
 * **************************************************/
void Game::setAntCount() {
    int remainingSpaces = cols * rows;
	cout << "Enter the number of ants (Max: " << remainingSpaces << "): ";
	bool validInput = false;
	do {
		menu.promptUserChoice();
		numAnts = menu.getUserChoice();
		if (numAnts >= 0 && numAnts <= remainingSpaces) {
			this->placeCritters(numAnts, 'O');
			validInput = true;
		} else {
			cout << "Invalid entry. Please try again." << endl;
		}
	} while (validInput == false);
}

/*****************************************************
 * Get the number of doodlebugs from the user and place
 * the appropriate amount of doodlebugs on the board.
 * ***************************************************/
void Game::setDoodleCount() {
    int remainingSpaces = (cols * rows) - numAnts;
	cout << "Enter the number of doodlebugs (Max: " << remainingSpaces << "): ";
	bool validInput = false;
	do {
		menu.promptUserChoice();
		numDoodles = menu.getUserChoice();
		if (numDoodles >= 0 && numDoodles <= remainingSpaces) {
			this->placeCritters(numDoodles, 'X');
			validInput = true;
		} else {
			cout << "Invalid entry. Please try again." << endl;
		}
	} while (validInput == false);
}

/*****************************************************
 * Make moves and print the updated board until the
 * user specified number of steps have been completed.
 * ***************************************************/
void Game::runSimulation() {
    for (int i = 0; i < this->getTimeStep(); i++)
	{
		moveCount++;
        cout << "----------------------------" << endl;
		cout << "MOVE " << moveCount << endl;
		this->makeMoves();
		this->printBoard();
		cout << endl;
	}
}