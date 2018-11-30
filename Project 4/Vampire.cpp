/*****************************************************************************
 * Program name: Vampire
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Vampire class is a derivative of Character class. Its unique
 * attributes are having 1 D12 roll for attack, 1 D6 roll for defense, 1 armor,
 * and 18 strength points. It also has an ability 'Charm' that denies damage
 * from the enemy 50% of the time.
*****************************************************************************/
#include "Vampire.hpp"
#include "Die.hpp"

#include <iostream>

Vampire::Vampire()
{
    m_type = "Vampire";
    m_armor = 1;
    m_strength = 18;
}

/*****************************************************************************
 *                              attack()
 * attack rolls a D12 Die object once to get the attack value of the Vampire.
*****************************************************************************/

int Vampire::attack()
{
    Die attackDie(12);
    m_attackVal = attackDie.getRandomInt();
    return m_attackVal;
}

/*****************************************************************************
 *                              defense()
 * defense rolls a D6 Die object once to get the defense value of the Vampire.
 * There's a 50% chance of using the 'Charm' ability, which blocks all damage
 * Vampire takes.
*****************************************************************************/

int Vampire::defense()
{
    if(isCharmed())
    {
        m_defenseVal = 100000;
        return m_defenseVal;
    }
    else {
        Die defenseDie(6);
        m_defenseVal = defenseDie.getRandomInt();
        return m_defenseVal;
    }
}

/*****************************************************************************
 *                              recover()
 * recover restores 50% of strength up to maximum strength.
*****************************************************************************/

void Vampire::recover() {
    int recoverHalf = (18 - m_strength) * .5;
    m_strength += recoverHalf;
}

/*****************************************************************************
 *                              isCharmed()
 * isCharmed flips a coin and on one hand, it uses the ability 'Charm', while
 * on the other, it does not.
*****************************************************************************/

bool Vampire::isCharmed()
{
    Die charm(2);
    int coinFlip = charm.getRandomInt();
    if(coinFlip == 1)
    {
        return true;
    }
    if(coinFlip == 2)
    {
        return false;
    }
}
