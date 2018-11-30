/*************************************************************
 * Program Name: Predator/Prey - Critter Class
 * Author: Ann Fay
 *         Kyle Garland
 *         Kevin Harvell
 *         John Lambert
 *         Eric Pass
 * Date: 5/7/2018
 * Description: This is an abstract class which contains some
 * basic counters and coordinates as well as serving
 * as an interface for the following child classes:
 * 
 * Ant
 * Doodlebug
 * **********************************************************/

#include "Critter.hpp"


Critter::Critter(int rowPosIn, int colPosIn) 
{
    this->rowPos = rowPosIn;
    this->colPos = colPosIn;
	this->breedCounter = 0;
	this->hasMoved = false;
}

char Critter::getBugType() 
{
    return bugType;
}

int Critter::getBreedCounter()
{
	return this->breedCounter;
}

void Critter::setBreedCounter(int n)
{
	this->breedCounter = n;
}

void Critter::setRow(int n)
{
	this->rowPos = n;
}

void Critter::setCol(int n)
{
	this->colPos = n;
}

void Critter::setHasMovedFalse()
{
	this->hasMoved = false;
}

bool Critter::getHasMoved()
{
	return this->hasMoved;
}