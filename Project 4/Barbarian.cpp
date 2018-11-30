/*****************************************************************************
 * Program name: Barbarian
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Barbarian class is a derivative of Character class. Its unique
 * attributes are having 2 D6 rolls for attack, 2 D6 rolls for defense, 0 armor,
 * and 12 strength points.
*****************************************************************************/

#include "Barbarian.hpp"
#include "Die.hpp"

Barbarian::Barbarian() {
    m_type = "Barbarian";
    m_armor = 0;
    m_strength = 12;
}

/*****************************************************************************
 *                              attack()
 * attack rolls a D6 Die object twice to get the attack value of the Barbarian.
*****************************************************************************/

int Barbarian::attack() {
    Die attackDie(6);
    m_attackVal = attackDie.getRandomInt() + attackDie.getRandomInt();;
    return m_attackVal;
}

/*****************************************************************************
 *                              defense()
 * defense rolls a D6 Die object twice to get the defense value of the Barbarian.
*****************************************************************************/

int Barbarian::defense() {
    Die defenseDie(6);
    m_defenseVal = defenseDie.getRandomInt() + defenseDie.getRandomInt();
    return m_defenseVal;
}

/*****************************************************************************
 *                              recover()
 * recover restores 50% of strength up to maximum strength.
*****************************************************************************/

void Barbarian::recover() {
    int recoverHalf = (12 - m_strength) * .5;
    m_strength += recoverHalf;
}
