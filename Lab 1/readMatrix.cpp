/*****************************************************************************
** Program name: readMatrix()
** Author: Kevin Harvell
** Date: 4/1/2018
** Description: readMatrix() is a function that takes two parameters: a pointer
** to a 2D array and an integer as the size of the matrix. It asks the user
** for 4 or 9 numbers based on the size of the matrix and fills the contents
** of the 2D array.
*****************************************************************************/
#include <iostream>
#include <sstream>
#include "readMatrix.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// function prototype
int getInt();

void readMatrix(int **matrix, int size)
{
    // loop through matrix inputting integers
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix[i][j] = getInt();
        }

    }
}

/*****************************************************************************
 *                              getInt()
 * getInt receives input from the user, converts it into a stringstream,
 * which then checks to see if there is anything beyond an integer that is
 * left over. If there is, it makes the user try to input an integer again.

   ***adapted from OSU slack #162 posted by Buttery
 ****************************************************************************/
int getInt()
{
    // Set error flag variable
    bool errFlag = false;

    // Declare a string to hold the line of input
    string input;

    // Integer for the function to return
    int validInt;

    while(errFlag == false)
    {
        // Read input to the string variable
        getline(cin, input);

        // Initialize stringstream with input string
        stringstream sStream(input);

        // If able to convert and nothing left over
        if(sStream >> validInt && !(sStream >> input))
        {
            errFlag = true;
        }
        else
        {
            cout << "\nYou must enter an integer value." << endl;
        }
    }

    return validInt;
}



