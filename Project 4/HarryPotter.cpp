/*****************************************************************************
 * Program name: Harry Potter
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Harry Potter class is a derivative of Character class. Its unique
 * attributes are having 2 D6 rolls for attack, 2 D6 rolls for defense, 0 armor,
 * and 10 strength points. When Harry Potter dies or is 'Glared' on by Medusa,
 * he is revived with 20 strength points. If he dies after this, he's dead for
 * real.
*****************************************************************************/
#include "HarryPotter.hpp"
#include "Die.hpp"

#include <iostream>

using std::cout;

HarryPotter::HarryPotter() {
    m_type = "Harry Potter";
    m_armor = 0;
    m_strength = 10;
}

/*****************************************************************************
 *                              attack()
 * attack rolls a D6 Die object twice to get the attack value of Harry Potter.
*****************************************************************************/

int HarryPotter::attack() {
    Die attackDie(6);
    m_attackVal = attackDie.getRandomInt() + attackDie.getRandomInt();
    return m_attackVal;
}

/*****************************************************************************
 *                              defense()
 * defense rolls a D6 Die object twice to get the defense value of Harry Potter.
*****************************************************************************/

int HarryPotter::defense() {
    Die defenseDie(6);
    m_defenseVal = defenseDie.getRandomInt() + defenseDie.getRandomInt();
    return m_defenseVal;
}

/*****************************************************************************
 *                              recover()
 * recover restores 50% of strength up to maximum strength.
*****************************************************************************/

void HarryPotter::recover() {
    int recoverHalf;
    if(m_lives == 1) {
        recoverHalf = (10 - m_strength) * .5;
        m_strength += recoverHalf;
    } else if(m_lives == 0)
    {
        recoverHalf = (20 - m_strength) * .5;
        m_strength += recoverHalf;
    }
}

/*****************************************************************************
 *                              takeDamageFrom()
 * takeDamageFrom assigns damage from a Character pointer to an enemy to this
 * Character. It has a few checks to check for certain Character's abilities,
 * such as: Vampire's Charm, Medusa's Glare, and Harry Potter's Hogwarts.
 * This function is virtual and overridden for Harry Potter because Harry Potter
 * is able to revive if killed once.
*****************************************************************************/

void HarryPotter::takeDamageFrom(Character *enemy) {
    m_damage = enemy->getAttack() - this->getDefense() - this->getArmor();

    // Check for Medusa's Glare
    if(enemy->getAttack() == -1)
    {
        m_damage = 100000;
        this->m_strength -= m_damage;
    }
        // Check for valid damage amount
    else if(m_damage > 0)
    {
        this->m_strength -= m_damage;
    }
        // Damage is negative, thus no damage is assigned
    else
    {
        m_damage = 0;
    }

    // Check to see if Harry Potter is dying for the first time.
    // If so, reduce lives and revive to strength 20
    if(m_strength <= 0 && m_lives == 1)
    {
        m_lives -= 1;
        m_strength = 20;
    }
}


