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
#ifndef COUNT_LETTERS_HPP
#define COUNT_LETTERS_HPP

#include <fstream>

void count_letters(std::ifstream &, int*);

#endif
