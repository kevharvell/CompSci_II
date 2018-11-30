/*****************************************************************************
 * Program name: Blue Men
 * Author: Kevin Harvell
 * Date: 5/2/2018
 * Description: Blue Men class is a derivative of Character class. Its unique
 * attributes are having 2 D10 rolls for attack, 3 D6 rolls for defense, 3 armor,
 * and 12 strength points. The amount of D6 dice for defense goes down 1 for
 * every 4 damage Blue Men takes.
*****************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Character.hpp"

class BlueMen : public Character
{
private:
protected:
public:
    BlueMen();
    virtual int attack() override;
    virtual int defense() override;
    virtual void recover() override;
};

#endif
