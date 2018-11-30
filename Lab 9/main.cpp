/*****************************************************************************
 * Program name: bufferPalindrome
 * Author: Kevin Harvell
 * Date: 5/30/2018
 * Description: bufferPalindrome either simulates a buffer using a queue or
 * creates a palindrome using a stack.
*****************************************************************************/

#include "bufferPalindrome.hpp"
#include "Menu.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <random>

using std::queue;
using std::stack;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    srand(time(0));

    // Set up Menu
    Menu menu;
    menu.addOption("Test the buffer");
    menu.addOption("Create a palindrome");

    // Display menu choices and get user's choice
    menu.printOptions();
    menu.promptUserChoice();

    // If user selects "Test the buffer", run the buffer simulation
    if(menu.getUserChoice() == 1) {
        // Queue used to simulate a buffer
        queue<int> buffer;
        // User defined settings for buffer simulation
        int numRounds;
        int pushChance;
        int popChance;
        // Random numbers
        int N;
        int randPush;
        int randPop;
        // Average Length of buffer variables
        double avgL = 0;

        // Prompt user for number of rounds, chance of pushing, and
        // chance of popping
        promptSettings(numRounds, pushChance, popChance);

        // Loop through user-specified number of rounds to simulate the buffer
        for (int i = 1; i <= numRounds; i++) {
            // Indicate what round it is.
            cout << "\n<===== ROUND " << i << " =====>" << endl;

            // Generate random numbers for simulation
            // Number to push onto queue between 1 and 1000
            N = rand() % 1000 + 1;
            // Random chance of pushing to back of queue
            randPush = rand() % 100 + 1;
            // Random chance of popping front of queue
            randPop = rand() % 100 + 1;

            // Push number
            if (randPush <= pushChance) {
                buffer.push(N);
            }

            // Pop number
            if (randPop <= popChance && !buffer.empty()) {
                buffer.pop();
            }

            // If buffer is empty, print that it is so.
            if (buffer.empty()) {
                cout << "There are no values in the buffer." << endl;
            }
                // Buffer is not empty, print the contents.
            else {
                printBuffer(buffer);
            }

            // Output the length of the buffer
            cout << "Current length of buffer: " << buffer.size() << endl;

            // Output the average length of buffer if there are values in the buffer.
            if (!buffer.empty()) {
                avgL = (avgL * (i - 1) + buffer.size()) / i;
            }
                // The buffer size is 0, so use a different equation w/ 0 for buffer size.
            else {
                avgL = (avgL * (i - 1)) / i;
            }
            cout << "Average Length: " << avgL << endl;
        }
    }

    // User has selected "Create a palindrome"
    else if(menu.getUserChoice() == 2)
    {
        stack<char> palindrome;
        string input;
        int inputLength;

        cout << "Please enter a string to create a palindrome from: ";
        getline(cin, input);

        // Print out the original word
        cout << input;

        inputLength = input.length();

        // Push string to palindrome stack
        for(int i = 0; i < inputLength; i++)
        {
            palindrome.push(input[i]);
        }

        // Print out top of the stack, then pop it off
        for(int i = 0; i < inputLength; i++)
        {
            cout << palindrome.top();
            palindrome.pop();
        }
    }

    return 0;
}