//
// Created by Kev on 5/15/2018.
//

#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

Game::Game() {
    // Create Character Menu
    characterMenu.addOption("Vampire");
    characterMenu.addOption("Barbarian");
    characterMenu.addOption("Blue Men");
    characterMenu.addOption("Medusa");
    characterMenu.addOption("Harry Potter");

    // Create Loser Menu
    loserMenu.addOption("Yes");
    loserMenu.addOption("No");
}

/*****************************************************************************
 * runGame is the central engine for most of the gameplay functionality in
 * charge of organizing all of the processes of the game.
*****************************************************************************/

void Game::runGame() {
    // Call setFighters function to form teams
    setFighters();
    cout << "\nTeam A's Line Up" << endl;
    teamALineUp.displayList();
    cout << "Team B's Line Up" << endl;
    teamBLineUp.displayList();

    fight();

    displayResults();
}

/*****************************************************************************
 * setFighters gets how many fighters on each team, asks for fighter types,
 * names, then finally places each fighter in the appropriate team lineup.
*****************************************************************************/

void Game::setFighters() {
    // Get how many fighters on each team
    cout << "How many fighters for Team A?";
    numTeamAFighters = validate.getInt(MIN_FIGHTERS, MAX_FIGHTERS);
    cout << "How many fighters for Team B?";
    numTeamBFighters = validate.getInt(MIN_FIGHTERS, MAX_FIGHTERS);

    // For Team A, ask for the type of character each fighter is and
    // the name for each fighter.
    cout << "For each of Team A's fighters, please choose the type of character and name the character" << endl;
    for(int i = 0; i < numTeamAFighters; i++)
    {
        cout << "Please select a character for Team A's Fighter #" << i + 1 << " from the following menu:" << endl;
        characterMenu.printOptions();
        characterMenu.promptUserChoice();

        // Create character based on user input
        createCharacter(characterMenu.getUserChoice());

        // Check to see if tempCharacter was set
        // If so, get name of the fighter
        // Then add the fighter to the lineup queue
        if(tempCharacter != nullptr) {
            string tempName;
            // Set name for fighter
            cout << "And what shall you name " << tempCharacter->getType() << "? ";
            getline(cin, tempName);
            tempCharacter->setName(tempName);
            teamALineUp.addToTail(tempCharacter);
            tempCharacter = nullptr;
        }
    }

    // For Team B, ask for the type of character each fighter is and
    // the name for each fighter.
    cout << "For each of Team B's fighters, please choose the type of character and name the character" << endl;
    for(int i = 0; i < numTeamBFighters; i++)
    {
        cout << "Please select a character for Team B's Fighter #" << i + 1 << " from the following menu:" << endl;
        characterMenu.printOptions();
        characterMenu.promptUserChoice();

        // Create character based on user input
        createCharacter(characterMenu.getUserChoice());

        // Check to see if tempCharacter was set
        // If so, get name of the fighter
        // Then add the fighter to the lineup queue
        if(tempCharacter != nullptr) {
            string tempName;
            // Set name for fighter
            cout << "And what shall you name " << tempCharacter->getType() << "? ";
            getline(cin, tempName);
            tempCharacter->setName(tempName);
            teamBLineUp.addToTail(tempCharacter);
            tempCharacter = nullptr;
        }
    }
}

/*****************************************************************************
 * createCharacter allocates memory for newly created Characters.
*****************************************************************************/

void Game::createCharacter(int choice) {
    // Create character based on user input
    switch (characterMenu.getUserChoice()) {
        case Character::VAMPIRE: {
            tempCharacter = new Vampire;
            break;
        }
        case Character::BARBARIAN: {
            tempCharacter = new Barbarian;
            break;
        }
        case Character::BLUE_MEN: {
            tempCharacter = new BlueMen;
            break;
        }
        case Character::MEDUSA: {
            tempCharacter = new Medusa;
            break;
        }
        case Character::HARRY_POTTER: {
            tempCharacter = new HarryPotter;
            break;
        }
    }
}

/*****************************************************************************
 * fight has each team's lineup front fighter faceoff against each other.
 * Each fighter takes turn attacking/defending until one fighter dies. The
 * winning fighter goes to the back of the queue in its lineup, while the
 * losing fighter goes to the top of the losers stack. Winning fighters earn
 * 2 points and losing fighters lose 1 point. At the end of each round, results
 * of that round are displayed.
*****************************************************************************/

void Game::fight() {
    Character* tempFighterA;
    Character* tempFighterB;
    // Check to see if either team's line up is empty before fighting
    while(!teamALineUp.isEmpty() && !teamBLineUp.isEmpty())
    {
        tempFighterA = teamALineUp.getFront();
        tempFighterB = teamBLineUp.getFront();
        // Run each turn of attack in combat
        while (tempFighterA->getStrength() > 0 && tempFighterB->getStrength() > 0) {
            // Team A attacks first
            if (tempFighterA->getStrength() > 0 && tempFighterB->getStrength() > 0 && !debug) {
                tempFighterA->attack();
                tempFighterB->defense();
                tempFighterB->takeDamageFrom(tempFighterA);
            }
            // Team B attacks next
            if (tempFighterA->getStrength() > 0 && tempFighterB->getStrength() > 0 && !debug) {
                tempFighterB->attack();
                tempFighterA->defense();
                tempFighterA->takeDamageFrom(tempFighterB);
            }

            // For debugging
            // Team A attacks first
            if (tempFighterA->getStrength() > 0 && tempFighterB->getStrength() > 0 && debug) {
                cout << "teamA Attacker: " << tempFighterA->getType() << endl;
                cout << "teamB Defender: " << tempFighterB->getType() << " -\tArmor: " << tempFighterB->getArmor()
                     << "\tStrength: " << tempFighterB->getStrength() << endl;
                cout << "teamA attacks with a roll of: " << tempFighterA->attack() << endl;
                cout << "teamB defends with a roll of: " << tempFighterB->defense() << endl;
                tempFighterB->takeDamageFrom(tempFighterA);
                cout << "teamA inflicts " << tempFighterB->getDamage() << " damage!" << endl;
                cout << "teamB's strength is now: " << tempFighterB->getStrength() << endl << endl;
                characterMenu.pressEnter();
            }
            // tempFighterB attacks next
            if (tempFighterA->getStrength() > 0 && tempFighterB->getStrength() > 0 && debug) {
                cout << "teamB Attacker: " << tempFighterB->getType() << endl;
                cout << "teamA Defender: " << tempFighterA->getType() << " -\tArmor: " << tempFighterA->getArmor()
                     << "\tStrength: " << tempFighterA->getStrength() << endl;
                cout << "teamB attacks with a roll of: " << tempFighterB->attack() << endl;
                cout << "teamA defends with a roll of: " << tempFighterA->defense() << endl;
                tempFighterA->takeDamageFrom(tempFighterB);
                cout << "teamB inflicts " << tempFighterA->getDamage() << " damage!" << endl;
                cout << "teamA's strength is now: " << tempFighterA->getStrength() << endl << endl;
                characterMenu.pressEnter();
            }
        }

        // Combat is over
        cout << "COMBAT OVER!" << endl;
        // tempFighterB won the combat
        if(tempFighterA->getStrength() <= 0)
        {
            // Display Round results
            cout << "Round " << round << ": Team A " << tempFighterA->getType() << " " << tempFighterA->getName()
                << " vs. Team B " << tempFighterB->getType() << " " << tempFighterB->getName() << ", "
                << tempFighterB->getType() << " " << tempFighterB->getName() << " Won!" << endl << endl;
            // Winning fighter recovers half of Strength lost
            tempFighterB->recover();
            // Winning fighter is moved to the tail of linked list
            teamBLineUp.removeHead();
            teamBLineUp.addToTail(tempFighterB);
            // Losing fighter removed from team linked list to losers linked list
            teamALineUp.removeHead();
            losers.addToHead(tempFighterA);
            // Team B score goes up by 2, Team A score goes down 1
            teamBScore += 2;
            teamAScore -= 1;
        }
        // tempFighterA won the combat
        else if(tempFighterB->getStrength() <= 0)
        {
            // Display Round results
            cout << "Round " << round << ": Team A " << tempFighterA->getType() << " " << tempFighterA->getName()
                 << " vs. Team B " << tempFighterB->getType() << " " << tempFighterB->getName() << ", "
                 << tempFighterA->getType() << " " << tempFighterA->getName() << " Won!" << endl << endl;
            // Winning fighter recovers half of Strength lost
            tempFighterA->recover();
            // Winning fighter is moved to the tail of linked list
            teamALineUp.removeHead();
            teamALineUp.addToTail(tempFighterA);
            // Losing fighter removed from team linked list to losers linked list
            teamBLineUp.removeHead();
            losers.addToHead(tempFighterB);
            // Team A score goes up by 2, Team B score goes down 1
            teamAScore += 2;
            teamBScore -= 1;
        }
        round++;
    }
}

/*****************************************************************************
 * displayResults displays final results of the tournament, including which
 * team won, and asking the user if they would like to see the losers list.
*****************************************************************************/

void Game::displayResults() {
    cout << "TOURNAMENT OVER!" << endl;
    cout << "Team A Score: " << teamAScore << "\tTeam B Score: " << teamBScore << endl << endl;
    if(teamAScore > teamBScore)
    {
        // Team A wins!
        cout << "Team A Wins!" << endl << endl;
    }
    else if(teamBScore > teamAScore)
    {
        // Team B wins!
        cout << "Team B Wins!" << endl << endl;
    }
    else
    {
        // Score is tied
        cout << "We have a draw!" << endl << endl;
    }

    // Give user option to see the losers
    cout << "Would you like to see the losers?" << endl;
    loserMenu.printOptions();
    loserMenu.promptUserChoice();
    if(loserMenu.getUserChoice() == 1)
    {
        cout << "Here are the losers: " << endl;
        losers.displayList();
    }
}



