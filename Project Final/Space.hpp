/*****************************************************************************
 * Program name: Space
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Space is an abstract base class representing room spaces in a
 * haunted house.
*****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

class Space {
private:

protected:

public:
    virtual ~Space() = 0;

    Space* top;
    Space* right;
    Space* bottom;
    Space* left;

    virtual void playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle) = 0;
};

#endif
