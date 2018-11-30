/******************************************************************
** Program Name: Group Project
** Author Name: Group 3
** Date: 5 May 2018
** Description: Header file for Game class.
******************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Critter.hpp"
#include "doodlebug.hpp"

class Game
{
	private:
		int timeStep;
		int boardSize;
		int rows;
		int cols;
		Critter*** board;
	protected:
	public:
		Game();
		~Game();
		void createBoard();
		void deleteBoard();
		void setBoardSize(int);
		int getBoardSize();
		Critter*** getBoard();
		void setRows(int);
		int getRows();
		void setCols(int);
		int getCols();
		void createDoodlebug(int, int);
		void printBoard();
		void makeMoves();
};

#endif