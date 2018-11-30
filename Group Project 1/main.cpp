#include "Critter.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"
#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Critter*** tempBoard;
	Game game;
	int temp;
	srand(time(NULL));

	cout << "Please enter desired board size: ";
	cin >> temp; 
	game.setBoardSize(temp);
	game.createBoard();
	tempBoard = game.getBoard();
	temp = game.getBoardSize();
	
	game.createDoodlebug(temp/2, temp/2);

	game.printBoard();

	game.deleteBoard();

	return 0;
}