/*****************************************************************************
 * Program name: Vampire
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Vampire class is a derivative of Character class. Its unique
 * attributes are having 1 D12 roll for attack, 1 D6 roll for defense, 1 armor,
 * and 18 strength points. It also has an ability 'Charm' that denies damage
 * from the enemy 50% of the time.
*****************************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
private:

protected:
public:
    Vampire();
    virtual int attack();
    virtual int defense() override;
    virtual void recover() override;

    bool isCharmed();

};

#endif
