/*****************************************************************************
 * Program name: Penguin
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Penguin is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/

#include "Penguin.hpp"

Penguin::Penguin(int age)
    : Animal(1, 1000, 5, 10, 100)
{
    m_age = age;
}
