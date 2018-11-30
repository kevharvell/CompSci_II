/*****************************************************************************
 * Program name: Searching and Sorting Main
 * Author: Kevin Harvell
 * Date: 5/25/2018
 * Description: This program uses algorithms to search data and sort data,
 * inputting and outputting data.
*****************************************************************************/

#include "searchSortIO.hpp"
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

using std::vector;

/*****************************************************************************
  * transferToVect transfers integer data from an input file to a vector.
*****************************************************************************/

void transferToVect(std::ifstream &input, vector<int> &dataVectIn)
{
    int tempNum;
    while(input >> tempNum)
    {
        dataVectIn.push_back(tempNum);
    }
}

/*****************************************************************************
  * printVect prints the contents of a vector.
*****************************************************************************/

void printVect(const vector<int> &dataVectIn)
{
    // Print contents of dataVect for testing
    for(int i = 0; i < dataVectIn.size(); i++)
    {
        cout << dataVectIn[i] << endl;
    }
}

/*****************************************************************************
  * simpleSearch searches through a vector using a linear search. It returns
  * the index of where the search value was found or -1 if not found.
*****************************************************************************/

int simpleSearch(const std::vector<int> &dataVectIn, int value)
{
    // Below code Modified from C++:Early Objects, 9th Edition
    // Tony Gaddis, Judy Walters, Godfrey Muganda,
    // Thank you!

    // index variable used as a subscript to search vector
    int index = 0;
    // position variable used to record position of search value
    int position = -1;
    // flag to indicate if the value was found
    bool found = false;

    while(index < dataVectIn.size() && !found)
    {
        // If the value is found
        if(dataVectIn[index] == value)
        {
            // Set the flag
            found = true;
            // Record the value's subscript
            position = index;
        }
        index++;
    }
    // Return the position, or -1
    return position;
}

/*****************************************************************************
  * selectionSort sorts a vector in ascending order using a selection sort.
*****************************************************************************/

void selectionSort(std::vector<int> &dataVectIn)
{
    // Below code Modified from C++:Early Objects, 9th Edition
    // Tony Gaddis, Judy Walters, Godfrey Muganda,
    // Thank you!

    int startScan, minIndex, minValue;

    for(startScan = 0; startScan < (dataVectIn.size() - 1); startScan++)
    {
        minIndex = startScan;
        minValue = dataVectIn[startScan];

        for(int index = startScan + 1; index < dataVectIn.size(); index++)
        {
            if(dataVectIn[index] < minValue)
            {
                minValue = dataVectIn[index];
                minIndex = index;
            }
        }
        dataVectIn[minIndex] = dataVectIn[startScan];
        dataVectIn[startScan] = minValue;
    }
}

/*****************************************************************************
  * binarySearch searches through a vector for a target search value using a
  * binary search. It returns the index where the search value is found or -1
  * if not found.
*****************************************************************************/

int binarySearch(std::vector<int> &dataVectIn, int value)
{
    // For binarySearch to be work correctly, the array/vector must be sorted
    selectionSort(dataVectIn);

    // Below code Modified from C++:Early Objects, 9th Edition
    // Tony Gaddis, Judy Walters, Godfrey Muganda,
    // Thank you!

    // First array element
    int first = 0,
    // Last array element
        last = dataVectIn.size() - 1,
    // Midpoint of search
        middle,
    // Position of search value
        position = -1;
    // Flag
    bool found = false;

    while(!found && first <= last)
    {
        // Calculate midpoint
        middle = (first + last) / 2;
        // If value is found at mid
        if(dataVectIn[middle] == value)
        {
            found = true;
            position = middle;
        }
        // If value is in lower half
        else if(dataVectIn[middle] > value)
        {
            last = middle - 1;
        }
        // If value is in upper half
        else
        {
            first = middle + 1;
        }
    }
    return position;
}

/*****************************************************************************
  * vectorToFile transfers vector contents to a user-specified output file.
*****************************************************************************/

void vectorToFile(std::vector<int> &dataVectIn)
{
    std::ofstream ofs;
    string outputFileName;

    cout << "Please enter a name for the output file: " ;
    getline(cin, outputFileName);

    ofs.open(outputFileName);

    for(int i = 0; i < dataVectIn.size(); i++)
    {
        ofs << dataVectIn[i] << endl;
    }

    ofs.close();
}