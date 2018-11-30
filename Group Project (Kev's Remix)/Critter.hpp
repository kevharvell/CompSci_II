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

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Critter
{
private:
protected:
    int rowPos;
    int colPos;
    char bugType;
    int breedCounter;
	bool hasMoved;
public:
    Critter() {};
    Critter(int, int);
	virtual ~Critter() {};
    virtual void move(Critter***, int, int) = 0;
	virtual void breed(Critter***, int, int) = 0;
    virtual int getStarveCounter() = 0;
    char getBugType();
	int getBreedCounter();
	void setBreedCounter(int);
    void setRow(int);
    void setCol(int);
	void setHasMovedFalse();
	bool getHasMoved();
    enum Orientation {UP, RIGHT, DOWN, LEFT};
};

#endif
