/*****************************************************************************
 * Program name: Zoo
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Zoo is the main engine class for the Zoo Tycoon game. It holds
 * much of the important information including: money, the animal cages, and
 * random events.
*****************************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP
#include "InputValidation.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo
{
private:
    InputValidation validate;

    int money = 100000;

    // Create animal cages
    Animal** tigers;
    Animal** penguins;
    Animal** turtles;

    int qty;
    int tigerCapacity = 10;
    int penguinCapacity = 10;
    int turtleCapacity = 10;
    int numTigers = 0;
    int numPenguins = 0;
    int numTurtles = 0;

protected:

public:
    enum AnimalType {TIGER, PENGUIN, TURTLE};
    enum RandomEvents {SICK, ATTENDANCE_EVENT, BIRTH, NOTHING};
    Zoo();
    ~Zoo();

    void printStats();
    void liveDay();
    void addAnimal(int animalType, int age, int qty);
    void rebuildCages(int animalType);
    void spend(int cost);
    int getMoney();
    void startZoo();
    void die();
    void getPaid();
    void getBonus();
    void birth();
    void age();
    void payFoodCosts();
    void randomEvent();
    void buyAdult();
};

#endif
