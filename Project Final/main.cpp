/*****************************************************************************
 * Program name: HauntedHouse
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Haunted House is a game containing 6 spaces linked together
 * with pointers where the player must gain courage while trying to obtain a
 * candle in order to exorcise a ghost from the house.
*****************************************************************************/
#include "Game.hpp"
#include "Space.hpp"
#include <ctime>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(NULL));
    Game hauntedHouse;
    hauntedHouse.playGame();

    return 0;
}