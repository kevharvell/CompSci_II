/*************************************************************************
** Program name: Critter
** Author: Group 3
** Date: 4/30/2018
** Description:
*************************************************************************/

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
		Critter*** boardPtr = nullptr;
	public:
		Critter();
		~Critter();
		virtual void move() = 0;
		virtual void breed() = 0;
		virtual char getBugType() = 0;
		virtual void setRow(int) = 0;
		virtual void setCol(int) = 0;
};

#endif