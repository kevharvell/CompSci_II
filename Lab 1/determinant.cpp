/*****************************************************************************
** Program name: determinant()
** Author: Kevin Harvell
** Date: 4/1/2018
** Description: determinant() is a function that takes two parameters: a pointer
** to a 2D array and an integer as the size of the matrix. determinant()
** calculates the determinant and returns it.
*****************************************************************************/

#include "determinant.hpp"

int determinant(int** matrix, int size)
{
    int determinantOut;
    // if the matrix is 2x2
    if(size == 2) {
        // set matrix contents to formula letters for easier readability
        int a = matrix[0][0],
                b = matrix[0][1],
                c = matrix[1][0],
                d = matrix[1][1];
        // find determinant for a 2x2 matrix
        determinantOut = (a * d) - (b * c);
    }
    // if the matrix is 3x3
    else if(size == 3)
    {
        // set matrix contents to formula letters for easier readability
        int a = matrix[0][0];
        int b = matrix[0][1];
        int c = matrix[0][2];
        int d = matrix[1][0];
        int e = matrix[1][1];
        int f = matrix[1][2];
        int g = matrix[2][0];
        int h = matrix[2][1];
        int i = matrix[2][2];
        // find determinant for a 3x3 matrix
        determinantOut = (a * (e * i - f * h)) - (b * (d * i - f * g)) + (c * (d * h - e * g));
    }
    return determinantOut;
}
