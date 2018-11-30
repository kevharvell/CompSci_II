/*************************************************************
 * Program Name: Predator/Prey - Doodlebug Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: A child class of Critter. This contains the
 * move(and eat ants), breed, and starve functions for the 
 * doodlebug critters.
 * **********************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter {
    private:
        int starveCounter;
    public:
        Doodlebug(int, int);
        int getStarveCounter();
        void move(Critter***, int, int);
	    void breed(Critter***, int, int);
        void starve(Critter***, int, int);
};

#endif