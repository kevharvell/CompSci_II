/*****************************************************************************
 * Program name: Medusa
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Medusa class is a derivative of Character class. Its unique
 * attributes are having 2 D6 rolls for attack, 1 D6 rolls for defense, 3 armor,
 * and 8 strength points. It also has an ability 'Glare' that instantly kills
 * the enemy.
*****************************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
private:
protected:
public:
    Medusa();
    virtual int attack() override;
    virtual int defense() override;
    virtual void recover() override;
};

#endif
