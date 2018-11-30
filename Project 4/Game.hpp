//
// Created by Kev on 5/15/2018.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "InputValidation.hpp"
#include "List.hpp"

class Game {
    private:
        InputValidation validate;
        Menu characterMenu;
        Menu loserMenu;
        bool debug = false;
        const int MIN_FIGHTERS = 1;
        const int MAX_FIGHTERS = 5;
        int teamAScore = 0;
        int teamBScore = 0;
        int round = 1;
        int numTeamAFighters;
        int numTeamBFighters;
        List teamALineUp;
        List teamBLineUp;
        List losers;
        Character* tempCharacter = NULL;

        void setFighters();
        void createCharacter(int choice);
        void fight();
        void displayResults();

    public:
        Game();
        void runGame();
};


#endif
