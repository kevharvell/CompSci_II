/*****************************************************************************
 * Program name: Dice War
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: Dice war is a 2-player game played with dice.
 * Rules: the player who rolls higher numner gets one point. If both players
 * roll the same number, it is considered a draw and no one gets a point.
 * There are two kinds of dice: normal die, represented by Die class; and
 * loaded die, represented by the loadedDie class.
*****************************************************************************/

#include <iostream>
#include <ctime>
#include <random>
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // Initialize random seed
    srand(time(0));

    // Create Game, Start Menu
    Game game;
    game.createStartMenu();
    game.startMenu();
    game.playOrQuit();

    return 0;
}