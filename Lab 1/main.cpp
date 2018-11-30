/*****************************************************************************
** Program name: Matrix Calculator Main
** Author: Kevin Harvell
** Date: 4/1/2018
** Description: Matrix Calculator receives input from the user to specify
** either a 2x2 or 3x3 matrix. It then uses two functions, readMatrix() and
** determinant() in order to fill in the matrix and calculate the determinant
** respectively.
*****************************************************************************/

#include <iostream>
#include <limits.h>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

// Function prototypes
int getMatrixSize();
void printMatrix(int** matrix, int size);

int main() {
    int matrixSize = getMatrixSize();

    // Code below modified from
    // https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new
    // creates a  dynamically allocated 2D array
    int** matrix = new int*[matrixSize];
    for(int i = 0; i < matrixSize; i++)
    {
        matrix[i] = new int[matrixSize];
    }

    // Prompt user for input, display number of values by squaring matrixSize
    cout << "Please input " << matrixSize * matrixSize << " values below." << endl;
    readMatrix(matrix, matrixSize);

    cout << "The input matrix is: " << endl;
    printMatrix(matrix, matrixSize);

    cout << "The determinant of the matrix is " << determinant(matrix, matrixSize) << endl;

    // delete dynamically allocated 2D array
    for(int i = 0; i < matrixSize; i++)
    {
        delete []matrix[i];
    }
    delete []matrix;


    return 0;
}

/*******************************************************************************
 *                          getMatrixSize()
 * getMatrixSize gets the size of the desired matrix from the user by entering
 * 2 or 3 and returns that value.
 *******************************************************************************/
int getMatrixSize()
{
    int matrixSize;

    cout << "Please choose the size of the matrix." << endl;
    do {
        cout << "Enter 2 for 2x2 or 3 for 3x3: ";
        cin >> matrixSize;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

    } while(matrixSize != 2 && matrixSize != 3);

    return matrixSize;
}
/*******************************************************************************
 *                          printMatrix()
 * printMatrix takes a pointer to an array of pointers and the size of the matrix
 * as its parameters. It loops through the pointer array to display its contents
 * in a matrix formatting.
 ******************************************************************************/
void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}