/*****************************************************************************
* Program name: output_letters
* Author: Kevin Harvell
* Date: 4/14/2018
* Description: output_letters is a function that takes an output file stream
* variable, and a pointer to an array of integers that contains frequencies
* of letters. It asks the user for the filename the user would like to output
* to, then outputs the frequencies of letters to the output file in the format
* specified above.
*****************************************************************************/

#include "output_letters.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// constant variable for the number of letters in the alphabet;
// used for letter count array.
const int NUM_LETTERS_ALPHA = 26;
// constant variable representing the ASCII value of 'a'
// will be used when displaying letters in array.
const int CHAR_OFFSET = 97;

void output_letters(std::ofstream &outputFileIn, int* letterCountArrIn)
{
    // get the outputFileName from the user
    string outputFileName;
    cout << "Please enter the file name to output character count to: ";
    getline(cin, outputFileName);
    outputFileIn.open(outputFileName);
    // loop through the letter count array in order to write results to
    // output file.
    for(int i = 0; i < NUM_LETTERS_ALPHA; i++)
    {
        // temporary char variable for display purposes
        char tempChar = i + CHAR_OFFSET;
        outputFileIn << tempChar << ": " << letterCountArrIn[i] << endl;
    }
}