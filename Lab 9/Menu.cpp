/*****************************************************************************
* Program name: Menu
* Author: Kevin Harvell
* Date: 4/3/2018
* Description: Menu is a class that can be reused in later programs.
* Menu functions print menu options to the screen for the user, and after
* the user makes a choice, verify the user's input, and return the value back
* to the program.
*****************************************************************************/
#include <iostream>
#include <limits>
#include "Menu.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

/*****************************************************************************
 *                              addOption()
 * addOption adds a string option to the private menuOptions vector
 ****************************************************************************/
void Menu::addOption(string option)
{
    menuOptions.push_back(option);
}
/*****************************************************************************
 *                             printOptions()
 * printOptions loops through the menuOptions vector and prints them to the
 * console in a numbered list.
 ****************************************************************************/
void Menu::printOptions()
{
    for(unsigned i = 1; i <= menuOptions.size(); i++)
    {
        cout << i << ". " << menuOptions[i - 1] << endl;
    }
}
/*****************************************************************************
 *                             promptUserChoice()
 * promptUserChoice calls the getInt(min,max) function from the
 * InputValidation class in order to receive a valid choice from the user.
 * It then stores the input into the private userChoice variable.
 ****************************************************************************/
void Menu::promptUserChoice()
{
    userChoice = validate.getInt(1, menuOptions.size());
}
int Menu::getUserChoice()
{
    return userChoice;
}

void Menu::pressEnter()
{
    cout << "Press ENTER to continue... " << std::flush;
    cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
}
