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
#ifndef OUTPUT_LETTERS_H
#define OUTPUT_LETTERS_H

#include <fstream>

void output_letters(std::ofstream &, int*);

#endif
