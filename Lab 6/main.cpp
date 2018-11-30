/*****************************************************************************
 * Program Name: Doubly Linked Lists
 * Author: Kevin Harvell
 * Date: 5/13/2018
 * Description: Doubly Linked Lists experiments with doubly linked lists with
 * the following functions: adding a new node to the head, adding a new node
 * to the tail, deleting the first node in a list, deleting the last node in
 * a list, and traversing the list reversely.
*****************************************************************************/

#include "List.hpp"
#include "Menu.hpp"

#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Create InputValidation object
    InputValidation validate;

    // Create Menu
    Menu menu;
    menu.addOption("Add a new node to the head");
    menu.addOption("Add a new node to the tail");
    menu.addOption("Delete from head");
    menu.addOption("Delete from tail");
    menu.addOption("Traverse the list reversely");
    menu.addOption("Exit");

    // Create linkedList object
    List linkedList;

    cout << "Welcome to my linked list!\n" << endl;

    // Run program while user has not selected to exit
    do {
        cout << "Choose from the following options:\n" << endl;
        menu.printOptions();
        menu.promptUserChoice();

        switch(menu.getUserChoice()) {
            case 1: {
                cout << "Please enter a positive integer: ";
                linkedList.addToHead(validate.getInt(1, 100000));
                linkedList.displayList();
                break;
            }
            case 2: {
                cout << "Please enter a positive integer: ";
                linkedList.addToTail(validate.getInt(1, 100000));
                linkedList.displayList();
                break;
            }
            case 3: {
                linkedList.removeHead();
                linkedList.displayList();
                break;
            }
            case 4: {
                linkedList.removeTail();
                linkedList.displayList();
                break;
            }
            case 5: {
                linkedList.reverseTraverse();
                break;
            }
            case 6: {
                // Exit the program
                break;
            }
        }

    } while(menu.getUserChoice() != 6);

    return 0;
}