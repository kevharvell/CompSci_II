#ifndef ANT_HPP
#define ANT_HPP

#include "Critter.hpp"
#include "Game.hpp"

#include <ctime>
#include <cstdlib>

class Ant :
	public Critter
{
private:
	//for random direction
	Orientation dir;
	Game gameBoard;
	//breeds after 3 steps
	char bugType = 'O';
	int numSteps;
	int xPos;
	int yPos;
public:
	//Ant();
	Ant(int, int, char, int);
	~Ant();
	void move(Game);
	void breed();
	char getBugType();

};

#endif