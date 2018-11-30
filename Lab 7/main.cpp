/*****************************************************************************
 * Program Name: Circular Linked List
 * Author: Kevin Harvell
 * Date: 5/15/2018
 * Description: Circular Linked List gives some practice creating a circular
 * linked list queue, including functions that add a value to the back of a
 * queue, displaying the front in line, removing the front in line, and
 * displaying the queue's content.
*****************************************************************************/


#include "Menu.hpp"
#include "Queue.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Create InputValidation object
    InputValidation validate;

    // Create Menu object
    Menu menu;
    menu.addOption("Add a value to the back of queue");
    menu.addOption("Display the front value");
    menu.addOption("Remove the front node");
    menu.addOption("Display the queue's content");
    menu.addOption("Exit");

    // Create Queue object
    Queue queueList;

    cout << "Welcome to my queue!" << endl << endl;

    do {
        cout << "Choose from the following options:" << endl;
        menu.printOptions();
        menu.promptUserChoice();

        switch(menu.getUserChoice())
        {
            case 1:
                int posInt;
                cout << "Please enter a positive integer: ";
                posInt = validate.getInt(1, 10000);
                queueList.addBack(posInt);
                break;
            case 2:
                if(!queueList.isEmpty()) {
                    cout << "\nThe first node value is: " << queueList.getFront() << endl << endl;
                }
                break;
            case 3:
                queueList.removeFront();
                break;
            case 4:
                queueList.printQueue();
                break;
            case 5:
                break;
            default:
                break;
        }
    } while(menu.getUserChoice() != 5);


    return 0;
}