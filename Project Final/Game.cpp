/*****************************************************************************
 * Program name: Game
 * Author: Kevin Harvell
 * Date: 6/8/2018
 * Description: Game is the main engine for the flow of the Haunted House game.
 * It creates the haunted house as a linked list-like object. Prints the house
 * each turn. Controls the gameplay for each turn.
*****************************************************************************/

#include "Game.hpp"
#include "Room.hpp"
#include "CandleRoom.hpp"
#include "GhostRoom.hpp"
#include <iostream>

using std::cout;
using std::endl;

Game::Game() {
    currentRoom = NULL;
    hasCandle = false;
    ghostHasCandle = false;

    // Set up Move Menu
    moveMenu.addOption("UP");
    moveMenu.addOption("RIGHT");
    moveMenu.addOption("DOWN");
    moveMenu.addOption("LEFT");
}

Game::~Game() {
    delete room1;
    delete room2;
    delete room3;
    delete room4;
    delete candleRoom;
    delete ghostRoom;
}

/*****************************************************************************
 * createHouse creates the rooms of the house with derivatives of the Space
 * class. It then sets all the pointers of the rooms to create a linked list
 * of sorts.
 ****************************************************************************/

void Game::createHouse() {
    // Create the house "rooms" with derivatives of the Space class
    room1 = new Room();
    room2 = new Room();
    room3 = new Room();
    room4 = new Room();
    candleRoom = new CandleRoom();
    ghostRoom = new GhostRoom();

    // Set all the pointers for the rooms
    room1->top = room4;
    room1->right = room2;
    room1->bottom = NULL;
    room1->left = room3;

    room2->top = candleRoom;
    room2->right = NULL;
    room2->bottom = NULL;
    room2->left = room1;

    room3->top = ghostRoom;
    room3->right = room1;
    room3->bottom = NULL;
    room3->left = NULL;

    room4->top = NULL;
    room4->right = candleRoom;
    room4->bottom = room1;
    room4->left = ghostRoom;

    candleRoom->top = NULL;
    candleRoom->right = NULL;
    candleRoom->bottom = room2;
    candleRoom->left = room4;

    ghostRoom->top = NULL;
    ghostRoom->right = room4;
    ghostRoom->bottom = room3;
    ghostRoom->left = NULL;

}

/*****************************************************************************
 * printHouse prints the haunted house including all of the rooms.
 ****************************************************************************/

void Game::printHouse()
{
    // Roof of house
    cout << "          _       " << endl;
    cout << "         / \\      " << endl;
    cout << "        /   \\     " << endl;
    cout << "       /     \\    " << endl;
    cout << "      /   |   \\   " << endl;
    cout << "     /   ---   \\  " << endl;
    cout << "    /     |     \\ " << endl;
    cout << "   /             \\" << endl;

    // Top story of house
    cout << "   ---------------" << endl;
    // Check to see if user has collected candle yet
    if(!hasCandle) {
        cout << "   |G  ||   ||C  |" << endl;
    }
    else if(hasCandle && !ghostHasCandle)
    {
        cout << "   |G  ||   ||   |" << endl;
    }
    else if(ghostHasCandle)
    {
        cout << "   |   ||   ||   |" << endl;
    }
    // Change image based on which room the user is in.
    if(currentRoom == room4)
    {
        cout << "   |   || * ||   |" << endl;
    }
    else if(currentRoom == candleRoom)
    {
        cout << "   |   ||   || * |" << endl;
    }
    else if(currentRoom == ghostRoom)
    {
        cout << "   | * ||   ||   |" << endl;
    }
    else
    {
        cout << "   |   ||   ||   |" << endl;
    }

    // Bottom story of house
    cout << "   ---------------" << endl;
    cout << "   |   ||   ||   |" << endl;

    // Change image based on which room the user is in.
    if(currentRoom == room1)
    {
        cout << "   |   || * ||   |" << endl;
    }
    else if(currentRoom == room2)
    {
        cout << "   |   ||   || * |" << endl;
    }
    else if(currentRoom == room3)
    {
        cout << "   | * ||   ||   |" << endl;
    }
    else
    {
        cout << "   |   ||   ||   |" << endl;
    }
    cout << "   ---------------" << endl;
}

/*****************************************************************************
 * playGame is the main game engine for the Haunted House game. It starts
 * by creating the house, starting the game, and running through a loop to
 * make moves and see the progress via printHouse. The game ends when either
 * max moves is reached or the player gets the candle to the ghost or the
 * player runs out of courage.
 ****************************************************************************/

void Game::playGame() {
    createHouse();
    start();
    while(numMoves <= MAX_MOVES && !ghostHasCandle && courage > 0)
    {
        makeMove();
        printHouse();
    }

    // Determine Game Outcomes
    // User took too many moves to complete the objective, game over
    if(numMoves > MAX_MOVES)
    {
        cout << "You took too long to exorcise the ghost." << endl;
        cout << "Looks like the Haunted House has a new ghost..." << endl;
        cout << "Mwahaha....MWAHAHAHHAAHAHAHAHAHAHHAHAHAHAHAHAHAHAHA" << endl;
    }
    // User went to the ghost with the candle but too little courage.
    else if(courage <= 0 && hasCandle)
    {
        cout << "You coward! What were you thinking trying "
             << "to exorcise the ghost with such little courage???" << endl;
        cout << "Looks like the Haunted House has a new ghost..." << endl;
        cout << "Mwahaha....MWAHAHAHHAAHAHAHAHAHAHHAHAHAHAHAHAHAHAHA" << endl;
    }
    // User went to the ghost without the candle and/or ran out of courage
    else if(courage <= 0)
    {
        cout << "You imbecile! The note told you to get the candle!" << endl;
        cout << "Your cowardice got the best of you." << endl;
        cout << "Looks like the Haunted House has a new ghost..." << endl;
        cout << "Mwahaha....MWAHAHAHHAAHAHAHAHAHAHHAHAHAHAHAHAHAHAHA" << endl;
    }
    // User has won the game!
    else
    {
        cout << "Your body takes over and begins speaking incantations" << endl;
        cout << "that you have never heard before in your life." << endl;
        cout << "Your body raises the candle and the flame grows larger." << endl;
        cout << "The flame has engulfed the entire room, the ghost and you." << endl << endl;
        cout << "A gut-wrenching scream ensues penetrating every fiber of your being." << endl;
        cout << "You are blinded by the light, and all of a sudden..." << endl;
        cout << "It is quiet, daylight, and there is no sign of the horror that was the ghost!" << endl;
        cout << "Congratulations! You got yourself a new, UN-haunted house!!!" << endl;
    }
}

/*****************************************************************************
 * start starts the game with some unique story set-up, sets the current room
 * to room 1 and runs the playSpace gameplay from the Space class.
 ****************************************************************************/

void Game::start() {
    cout << "Game Rules:" << endl << endl;
    cout << "Goal of my game is to get a candle to exorcise a ghost in the Haunted House." << endl;
    cout << "There will be spaces that randomly give or take courage," << endl;
    cout << "and 50 courage is needed to collect the candle. " << endl;
    cout << "75 courage and the candle are needed to exorcise the ghost. Good luck!" << endl << endl;
    cout << "Welcome to the C++ Haunted House, the scariest realm of all terminals!" << endl;
    printHouse();
    cout << "\nNo one has entered the haunted house in over 100 ye..." << endl;
    cout << "Dear GOD, lad, what are you doing???" << endl;
    validate.pressEnter();
    cout << "You have just entered the house..." << endl;
    cout << "There is a ghoulish sound in the distance." << endl;
    cout << "In the faint moonlight, you see a parchment on the ground with frantic writing:" << endl;
    cout << "'RUN W... YOU CAN! There's a ghos...Only way...kill it...exorcise w...a candle...'" << endl;
    currentRoom = room1;
    numMoves++;
    printHouse();
    currentRoom->playSpace(courage, hasCandle, ghostHasCandle);
}

/*****************************************************************************
 * displayStats displays the user's stats including: courage and number of moves.
 ****************************************************************************/

void Game::displayStats()
{
    cout << "\n>>> COURAGE: " << courage << "\t NUMBER OF MOVES: "
         << numMoves << "/" << MAX_MOVES << " <<<" << endl << endl;
}

/*****************************************************************************
 * makeMove controls the game flow for each move the user makes. This consists
 * of displaying stats, presenting the move direction menu, moving the user
 * in the specified direction, and running playSpace which is unique depending
 * on the type of space.
 ****************************************************************************/

void Game::makeMove() {
    displayStats();
    cout << "Where will you go? " << endl;
    moveMenu.printOptions();
    moveMenu.promptUserChoice();
    // Depending on direction user selects to move, currentRoom changes to valid
    // direction room. If the direction is not valid, the user loses a turn.
    switch(moveMenu.getUserChoice()) {
        case UP: {
            if(currentRoom->top != NULL)
            {
                currentRoom = currentRoom->top;
                currentRoom->playSpace(courage, hasCandle, ghostHasCandle);
            }
            else
            {
                cout << "You picked the wrong direction and ran into a wall!" << endl;
            }
            break;
        }
        case RIGHT: {
            if(currentRoom->right != NULL)
            {
                currentRoom = currentRoom->right;
                currentRoom->playSpace(courage, hasCandle, ghostHasCandle);
            }
            else
            {
                cout << "You picked the wrong direction and ran into a wall!" << endl;
            }
            break;
        }
        case DOWN: {
            if(currentRoom->bottom != NULL)
            {
                currentRoom = currentRoom->bottom;
                currentRoom->playSpace(courage, hasCandle, ghostHasCandle);
            }
            else
            {
                cout << "You picked the wrong direction and ran into a wall!" << endl;
            }
            break;
        }
        case LEFT: {
            if(currentRoom->left != NULL)
            {
                currentRoom = currentRoom->left;
                currentRoom->playSpace(courage, hasCandle, ghostHasCandle);
            }
            else
            {
                cout << "You picked the wrong direction and ran into a wall!" << endl;
            }
            break;
        }
    }
    numMoves++;
    validate.pressEnter();
}


