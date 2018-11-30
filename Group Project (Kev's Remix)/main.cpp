/*************************************************************
 * Program Name: Predator/Prey - Main
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: This contains the menus, user input prompts,
 * and simulation flow loops for the predator/prey program.
 * **********************************************************/
#include "Game.hpp"
#include "Critter.hpp"
#include "Menu.hpp"

#include <iostream>
#include <ctime>
using std::cout;
using std::endl;


/*****************************************************************
 * Seed random for later use. Run the simulation at least one time,
 * then present the user with a menu to either continue the simulation
 * or exit the program.
 * **************************************************************/
int main() {
    srand(time(NULL));
	Menu replay;
	Game game;

	cout << "Welcome to the Doodlebug simulation!" << endl;
	cout << "EXTRA CREDIT HAS BEEN INCLUDED!" << endl;
	cout << endl;

	//Initialize the simulation objects
	game.setTimeStep();
	game.setRows();
	game.setCols();
	game.createBoard();
	game.setAntCount();
	game.setDoodleCount();

	//Print the initial state of the board
	cout << "----------------------------" << endl;
	cout << "Initializing Board" << endl << endl;
	game.printBoard();
	cout << endl;

	//Run the simulation the prompt to exit or continue the simulation
	bool exitFlag = false;
	do {
		game.runSimulation();

		game.setTimeStep();
		std::cout << "1. Start simulation again" << std::endl;
		std::cout << "2. Exit Program" << std::endl;
		bool validInput = false;
		do {
			replay.promptUserChoice();
			int choice = replay.getUserChoice();
			if (choice == 1 || choice == 2) {
				switch (choice) {
					case 1 : validInput = true;
							 break;

					case 2 : validInput = true;
							 exitFlag = true;
							 break;
				}
			}
		} while (validInput == false);
	} while (exitFlag == false);

    return 0;
}
