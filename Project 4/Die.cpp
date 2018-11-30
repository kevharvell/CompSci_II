/*****************************************************************************
 * Program name: Die
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: Die class has a member variable of an integer N that represents
 * the number of sides on the individual die. It also has a member function that
 * returns a random integer between 1 and N as the result of rolling the die
 * once.
*****************************************************************************/

#include "Die.hpp"
#include <cstdlib>

// Default constructor sets die to have 6 sides.
Die::Die()
{
    numSides = 6;
}

Die::Die(int numSides)
{
    this->numSides = numSides;
}

int Die::getSides() {
    return numSides;
}

/*****************************************************************************
 *                          getRandomInt()
 * getRandomInt returns a random integer between 1 and the number of sides that
 * the die has.
*****************************************************************************/
int Die::getRandomInt()
{
    return rand() % getSides() + 1;
}
