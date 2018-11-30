/*****************************************************************************
 * Program name: Tiger
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Tiger is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/
#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal
{
private:

public:
    Tiger(int age);
};

#endif
