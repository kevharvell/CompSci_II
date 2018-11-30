/*****************************************************************************
 * Program name: Penguin
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Penguin is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal
{
private:
public:
    Penguin(int age);

};

#endif