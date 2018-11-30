/*****************************************************************************
 * Program name: Turtle
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Turtle is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/

#include "Turtle.hpp"

Turtle::Turtle(int age)
    : Animal(1, 100, 10, 5, 5)
{
    m_age = age;
}
