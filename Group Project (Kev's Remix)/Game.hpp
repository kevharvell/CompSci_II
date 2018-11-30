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

#ifndef GAME_HPP
#define GAME_HPP

#include "Critter.hpp"
#include "Menu.hpp"

class Game
{
private:
    int timeStep;   //number of turns to run
    int rows;
    int cols;
    int numAnts;
    int numDoodles;
    int moveCount;  //running total of all moves for all sim runs
    Menu menu;
    InputValidation validate;
    Critter*** board;

public:
    Game();
    ~Game();
    void createBoard();
    void printBoard();
	void setTimeStep();
	int getTimeStep();
	void setRows();
	int getRows();
	void setCols();
	int getCols();
    Critter*** getBoard();
    void createAnt(int row, int col);
	void createDoodlebug(int row, int col);
    void placeCritters(int, char);
    void makeMoves();
    void moveAllDoodlebugs();
    void moveAllAnts();
    void starveAllDoodlebugs();
    void breedAllAnts();
    void breedAllDoodlebugs();
    void resetHasMovedFlags();
    void setAntCount();
    void setDoodleCount();
    void runSimulation();

};

#endif
