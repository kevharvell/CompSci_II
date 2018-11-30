/*****************************************************************************
 * Program name: Game
 * Author: Kevin Harvell
 * Date: 4/16/2018
 * Description: The Game class implements the dice-rolling war game. It first
 * creates a start menu. Then it asks the user for the game settings. It prints
 * the results of each round and the final results.
*****************************************************************************/
#include <iostream>
#include <string>
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

/*****************************************************************************
 *                          createStartMenu()
 * createStartMenu creates the beginning Start Menu for the game.
*****************************************************************************/
void::Game::createStartMenu()
{
    startMenuObj.addOption("Play game");
    startMenuObj.addOption("Exit Game");
}

/*****************************************************************************
 *                          startMenu()
 * startMenu displays the Start Menu and asks the user to either play or exit
 * the game.
*****************************************************************************/
void Game::startMenu() {
    cout << "\nWelcome to Dice War!\n" << endl;
    startMenuObj.printOptions();
    startMenuObj.promptUserChoice();
}

/*****************************************************************************
 *                          createDieMenu()
 * createDieMenu creates a menu to select between a regular or loaded die.
*****************************************************************************/
void Game::createDieMenu()
{
    dieMenuObj.addOption("Regular Die");
    dieMenuObj.addOption("Loaded Die");
}

/*****************************************************************************
 *                          dieMenu()
 * dieMenu prints the Die Menu and asks the user for their choice between a
 * regular and loaded die.
*****************************************************************************/
void Game::dieMenu()
{
    dieMenuObj.printOptions();
    dieMenuObj.promptUserChoice();
}

/*****************************************************************************
 *                          getSettings()
 * getSettings gets the following settings from the user: number of rounds,
 * type of die for each player, and how many sides for each player's die.
*****************************************************************************/
void Game::getSettings()
{
    cout << "\nHow many rounds will be played? ";
    rounds = validate.getInt(1, 10);

    createDieMenu();
    cout << "\nPlayer 1: What type of die will you use: regular or loaded?\n" << endl;
    dieMenu();
    p1DieChoice = dieMenuObj.getUserChoice();
    cout << "\nPlayer 2: What type of die will you use: regular or loaded?\n" << endl;
    dieMenu();
    p2DieChoice = dieMenuObj.getUserChoice();
    cout << "\nPlayer 1: How many sides on your die? ";
    p1Sides = validate.getInt(2, 20);
    cout << "\nPlayer 2: How many sides on your die? ";
    p2Sides = validate.getInt(2, 20);
}

/*****************************************************************************
 *                          getResults()
 * getResults rolls each player's die based on whether it was regular or loaded.
 * It then compares the two player's rolls to see who won each round, being sure
 * to add to the correct player score. At the end of all the rounds, it displays
 * who won the game.
*****************************************************************************/
void Game::getResults()
{
    for(int i = 1; i <= rounds; i++)
    {
        // Temporary variables for each player's roll
        int p1Roll;
        int p2Roll;
        string p1DieType;
        string p2DieType;

        // Determine Player 1 Die Roll
        // if a regular die
        if(p1DieChoice == 1)
        {
            Die die(p1Sides);
            p1Roll = die.getRandomInt();
            p1DieType = "regular";
        }
        // if a loaded die
        else if(p1DieChoice == 2)
        {
            LoadedDie loadedDie(p1Sides);
            p1Roll = loadedDie.getLoadedRandomInt();
            p1DieType = "loaded";
        }

        // Determine Player 2 Die Roll
        // if a regular die
        if(p2DieChoice == 1)
        {
            Die die(p2Sides);
            p2Roll = die.getRandomInt();
            p2DieType = "regular";
        }
        // if a loaded die
        else if(p2DieChoice == 2)
        {
            LoadedDie loadedDie(p2Sides);
            p2Roll = loadedDie.getLoadedRandomInt();
            p2DieType = "loaded";
        }

        // Display Round results
        cout << "Round " << i << " Results: " << endl;
        cout << "Player 1 rolled a " << p1Sides << "-sided " << p1DieType
             << " die and rolled a " << p1Roll << endl;
        cout << "Player 2 rolled a " << p2Sides << "-sided " << p2DieType
             << " die and rolled a " << p2Roll << endl;
        whoWonRound(p1Roll, p2Roll);
    }
    whoWonGame();
}

/*****************************************************************************
 *                          whoWonRound()
 * whoWonRound determines and outputs which player won the round. It then
 * displays the current score of the game.
*****************************************************************************/
void Game::whoWonRound(int p1RollIn, int p2RollIn)
{
    if(p1RollIn > p2RollIn)
    {
        cout << "Player 1 wins this round!" << endl;
        p1Score++;
    }
    else if(p2RollIn > p1RollIn)
    {
        cout << "Player 2 wins this round!" << endl;
        p2Score++;
    }
    else
    {
        cout << "This round is a draw!" << endl;
    }

    cout << "P1 Score: " << p1Score << "\tP2 Score: " << p2Score << endl << endl;
}

/*****************************************************************************
 *                          whoWonGame()
 * whoWonGame compares the two player's final scores and outputs who the winner
 * of the game is.
*****************************************************************************/
void Game::whoWonGame()
{
    cout << "Final Score: " << endl;
    cout << "P1 Score: " << p1Score << "\tP2 Score: " << p2Score << endl << endl;

    if(p1Score > p2Score)
    {
        cout << "Congratulations Player 1! You win!" << endl;
    }
    else if(p2Score > p1Score)
    {
        cout << "Congratulations Player 2! You win!" << endl;
    }
    else
    {
        cout << "This game is a draw!" << endl;
    }
}

/*****************************************************************************
 *                          playOrQuit()
 * playOrQuit takes the input from the Start Menu and if the user decides to
 * play, asks the user for the settings for the game, then displays the results.
 * If the user decides to quit the game, the game ends.
*****************************************************************************/
void Game::playOrQuit() {
    if(startMenuObj.getUserChoice() == 1)
    {
        getSettings();
        getResults();
    }
    // 2 was selected, quit the game.
    else
    {
        return;
    }
}
