/*****************************************************************************
 * Program name: Blue Men
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Blue Men class is a derivative of Character class. Its unique
 * attributes are having 2 D10 rolls for attack, 3 D6 rolls for defense, 3 armor,
 * and 12 strength points. The amount of D6 dice for defense goes down 1 for
 * every 4 damage Blue Men takes.
*****************************************************************************/
#include "BlueMen.hpp"
#include "Die.hpp"

#include <cmath>

BlueMen::BlueMen() {
    m_type = "Blue Men";
    m_armor = 3;
    m_strength = 12;
}

/*****************************************************************************
 *                              attack()
 * attack rolls a D10 Die object twice to get the attack value of the Blue Men.
*****************************************************************************/

int BlueMen::attack() {
    Die attackDie(10);
    m_attackVal = attackDie.getRandomInt() + attackDie.getRandomInt();;
    return m_attackVal;
}

/*****************************************************************************
 *                              defense()
 * defense rolls a D6 Die object thrice to get the defense value of the Blue Men.
 * The roll count goes down by 1 for every 4 damage Blue Men takes.
*****************************************************************************/

int BlueMen::defense() {
    Die defenseDie(6);
    // Find out how many times to roll D6 die by dividing strength by 4 and
    // rounding up.
    int rolls = ceil(static_cast<double>(m_strength) / 4.0);
    int rollSum = 0;
    for(int i = 0; i < rolls; i++)
    {
        rollSum += defenseDie.getRandomInt();
    }
    m_defenseVal = rollSum;
    return m_defenseVal;
}

/*****************************************************************************
 *                              recover()
 * recover restores 50% of strength up to maximum strength.
*****************************************************************************/

void BlueMen::recover() {
    int recoverHalf = (12 - m_strength) * .5;
    m_strength += recoverHalf;
}
