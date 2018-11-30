/*****************************************************************************
 * Program name: bufferPalindrome
 * Author: Kevin Harvell
 * Date: 5/30/2018
 * Description: bufferPalindrome either simulates a buffer using a queue or
 * creates a palindrome using a stack.
*****************************************************************************/

#include "bufferPalindrome.hpp"
#include "InputValidation.hpp"

#include <iostream>

using std::cout;
using std::endl;

/*****************************************************************************
 * promptSettings prompts the user for the settings in the buffer simulation
 * which include: number of rounds and the chances of pushing and popping
 * to/from the queue.
 ****************************************************************************/

void promptSettings(int &numRounds, int &pushChance, int &popChance) {
    InputValidation validate;
    // Ask user for:
    // How many rounds will be simulated,
    cout << "How many rounds will be simulated? ";
    numRounds = validate.getInt(0, 1000);

    // The percentage chance to put a randomly generated number at the
    // end of buffer,
    cout << "Percent chance to push number to end of buffer? (1-100) ";
    pushChance = validate.getInt(1, 100);

    // The percentage chance to take out a randomly generated number at the
    // front of buffer.
    cout << "Percent chance pop number from front of buffer? (1-100) ";
    popChance = validate.getInt(1, 100);
}

/*****************************************************************************
 * printBuffer prints the queue from first to last.
 ****************************************************************************/

void printBuffer(std::queue<int> buffer) {
    int tempBuffSize = buffer.size();
    // Print values in the buffer, and then print length of buffer.
    for (int j = 0; j < tempBuffSize; j++) {
        cout << buffer.front() << "   ";
        buffer.pop();
    }
    cout << endl;
}
