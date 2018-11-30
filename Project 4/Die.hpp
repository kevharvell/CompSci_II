/*****************************************************************************
 * Program name: Die
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: Die class has a member variable of an integer N that represents
 * the number of sides on the individual die. It also has a member function that
 * returns a random integer between 1 and N as the result of rolling the die
 * once.
*****************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
    int numSides;
public:
    Die();
    Die(int);
    int getSides();
    int getRandomInt();
};

#endif
