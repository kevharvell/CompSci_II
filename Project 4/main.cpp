
#include "Game.hpp"

#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

int main() {
    // seed random
    srand(time(0));

    // Create Start Menu
    Menu startMenu;
    startMenu.addOption("Play");
    startMenu.addOption("Exit");

    // Create Continue Menu
    Menu continueMenu;
    continueMenu.addOption("Play again");
    continueMenu.addOption("Exit");

    cout << "Welcome to Fantasy Combat Tournament!" << endl;
    // Get initial user choice to play or not
    startMenu.printOptions();
    startMenu.promptUserChoice();

    // If user wants to play, proceed
    if(startMenu.getUserChoice() == 1)
    {
        do {
            // Create and run game
            Game game;
            game.runGame();

            // Game is over, ask to keep playing
            continueMenu.printOptions();
            continueMenu.promptUserChoice();

        } while(continueMenu.getUserChoice() != 2);
    }

    return 0;
}