/*****************************************************************************
 * Program name: GhostRoom
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: GhostRoom is a derivative class of the abstract base class
 * Space. GhostRoom gives contains the win condition for the whole game
 * as long as the user has retrieved the candle and has more than 75 courage.
*****************************************************************************/

#ifndef GHOSTROOM_HPP
#define GHOSTROOM_HPP

#include "Space.hpp"

class GhostRoom : public Space {
private:
protected:
public:
    ~GhostRoom();
    void playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle);
};


#endif
