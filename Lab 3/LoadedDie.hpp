/*****************************************************************************
 * Program name: LoadedDie
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: LoadedDie class inherits the behavior and elements of Die class.
 * However, for the die rolling function, the number it returns is biased such
 * that the average output is higher than that of a Die object with the same
 * number of sides.
*****************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie: public Die
{
private:
public:
    LoadedDie(int);
    int getLoadedRandomInt();
};

#endif
