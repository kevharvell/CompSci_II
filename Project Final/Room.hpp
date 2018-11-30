/*****************************************************************************
 * Program name: Room
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Room is a derivative class of the abstract base class
 * Space. Room randomly adds or subtracts 0 to 25 courage to the user's
 * courage variable.
*****************************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Space.hpp"

class Room : public Space {
private:
protected:
public:
    ~Room();
    void playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle) override;
};


#endif
