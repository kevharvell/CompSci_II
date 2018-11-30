/*****************************************************************************
 * Program name: Zoo
 * Author: Kevin Harvell
 * Date: 4/22/2018
 * Description: Zoo is the main engine class for the Zoo Tycoon game. It holds
 * much of the important information including: money, the animal cages, and
 * random events.
*****************************************************************************/

#include <iostream>
#include <random>
#include "Menu.hpp"
#include "Zoo.hpp"

using std::cout;
using std::endl;

Zoo::Zoo()
{
    // Create animal cages
    tigers = new Animal*[tigerCapacity];
    penguins = new Animal*[penguinCapacity];
    turtles = new Animal*[turtleCapacity];
}

Zoo::~Zoo()
{
    // Deallocate memory used by zoo animal cages
    for(int i = 0; i < numTigers; i++)
    {
        delete tigers[i];
    }
    delete []tigers;
    for(int i = 0; i < numPenguins; i++)
    {
        delete penguins[i];
    }
    delete []penguins;
    for(int i = 0; i < numTurtles; i++)
    {
        delete turtles[i];
    }
    delete []turtles;
}

/*****************************************************************************
 *                          startZoo()
 * startZoo asks the user how many of each animal (1 or 2) that the user would
 * like to start the game with.
*****************************************************************************/

void Zoo::startZoo()
{
    cout << "Welcome to the world's worst zoo, where you can only see text representations of 3 animals:\n"
            << "tigers, penguins, and turtles!\n" << endl;
    cout << "Please pick how many (1 or 2) of each type of animal you would like to start with:\n" << endl;
    cout << "Tigers($10,000): ";
    qty = validate.getInt(1, 2);
    addAnimal(TIGER, 1, qty);
    cout << "Penguins($1,000): ";
    qty = validate.getInt(1, 2);
    addAnimal(PENGUIN, 1, qty);
    cout << "Turtles($100): ";
    qty = validate.getInt(1, 2);
    addAnimal(TURTLE, 1, qty);
}

/*****************************************************************************
 *                          age()
 * age ages all animal in the Zoo by 1 day.
*****************************************************************************/

void Zoo::age()
{
    for(int i = 0; i < numTigers; i++)
    {
        tigers[i]->ageUp();
    }
    for(int i = 0; i < numPenguins; i++)
    {
        penguins[i]->ageUp();
    }
    for(int i = 0; i < numTurtles; i++)
    {
        turtles[i]->ageUp();
    }
}

/*****************************************************************************
 *                          payFoodCosts()
 * payFoodCosts subtracts the food costs for each animal from the Zoo's total
 * money.
*****************************************************************************/

void Zoo::payFoodCosts()
{
    int sum = 0;
    // Pay for tiger food
    for(int i = 0; i < numTigers; i++)
    {
        sum += tigers[i]->getBaseFoodCost();
    }
    // Pay for penguin food
    for(int i = 0; i < numPenguins; i++)
    {
        sum += penguins[i]->getBaseFoodCost();
    }
    // Pay for turtle food
    for(int i = 0; i < numTurtles; i++)
    {
        sum += turtles[i]->getBaseFoodCost();
    }

    spend(sum);

    cout << "$" << sum << " spent on food costs." << endl;
}

int Zoo::getMoney()
{
    return money;
}

/*****************************************************************************
 *                          spend()
 * spend subtracts the cost parameter from the Zoo's money.
*****************************************************************************/
void Zoo::spend(int cost)
{
    money -= cost;
}

/*****************************************************************************
 *                          rebuildCages()
 * rebuildCages expands the dynamically allocated array in the case of the
 * number of a certain animal type growing beyond what the array can hold. It
 * expands the array by a factor of 2.
*****************************************************************************/

void Zoo::rebuildCages(int animalType) {
    switch (animalType) {
        case TIGER: {
            tigerCapacity *= 2;

            Animal **tigersTemp = new Animal *[tigerCapacity];

            for (int i = 0; i < numTigers; i++) {
                tigersTemp[i] = tigers[i];
            }
            delete[]tigers;

            tigers = tigersTemp;
            break;
        }

        case PENGUIN: {
            penguinCapacity *= 2;

            Animal **penguinsTemp = new Animal *[penguinCapacity];

            for (int i = 0; i < numPenguins; i++) {
                penguinsTemp[i] = penguins[i];
            }
            delete[]penguins;

            penguins = penguinsTemp;
            break;
        }

        case TURTLE: {
            turtleCapacity *= 2;

            Animal **turtlesTemp = new Animal *[turtleCapacity];

            for (int i = 0; i < numTurtles; i++) {
                turtlesTemp[i] = turtles[i];
            }
            delete[]turtles;

            turtles = turtlesTemp;
            break;
        }

    }
}

/*****************************************************************************
 *                          addAnimal()
 * addAnimal takes in three parameters: animalType, age, and qty.
 * These parameters help in the creation of the correct animal in the zoo.
*****************************************************************************/

void Zoo::addAnimal(int animalType, int age, int qty)
{
    for(int i = 0; i < qty; i++) {
        switch (animalType) {
            case TIGER: {
                // Check to see if the tiger cage is at max capacity
                // If so, expand the cage.
                if (numTigers == tigerCapacity) {
                    rebuildCages(TIGER);
                }
                // Create new animal
                tigers[numTigers] = new Tiger(age);
                // If this is not a birth, charge the zoo owner
                if(age != 0) {
                    spend(tigers[numTigers]->getCost());
                }
                numTigers++;
                break;
            }
            case PENGUIN: {
                // Check to see if the penguin cage is at max capacity
                // If so, expand the cage.
                if (numPenguins == penguinCapacity) {
                    rebuildCages(PENGUIN);
                }
                // Create new animal
                penguins[numPenguins] = new Penguin(age);
                // If this is not a birth, charge the zoo owner
                if(age != 0) {
                    spend(penguins[numPenguins]->getCost());
                }
                numPenguins++;
                break;
            }
            case TURTLE: {
                // Check to see if the turtle cage is at max capacity
                // If so, expand the cage.
                if (numTurtles == turtleCapacity) {
                    rebuildCages(TURTLE);
                }
                // Create new animal
                turtles[numTurtles] = new Turtle(age);
                // If this is not a birth, charge the zoo owner
                if(age != 0) {
                    spend(turtles[numTurtles]->getCost());
                }
                numTurtles++;
                break;
            }
            default:
                cout << "Invalid animalType input for addAnimal()." << endl;
                break;
        }
    }
}

/*****************************************************************************
 *                          randomEvent()
 * randomEvent selects a number between 0 and 3 and uses these values in the
 * enum RandomEvents to act out a random event of: sickness, attendance boom,
 * birth, and nothing.
*****************************************************************************/

void Zoo::randomEvent() {
    
    int randNum = rand() % 4;
    
    switch (randNum) {
        case SICK: {
            cout << "Oh no! A sickness occurs to an animal in the zoo. It didn't make it... R.I.P" << endl;
            die();
            break;
        }
        case ATTENDANCE_EVENT: {
            cout << "Wow! A boom in zoo attendance occurs! You're going to make some serious cash!" << endl;
            getBonus();
            break;
        }
        case BIRTH: {
            cout << "It's a miracle! A baby has been born in your zoo!" << endl;
            birth();
            break;
        }
        case NOTHING: {
            cout << "Sometimes no news is good news! Nothing much going on at the zoo today." << endl;
            break;
        }
    }
}

/*****************************************************************************
 *                          birth()
 * birth checks to see that there are adult animals (age >= 3), and if there
 * are, creates a new animal of the type of the adult. The type of baby is
 * decided randomly.
*****************************************************************************/

void Zoo::birth()
{
    // Temporary bool variables  to store whether there is an adult (age >= 3)
    bool tigerAdult = false;
    bool penguinAdult = false;
    bool turtleAdult = false;

    // Check tigers to see if there are adults
    for(int i = 0; i < numTigers; i++)
    {
        if(tigers[i]->isAdult()) {
            tigerAdult = true;
        }
    }
    // Check penguins to see if there are adults
    for(int i = 0; i < numPenguins; i++)
    {
        if(penguins[i]->isAdult()) {
            penguinAdult = true;
        }
    }
    // Check turtles to see if there are adults
    for(int i = 0; i < numTurtles; i++)
    {
        if(turtles[i]->isAdult()) {
            turtleAdult = true;
        }
    }

    // If there are no adults, there can be no births
    if(!tigerAdult && !penguinAdult && !turtleAdult) {
        cout << "There are no adults to have babies." << endl;
        return;
    }

    // Birth a random baby as long as there is an adult present
    while(tigerAdult || penguinAdult || turtleAdult) {
        // Random int between 0 and 2 representing enum AnimalType
        int randNum = rand() % 3;

        // Check to see if randNum was Tiger and that there is an adult
        if(tigerAdult && randNum == TIGER)
        {
            // Add new tiger and change all variables to false to exit loop
            addAnimal(TIGER, 0, 1);
            tigerAdult = false;
            penguinAdult = false;
            turtleAdult = false;
        }
        // Check to see if randNum was Penguin and that there is an adult
        else if(penguinAdult && randNum == PENGUIN)
        {
            // Add new penguin and change all variables to false to exit loop
            addAnimal(PENGUIN, 0, 1);
            tigerAdult = false;
            penguinAdult = false;
            turtleAdult = false;
        }
        // Check to see if randNum was Turtle and that there is an adult
        else if(turtleAdult && randNum == TURTLE)
        {
            // Add new turtle and change all variables to false to exit loop
            addAnimal(TURTLE, 0, 1);
            tigerAdult = false;
            penguinAdult = false;
            turtleAdult = false;
        }
    }
}

/*****************************************************************************
 *                          die()
 * die picks an animal type at random, checks to see that there is actually an
 * animal to kill, and then proceeds to kill it :(
*****************************************************************************/

void Zoo::die()
{
    // variable to store whether the die function has successfully killed an animal
    bool notDead = true;

    // while an animal hasn't died and the number of each type is greater than 0
    while(notDead && (numTigers > 0 || numPenguins > 0 || numTurtles > 0))
    {
        int randNum = rand() % 3;

        switch (randNum) {
            case TIGER: {
                if(numTigers > 0) {
                    delete tigers[numTigers - 1];
                    numTigers--;
                    notDead = false;
                }
                break;
            }
            case PENGUIN: {
                if(numPenguins > 0) {
                    delete penguins[numPenguins - 1];
                    numPenguins--;
                    notDead = false;
                }
                break;
            }
            case TURTLE: {
                if(numTurtles > 0) {
                    delete turtles[numTurtles - 1];
                    numTurtles--;
                    notDead = false;
                }
                break;
            }
        }
    }

    // If there are no more animals to kill
    if(numTigers == 0 && numPenguins == 0 && numTurtles == 0)
    {
        cout << "There are no more animals to kill. R.I.P." << endl;
    }

}

/*****************************************************************************
 *                          getPaid()
 * getPaid pays the zoo based on each animal's payOff amount.
*****************************************************************************/

void Zoo::getPaid()
{
    int sum = 0;
    // Tiger pay
    for(int i = 0; i < numTigers; i++)
    {
        sum += tigers[i]->getPayOff();
    }
    // Penguin pay
    for(int i = 0; i < numPenguins; i++)
    {
        sum += penguins[i]->getPayOff();
    }
    // Turtle pay
    for(int i = 0; i < numTurtles; i++)
    {
        sum += turtles[i]->getPayOff();
    }

    money += sum;

    cout << "Your zoo made $" << sum << " today!" << endl << endl;
}

/*****************************************************************************
 *                          getBonus()
 * getBonus generates a random bonus between 250 and 500 dollars for each tiger
 * in the zoo. It adds this bonus to the zoo's money.
*****************************************************************************/

void Zoo::getBonus()
{
    int randNum = rand() % 251 + 250;
    randNum *= numTigers;
    money += randNum;
    cout << "$" << randNum << " bonus received!" << endl;
}

/*****************************************************************************
 *                          buyAdult()
 * buyAdult at the end of every day, prompts the user to buy an adult animal
 * of whatever type the user decides.
*****************************************************************************/

void Zoo::buyAdult()
{
    Menu adults;
    adults.addOption("Tiger");
    adults.addOption("Penguin");
    adults.addOption("Turtle");
    adults.addOption("I don't want to buy any animals.");

    cout << "Would you like to buy an adult animal for the zoo?" << endl;
    adults.printOptions();
    adults.promptUserChoice();

    switch(adults.getUserChoice()) {
        case 1: {
            addAnimal(TIGER, 3, 1);
            break;
        }
        case 2: {
            addAnimal(PENGUIN, 3, 1);
            break;
        }
        case 3: {
            addAnimal(TURTLE, 3, 1);
            break;
        }
        case 4: {
            break;
        }
    }
}

/*****************************************************************************
 *                          liveDay()
 * liveDay simulates a day in the zoo by calling many of the other functions
 * that represent events of that day: printStats, age, payFoodCosts, randomEvent,
 * getPaid, and buyAdult.
*****************************************************************************/

void Zoo::liveDay()
{
    cout << "\nBeginning of day stats:\n" << endl;
    printStats();
    age();
    payFoodCosts();
    randomEvent();
    getPaid();
    buyAdult();

}

/*****************************************************************************
 *                          printStats()
 * printStats prints the stats of the zoo for each day, including:
 * money, number of tigers, penguins, and turtles.
*****************************************************************************/

void Zoo::printStats()
{
    cout << "Money = $" << getMoney() << endl;

    cout << "\nNumber of tigers: " << numTigers;

    cout << "\nNumber of penguins: " << numPenguins;

    cout << "\nNumber of turtles: " << numTurtles << endl << endl;

}






