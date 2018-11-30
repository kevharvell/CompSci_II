/*****************************************************************************
* Program Name: Menu
* Author: Eric Pass
* Date: 4/3/2018
* Description: Menu is a class that can be reused in later programs.
* Menu functions print menu options to the screen for the user, and after
* the user makes a choice, verify the user's input, and return the value back
* to the program.
*****************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "InputValidation.hpp"

class Menu
{
	private:
		InputValidation validate;
		std::vector<std::string> menuOptions;
		int userChoice;
	public:
		void addOption(std::string option);
		void printOptions();
		void promptUserChoice();
		int getUserChoice();
};

#endif
