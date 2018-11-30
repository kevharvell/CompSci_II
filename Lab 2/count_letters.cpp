/*****************************************************************************
* Program name: count_letters
* Author: Kevin Harvell
* Date: 4/14/2018
* Description: count_letters is a function that takes an input file stream,
* and a pointer to an array of integers. It first reads the paragraph string
* from the input file stram, then counts the letter frequencies of that
* paragraph, and stores the frequencies in the array. It disregards upper/
* lowercase letters
*****************************************************************************/
#include "count_letters.hpp"
#include "output_letters.hpp"
#include <iostream>
#include <fstream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

// constant variable for the number of letters in the alphabet;
// used for letter count array.
const int NUM_LETTERS_ALPHA = 26;
// constant variable representing the ASCII value of 'a'
// will be used when counting letters in array.
const int CHAR_OFFSET = 97;

void count_letters(std::ifstream &inputFileIn, int* letterCountArrIn)
{
    // temporary string to store each paragraph
    string paragraph;
    // store the first paragraph
    getline(inputFileIn, paragraph);
    // loop through each paragraph
    while(!inputFileIn.fail()) {
        // initialize counting array for each paragraph to have
        // each letter count set to 0
        for(int i = 0; i < NUM_LETTERS_ALPHA; i++)
        {
            letterCountArrIn[i] = 0;
        }
        // loop through each letter in the paragraph to count frequencies
        for(int i = 0; i < paragraph.length(); i++)
        {
            // temporary letter variable
            char letter;
            letter = paragraph[i];
            // make sure that it is a letter before adding to the count
            if(isalpha(letter))
            {
                // make the letter lowercase so the count is accurate
                letter = tolower(letter);
                // use the CHAR_OFFSET variable to subtract from the ASCII
                // value, thus adding to the count in the right position in
                // the letter count array.
                letterCountArrIn[int(letter) - CHAR_OFFSET] += 1;
            }
        }
        // before finishing with this paragraph, create an output file to display
        // letter count results.
        ofstream outputFile;
        output_letters(outputFile, letterCountArrIn);
        // onto the next paragraph (if it exists)
        getline(inputFileIn, paragraph);
    }
}
