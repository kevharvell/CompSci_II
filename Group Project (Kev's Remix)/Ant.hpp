/*************************************************************
 * Program Name: Predator/Prey - Ant Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: A child class of Critter. This contains the
 * move, breed, and starve functions for the ant critters.
 * **********************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include "Game.hpp"

//#include <ctime>

class Ant : public Critter
{
public:
	Ant(int, int);
	void move(Critter***, int, int);
	void breed(Critter***, int, int);
	int getStarveCounter() {return 0;}; //no starve counter for ants
};

#endif