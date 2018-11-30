/*****************************************************************************
 * Program name: Room
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Room is a derivative class of the abstract base class
 * Space. Room randomly adds or subtracts 0 to 25 courage to the user's
 * courage variable.
*****************************************************************************/

#include "Room.hpp"
#include <iostream>

using std::cout;
using std::endl;

Room::~Room() {

}

/*****************************************************************************
 * playSpace is a virtual function from the abstract base class Space. It
 * controls the game flow for Room Spaces.
*****************************************************************************/

void Room::playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle) {
    int randNum = rand() % 51 + (-25);
    cout << "The floorboards creak as you step foot in the room. There it is again!" << endl;
    cout << "The faint howling..." << endl;
    cout << "You stand frozen trying to get the courage to move on." << endl;
    cout << "Your courage changes by " << randNum << endl;
    courageIn += randNum;
}


