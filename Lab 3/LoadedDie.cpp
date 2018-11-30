/*****************************************************************************
 * Program name: LoadedDie
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: LoadedDie class inherits the behavior and elements of Die class.
 * However, for the die rolling function, the number it returns is biased such
 * that the average output is higher than that of a Die object with the same
 * number of sides.
*****************************************************************************/
#include <random>
#include "LoadedDie.hpp"

LoadedDie::LoadedDie(int numSides) : Die(numSides)
{

}

/*****************************************************************************
 *                          getLoadedRandomInt()
 * getLoadedRandomInt returns a loaded random integer between 1 and the number
 * of sides on the die. It loads the die by randomly adding a 0 or 1 to the roll
 * except in the case where the die rolls its maximum value.
*****************************************************************************/
int LoadedDie::getLoadedRandomInt()
{
    int randomDieRoll = rand() % getSides() + 1;
    int loadedDieWeight = rand() % 2;
    if (randomDieRoll <= getSides() - 1)
    {
        randomDieRoll += loadedDieWeight;
        return randomDieRoll;
    }
    else
    {
        return randomDieRoll;
    }

}
