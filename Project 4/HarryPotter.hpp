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
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
private:
    int m_lives = 1;
protected:
public:
    HarryPotter();
    virtual int attack() override;
    virtual int defense() override;
    virtual void recover() override;
    virtual void takeDamageFrom(Character* enemy) override;
};

#endif
