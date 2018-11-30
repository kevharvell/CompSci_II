/*****************************************************************************
 * Program name: Turtle
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Turtle is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal
{
private:

public:
    Turtle(int age);

};

#endif
