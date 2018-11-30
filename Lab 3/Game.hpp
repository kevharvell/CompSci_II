/*****************************************************************************
 * Program name: Game
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: The Game class implements the dice-rolling war game. It first
 * creates a start menu. Then it asks the user for the game settings. It prints
 * the results of each round and the final results.
*****************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Menu.hpp"
#include "InputValidation.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

class Game
{
private:
    Menu startMenuObj;
    Menu dieMenuObj;
    InputValidation validate;
    int rounds;
    int p1DieChoice;
    int p2DieChoice;
    int p1Sides;
    int p2Sides;
    int p1Score = 0;
    int p2Score = 0;

    void getSettings();
    void getResults();
    void whoWonRound(int, int);
    void whoWonGame();
    void createDieMenu();
    void dieMenu();

public:
    void createStartMenu();
    void startMenu();
    void playOrQuit();
};


#endif
