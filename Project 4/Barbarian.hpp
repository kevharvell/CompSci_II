/*****************************************************************************
 * Program name: Barbarian
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Barbarian class is a derivative of Character class. Its unique
 * attributes are having 2 D6 rolls for attack, 2 D6 rolls for defense, 0 armor,
 * and 12 strength points.
*****************************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
private:
protected:
public:
    Barbarian();
    virtual int attack() override;
    virtual int defense() override;
    virtual void recover() override;
};

#endif
