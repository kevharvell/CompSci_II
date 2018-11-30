/*****************************************************************************
 * Program name: CandleRoom
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: CandleRoom is a derivative class of the abstract base class
 * Space. CandleRoom gives the candle to the user as long ast their courage is
 * over 50.
*****************************************************************************/

#ifndef CANDLEROOM_HPP
#define CANDLEROOM_HPP

#include "Space.hpp"

class CandleRoom : public Space {
private:
protected:
public:
    ~CandleRoom();
    void playSpace(int &courageIn, bool &hasCandle, bool &ghostHasCandle);
};

#endif
