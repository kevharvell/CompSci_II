/*****************************************************************************
 * Program name: GhostRoom
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: GhostRoom is a derivative class of the abstract base class
 * Space. GhostRoom gives contains the win condition for the whole game
 * as long as the user has retrieved the candle and has more than 75 courage.
*****************************************************************************/

#include "GhostRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;

GhostRoom::~GhostRoom() {

}

/*****************************************************************************
 * playSpace is a virtual function from the abstract base class Space. It
 * controls the game flow for GhostRoom Spaces.
*****************************************************************************/

void GhostRoom::playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle) {
    cout << "The floorboards creak as you step foot in the room. There it is again!" << endl;
    cout << "The faint howling..." << endl;
    cout << "It's coming from right in front of you... THE GHOST!!!" << endl;
    cout << "You remember the note from when you entered this terrifying abode." << endl;
    cout << "Use the candle to exorcise the ghost!" << endl;

    // If courage is 75 or more and has the candle,
    // user can exorcise the ghost with the candle and win the game
    if(courageIn >= 75 && hasCandle)
    {
        ghostHasCandle = true;
    }
    // Courage is too low or candle is not owned. Ghost kills the user
    else
    {
        courageIn = 0;
    }
}


