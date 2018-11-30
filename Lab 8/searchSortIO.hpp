/*****************************************************************************
 * Program name: Searching and Sorting Main
 * Author: Kevin Harvell
 * Date: 5/25/2018
 * Description: This program uses algorithms to search data and sort data,
 * inputting and outputting data.
*****************************************************************************/

#ifndef SEARCHSORTIO_HPP
#define SEARCHSORTIO_HPP

#include <iostream>
#include <fstream>
#include <vector>

void transferToVect(std::ifstream &input, std::vector<int> &dataVectIn);
void printVect(const std::vector<int> &dataVectIn);
int simpleSearch(const std::vector<int> &dataVectIn, int value);
void selectionSort(std::vector<int> &dataVectIn);
int binarySearch(std::vector<int> &dataVectIn, int value);
void vectorToFile(std::vector<int> &dataVectIn);

#endif