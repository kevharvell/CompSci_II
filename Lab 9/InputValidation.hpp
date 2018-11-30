/*****************************************************************************
* Program name: InputValidation
* Author: Kevin Harvell
* Date: 4/3/2018
* Description: InputValidation is a class for input values. For now, it will
* have only one function which is to check to see if an input is an integer.
*****************************************************************************/
#ifndef INPUTVALIDATION_HPP
#define INPUTVALIDATION_HPP

#include <string>

class InputValidation {
public:
    int getInt();
    int getInt(int min, int max);
};

#endif
