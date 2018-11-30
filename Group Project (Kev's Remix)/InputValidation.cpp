/*****************************************************************************
* Program name: InputValidation
* Author: Kevin Harvell
* Date: 4/3/2018
* Description: InputValidation is a class for input values. For now, it will
* have only one function which is to check to see if an input is an integer.
*****************************************************************************/
#include <iostream>
#include <sstream>
#include "InputValidation.hpp"
using std::string;
using std::cin;
using std::stringstream;
using std::cout;
using std::endl;

/*****************************************************************************
 *                              getInt()
 * getInt receives input from the user, converts it into a stringstream,
 * which then checks to see if there is anything beyond an integer that is
 * left over. If there is, it makes the user try to input an integer again.

   ***adapted from OSU slack #162 posted by Buttery
 ****************************************************************************/
int InputValidation::getInt() 
{
    // Set error flag variable
    bool errFlag = false;

    // Declare a string to hold the line of input
    string input;

    // Integer for the function to return
    int validInt;

    while (errFlag == false) {
        // Read input to the string variable
        getline(cin, input);

        // Initialize stringstream with input string
        stringstream sStream(input);

        // If able to convert and nothing left over
        if (sStream >> validInt && !(sStream >> input))
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

/*****************************************************************************
 *                              getInt(int min, int max)
 * getInt receives input from the user, converts it into a stringstream,
 * which then checks to see if there is anything beyond an integer that is
 * left over. If there is, it makes the user try to input an integer again.

   ***adapted from OSU slack #162 posted by Buttery
 ****************************************************************************/
int InputValidation::getInt(int min, int max) 
{
    // Set error flag variable
    bool errFlag = false;

    // Declare a string to hold the line of input
    string input;

    // Integer for the function to return
    int validInt;

    while (errFlag == false) {
        // Read input to the string variable
        getline(cin, input);

        // Initialize stringstream with input string
        stringstream sStream(input);

        // If able to convert and nothing left over
        if (sStream >> validInt && !(sStream >> input))
        {
            // Check if within min and max
            if(validInt > max || validInt < min)
            {
                cout << "\nYou must select an integer equal to or between "
                     << min << " and " << max  << "." << endl;
            }

            // Converted and within bounds
            else
            {
                errFlag = true;
            }
        } else {
            cout << "\nYou must enter an integer value." << endl;
        }
    }
    return validInt;
}