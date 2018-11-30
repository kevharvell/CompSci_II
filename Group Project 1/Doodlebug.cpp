/*********************************************************************
** Program name: Group Project
** Author: Group 3
** Date:5-1-2018
** Description: This is the implemetaion file for Doodlebug class.
** This class creates a doodleBug, moves the bug and eats ants if ants are
 * available. The bug will starve and die if it doesn't eat. Doodle bug
 * will also breed.
*********************************************************************/
#include "Doodlebug.hpp"

Doodlebug::Doodlebug(int startingRowPos, int startingColpos,Game* board)
{
    rowPos = startingRowPos;
    colPos = startingColpos;
    gameBoard = &board;
    daysSinceLastEaten = 0;



}

void Doodlebug::move()
{
    int oldestAnt = 0; //using ant age/steps/turns to determine which ant to eat if bug is adjacent to multiple
    int potentialRowMove = rowPos;
    int potentialColMove = colPos;
    bool antPresent = false;
    if(rowPos > 0 && (gameBoard[rowPos-1][colPos] != nullptr) && gameBoard[rowPos-1][colPos].getType() == '0')
    {
        oldestAnt = gameBoard[rowPos-1][colPos].getAge();
        potentialRowMove = rowPos -1;
        potentialColMove = colPos;
        antPresent = true;
        gameBoard.removeAnt(); // this function needs to be written in Game
        daysSinceLastEaten = 0;
    }
    if((colPos < gameBoard.getBoardSize())&& (gameBoard[rowPos][colPos+1] != nullptr) &&
            (gameBoard[rowPos][colPos+1].getType() == '0'))
    {
        if (gameBoard[rowPos][colPos + 1].getAge() > oldestAnt)
        {
            potentialRowMove = rowPos;
            potentialColMove = colPos + 1;
            antPresent = true;
            gameBoard.removeAnt(); // this function needs to be written in Game
            daysSinceLastEaten = 0;
        }

    }
    if((rowPos < gameBoard.getBoardSize())&& (gameBoard[rowPos+1][colPos] != nullptr) &&
         (gameBoard[rowPos+1][colPos].getType() == '0'))
    {
        if(gameBoard[rowPos+1][colPos].getAge() > oldestAnt)
        {
            potentialRowMove = rowPos + 1;
            potentialColMove = colPos;
            antPresent = true;
            gameBoard.removeAnt(); // this function needs to be written in Game
            daysSinceLastEaten = 0;
        }
    }
    if((colPos > 0)&& (gameBoard[rowPos][colPos -1] != nullptr) &&
       (gameBoard[rowPos][colPos-1].getType() == '0'))
    {
        if(gameBoard[rowPos][colPos-1].getAge() > oldestAnt)
        {
            potentialRowMove = rowPos;
            potentialColMove = colPos - 1;
            antPresent = true;
            gameBoard.removeAnt(); // this function needs to be written in Game
            daysSinceLastEaten = 0;
        }
    }
    if(antPresent == true)
    {
        rowPos = potentialRowMove;
        colPos = potentialColMove;
    }
    else
    {
        daysSinceLastEaten ++;
        potentialRowMove = 0;  // we need a random function here to move doodle I'm setting to 0 for testing
        potentialColMove = 0;  //feel free to change these values
        if((gameBoard[potentialRowMove][potentialColMove] != nullptr) &&
                (gameBoard[potentialRowMove][potentialColMove].getType() != 'X'))
        {
            rowPos = potentialRowMove;
            colPos = potentialColMove;
        }

    }



}

Doodlebug::~Doodlebug()
{

}

char Doodlebug::getBugSpecies() const
{
    return bugSpecies;
}

int Doodlebug::getAge()
{
    return age;
}

void Doodlebug::breed()
{

    if(rowPos > 0 && (gameBoard[rowPos-1][colPos] == nullptr))
    {
       // we need a board function to place doodlebug on board then call constructor
       gameBoard.placeBugOnBoard (Doodlebug(rowPos-1, colPos,gameBoard)); //game board needs to write this method
        //I just made up a name for it.

    }
    else if((colPos < gameBoard.getBoardSize())&& (gameBoard[rowPos][colPos+1] == nullptr))
    {

        gameBoard.placeBugOnBoard((rowPos, colPos + 1,gameBoard));


    }
    else if((rowPos < gameBoard.getBoardSize())&& (gameBoard[rowPos+1][colPos] == nullptr))
    {

        gameBoard.placeBugOnBoard (Doodlebug(rowPos + 1, colPos, gameBoard));

    }
    else if((colPos > 0)&& (gameBoard[rowPos][colPos -1] == nullptr))
    {

        gameBoard.placeBugOnBoard (Doodlebug(rowPos, colPos -1,gameBoard));

    }


}

void Doodlebug::increaseDoodleAge()
{
    age++;

}

void Doodlebug::dayInLifeOfDoodle()
{
    move();
    if(age%8 == 0)
    {
        breed();
    }
    if(daysSinceLastEaten > 3)
    {
        gameboard.removeDoodle(); //this function needs to be written in board
    }
    increaseDoodleAge();

}







