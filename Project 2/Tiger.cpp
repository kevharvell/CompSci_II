/*****************************************************************************
 * Program name: Tiger
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Tiger is a specific class that inherits the properties of the
 * Animal class and assigns its properties to its own specific attributes.
*****************************************************************************/

#include "Tiger.hpp"

Tiger::Tiger(int age = 1)
    : Animal(1, 10000, 1, 50, 2000)
{
    m_age = age;
}


