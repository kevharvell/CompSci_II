/*****************************************************************************
 * Program name: letterCounter
 * Author: Kevin Harvell
 * Date: 4/14/2018
 * Description: letterCounter program reads a file filled with letters, counts
 * the letter frequencies in the file, and writes the results to a new file.
*****************************************************************************/

#include <iostream>
#include <string>
#include "count_letters.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;


const int NUM_LETTERS_ALPHA = 26;

int main() {
    ifstream inputFile;
    string readFileName;
    // array to hold the count of each letter
    int letterCountArr[NUM_LETTERS_ALPHA];

    // get the file name for reading; if invalid, keep prompting
    do {
        cout << "Please enter the file name you would like to read: ";
        getline(cin, readFileName);
        inputFile.open(readFileName.c_str());
        if(inputFile.is_open())
        {
            cout << "File opened successfully." << endl;
        }
        else {
            cout << "This file does not exist." << endl;
            readFileName.clear();
        }
    } while (inputFile.fail());

    count_letters(inputFile, letterCountArr);
    inputFile.close();

    return 0;
}