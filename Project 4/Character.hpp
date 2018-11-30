/*****************************************************************************
 * Program name: Character
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Character is an abstract base class. All the characters have
 * their own subclass that inherits from this class.
*****************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
private:
protected:
    std::string m_type = "";
    std::string m_name = "";
    int m_armor = 0;
    int m_strength = 0;
    int m_attackVal;
    int m_defenseVal;
    int m_damage;
public:
    // enum to make code more readable when choosing a character from the menu.
    enum CharacterType {VAMPIRE = 1, BARBARIAN = 2, BLUE_MEN = 3, MEDUSA = 4, HARRY_POTTER = 5};
    std::string getType();
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual void recover() = 0;
    virtual void takeDamageFrom(Character *enemy);
    void setName(std::string name);
    std::string getName();
    int getArmor();
    int getStrength();
    int getAttack();
    int getDefense();
    int getDamage();

};

#endif
