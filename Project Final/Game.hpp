/*****************************************************************************
 * Program name: Game
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Game is the main engine for the flow of the Haunted House game.
 * It creates the haunted house as a linked list-like object. Prints the house
 * each turn. Controls the gameplay for each turn.
*****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "InputValidation.hpp"
#include "Menu.hpp"

class Game {
private:
    enum Orientation {UP = 1, RIGHT = 2, DOWN = 3, LEFT = 4};

    Menu moveMenu;
    InputValidation validate;

    Space* room1;
    Space* room2;
    Space* room3;
    Space* room4;
    Space* candleRoom;
    Space* ghostRoom;
    Space* currentRoom;

    int courage = 50;
    int numMoves = 0;
    const int MAX_MOVES = 10;
    bool hasCandle;
    bool ghostHasCandle;

    void createHouse();
    void printHouse();
    void start();
    void displayStats();
    void makeMove();
protected:
public:
    Game();
    ~Game();
    void playGame();
};


#endif
