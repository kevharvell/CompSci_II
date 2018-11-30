/*****************************************************************************
 * Program name: Animal
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Animal is a base class for the animals at the zoo, containing
 * the following animal attributes: age, cost, number of babies, base food cost,
 * and payoff.
*****************************************************************************/

#include <iostream>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Zoo.hpp"

using std::cout;
using std::endl;


Animal::Animal() {

}

Animal::Animal(int age = 1, int cost = 0, int numBabies = 0, int baseFoodCost = 10, int payOff = 0)
    : m_age(age), m_cost(cost), m_numBabies(numBabies), m_baseFoodCost(baseFoodCost), m_payOff(payOff)
{

}

/*****************************************************************************
 *                          isAdult()
 * isAdult checks to see if the animal is an adult (age >= 3). If so, it returns
 * true.
*****************************************************************************/
bool Animal::isAdult()
{
    if(m_age >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************************************
 *                          ageUp()
 * ageUp ages the animal by one day.
*****************************************************************************/
void Animal::ageUp() {
    m_age++;
}

int Animal::getCost() {
    return m_cost;
}

int Animal::getBaseFoodCost() {
    return m_baseFoodCost;
}

int Animal::getPayOff() {
    return m_payOff;
}






