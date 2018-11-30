/*****************************************************************************
 * Program name: ZooTycoon
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Zoo tycoon is a game that allows players to run a zoo business.
 * Different types of animals cost different prices, have different
 * maintenance costs, and of course, return a different profit at the end of
 * each day. For this game, the player will be the proud owner of a virtual
 * zoo that has spaces to house tigers, penguins and turtles.
*****************************************************************************/
#include <iostream>
#include <ctime>

#include "Menu.hpp"
#include "Zoo.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // seed random
    srand(time(0));

    // Create the zoo
    Zoo zoo;
    zoo.startZoo();

    // Create play menu for game
    Menu menu;
    menu.addOption("Keep playing");
    menu.addOption("End game");

    // Run the zoo day after day as long as the user wants to and money allows
    do {
        zoo.liveDay();
        menu.printOptions();
        menu.promptUserChoice();
    }
    while(menu.getUserChoice() != 2 && zoo.getMoney() > 0);

    if(zoo.getMoney() <= 0)
    {
        cout << "Sorry, you're out of money! Game over!" << endl;
    }
}