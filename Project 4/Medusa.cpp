/*****************************************************************************
 * Program name: Medusa
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Medusa class is a derivative of Character class. Its unique
 * attributes are having 2 D6 rolls for attack, 1 D6 rolls for defense, 3 armor,
 * and 8 strength points. It also has an ability 'Glare' that instantly kills
 * the enemy.
*****************************************************************************/

#include "Medusa.hpp"
#include "Die.hpp"

#include <iostream>

using std::cout;

Medusa::Medusa() {
    m_type = "Medusa";
    m_armor = 3;
    m_strength = 8;
}

/*****************************************************************************
 *                              attack()
 * attack rolls a D6 Die object twice to get the attack value of Medusa.
 * If the rolls add up to 12, Medusa uses 'Glare' for an instant kill.
*****************************************************************************/

int Medusa::attack() {
    Die attackDie(6);
    m_attackVal = attackDie.getRandomInt() + attackDie.getRandomInt();
    // If the rolls add up to 12, Medusa uses 'Glare' for an instant kill.
    if(m_attackVal == 12)
    {
        m_attackVal = -1;
        return m_attackVal;
    }
    return m_attackVal;
}

/*****************************************************************************
 *                              defense()
 * defense rolls a D6 Die object once to get the defense value of Medusa.
*****************************************************************************/

int Medusa::defense() {
    Die defenseDie(6);
    m_defenseVal = defenseDie.getRandomInt();
    return m_defenseVal;
}

/*****************************************************************************
 *                              recover()
 * recover restores 50% of strength up to maximum strength.
*****************************************************************************/

void Medusa::recover() {
    int recoverHalf = (8 - m_strength) * .5;
    m_strength += recoverHalf;
}