//
// Created by fayda on 5/1/2018.
//

#ifndef DOODLEBUGS_DOODLEBUG_HPP
#define DOODLEBUGS_DOODLEBUG_HPP

#include <iostream>
#include "Critter.hpp"
#include "Game.hpp"

class Doodlebug : public Critter
{
private:
    int numSteps;
    int age;
    int daysSinceLastEaten;
    const char bugSpecies = 'X';
    Game gameBoard; //just a place holder for whatever we want to name this

public:
    Doodlebug(int startingXPos, int startingYPos,board*);
    ~Doodlebug();
    void move();
    void breed();
    char getBugSpecies() const;
    int getAge();
    void increaseDoodleAge();
    void dayInLifeOfDoodle();


};


#endif //DOODLEBUGS_DOODLEBUG_HPP
