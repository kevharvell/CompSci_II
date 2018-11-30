/******************************************************************
** Program Name: Group Project
** Author Name: Group 3
** Date: 5 May 2018
** Description: Implementation file for Game class.  This class
** control general game flow, dynamically creates the board for
** the game, and controls input validation.
******************************************************************/

#include "Game.hpp"
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game()
{
	timeStep = 0;
	boardSize = 0;
	rows = 0;
	cols = 0;
	board;
}

Game::~Game()
{

}

void Game::createBoard()
{
	board = new Critter** [boardSize];
	for (int i = 0; i < boardSize; i++)
	{
		board[i] = new Critter* [boardSize];
	}

	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			board[i][j] = nullptr;
		}
	}
}

void Game::deleteBoard()
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (board[i][j] != nullptr)
			{
				delete board[i][j];
				board[i][j] = nullptr;
			}
		}
		if (board[i] != nullptr)
		{
			delete[] board[i];
			board[i] = nullptr;
		}
	}
	delete[] board;
	board = nullptr;
}

void Game::setBoardSize(int n)
{
	this->boardSize = n;
}

int Game::getBoardSize()
{
	return this->boardSize;
}

Critter*** Game::getBoard()
{
	return this->board;
}

void Game::setRows(int n)
{
	this->rows = n;
}

int Game::getRows()
{
	return this->rows;
}

void Game::setCols(int n)
{
	this->cols = n;
}

int Game::getCols()
{
	return this->cols;
}

void Game::createDoodlebug(int r, int c)
{
	this->board[r][c] = new Doodlebug(r, c);
}

void Game::printBoard()
{
	for (int i = 0; i < getBoardSize(); i++)
	{
		for (int j = 0; j < getBoardSize(); j++)
		{
			if (board[i][j] != nullptr)
			{
				cout << board[i][j]->getBugType();
			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
	}
}