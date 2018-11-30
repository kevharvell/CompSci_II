/*****************************************************************************
 * Program name: Animal
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Animal is a base class for the animals at the zoo, containing
 * the following animal attributes: age, cost, number of babies, base food cost,
 * and payoff.
*****************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:


protected:
    int m_age = 1;
    int m_cost = 0;
    int m_numBabies = 0;
    int m_baseFoodCost = 10;
    int m_payOff = 0;


public:
    Animal();
    Animal(int age, int cost, int numBabies, int baseFoodCost, int payOff);
    int getCost();
    int getBaseFoodCost();
    int getPayOff();
    void ageUp();
    bool isAdult();
};

#endif
