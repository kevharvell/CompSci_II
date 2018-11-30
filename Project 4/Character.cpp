/*****************************************************************************
 * Program name: Character
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Character is an abstract base class. All the characters have
 * their own subclass that inherits from this class.
*****************************************************************************/
#include "Character.hpp"

using std::string;

string Character::getType() {
    return this->m_type;
}

int Character::getArmor() {
    return this->m_armor;
}

int Character::getStrength() {
    return this->m_strength;
}

/*****************************************************************************
 *                              takeDamageFrom()
 * takeDamageFrom assigns damage from a Character pointer to an enemy to this
 * Character. It has a few checks to check for certain Character's abilities,
 * such as: Vampire's Charm, Medusa's Glare, and Harry Potter's Hogwarts.
*****************************************************************************/

void Character::takeDamageFrom(Character* enemy) {
    m_damage = enemy->getAttack() - this->getDefense() - this->getArmor();
    // Check for Vampire's Charm
    if(this->getDefense() == 100000)
    {
        m_damage = 0;
    }
    // Check for Medusa's Glare
    else if(enemy->getAttack() == -1)
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
}

void Character::setName(string name) {
    m_name = name;
}

std::string Character::getName() {
    return m_name;
}

int Character::getDamage() {
    return m_damage;
}

int Character::getDefense() {
    return m_defenseVal;
}

int Character::getAttack() {
    return m_attackVal;
}



