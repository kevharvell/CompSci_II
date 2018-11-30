/*****************************************************************************
 * Program name: CandleRoom
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: CandleRoom is a derivative class of the abstract base class
 * Space. CandleRoom gives the candle to the user as long ast their courage is
 * over 50.
*****************************************************************************/

#include "CandleRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;

CandleRoom::~CandleRoom() {

}

/*****************************************************************************
 * playSpace is a virtual function from the abstract base class Space. It
 * controls the game flow for CandleRoom Spaces.
*****************************************************************************/

void CandleRoom::playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle) {
    cout << "The floorboards creak as you step foot in the room. There it is again!" << endl;
    cout << "The faint howling..." << endl;
    cout << "In the corner of the room a candle flickers casting shadows on the walls." << endl;
    cout << "You remember the note from when you entered this terrifying abode." << endl;
    cout << "You might need this candle to exorcise the ghost!" << endl;

    // If courage is 50 or more, user can get the candle
    if(courageIn >= 50)
    {
        cout << "You courageously reach out and grab the candle. That wasn't so bad..." << endl;
        hasCandle = true;
    }
    // Courage is too low. User cannot get the candle yet
    else
    {
        cout << "You are way too scared to collect the candle. You need more courage!" << endl;
    }
}


