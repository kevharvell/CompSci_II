/*****************************************************************************
 * Program name: Searching and Sorting Main
 * Author: Kevin Harvell
 * Date: 5/25/2018
 * Description: This program uses algorithms to search data and sort data,
 * inputting and outputting data.
*****************************************************************************/

#include "searchSortIO.hpp"
#include "InputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::vector;

int main() {
    InputValidation validate;
    ifstream ifs;
    ofstream ofs;
    vector<int> numV;
    vector<int> earlyV;
    vector<int> midV;
    vector<int> endV;
    int tempNum;

    // Read Values from Files & Transfer to Vectors
    ifs.open("num.txt");
    transferToVect(ifs, numV);
    ifs.close();

    ifs.open("early.txt");
    transferToVect(ifs, earlyV);
    ifs.close();

    ifs.open("mid.txt");
    transferToVect(ifs, midV);
    ifs.close();

    ifs.open("end.txt");
    transferToVect(ifs, endV);
    ifs.close();

    // Simple Search

    // Get search target value
    int searchValue;
    cout << "Simple Search" << endl;
    cout << "What is target value: ";
    searchValue = validate.getInt();

    // Use simpleSearch to find searchValue in num.txt
    if(simpleSearch(numV, searchValue) != -1)
    {
        cout << "num.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "num.txt: target value not found" << endl << endl;
    }

    // Use simpleSearch to find searchValue in early.txt
    if(simpleSearch(earlyV, searchValue) != -1)
    {
        cout << "early.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "early.txt: target value not found" << endl << endl;
    }

    // Use simpleSearch to find searchValue in mid.txt
    if(simpleSearch(midV, searchValue) != -1)
    {
        cout << "mid.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "mid.txt: target value not found" << endl << endl;
    }

    // Use simpleSearch to find searchValue in end.txt
    if(simpleSearch(endV, searchValue) != -1)
    {
        cout << "end.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "end.txt: target value not found" << endl << endl;
    }


    // Sorting using Selection Sort
    // then outputting data to user-specified txt file
    cout << "Name the output files for the 4 sorted txt files. " << endl;
    selectionSort(numV);
    vectorToFile(numV);
    selectionSort(earlyV);
    vectorToFile(earlyV);
    selectionSort(midV);
    vectorToFile(midV);
    selectionSort(endV);
    vectorToFile(endV);



    // Binary Search

    // Get search target value
    cout << "Binary Search" << endl;
    cout << "What is target value: ";
    searchValue = validate.getInt();

    // Use binarySearch to find searchValue in num.txt
    if(binarySearch(numV, searchValue) != -1)
    {
        cout << "num.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "num.txt: target value not found" << endl << endl;
    }

    // Use binarySearch to find searchValue in early.txt
    if(binarySearch(earlyV, searchValue) != -1)
    {
        cout << "early.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "early.txt: target value not found" << endl << endl;
    }

    // Use binarySearch to find searchValue in mid.txt
    if(binarySearch(midV, searchValue) != -1)
    {
        cout << "mid.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "mid.txt: target value not found" << endl << endl;
    }

    // Use binarySearch to find searchValue in end.txt
    if(binarySearch(endV, searchValue) != -1)
    {
        cout << "end.txt: target value found" << endl << endl;
    }
    else
    {
        cout << "end.txt: target value not found" << endl << endl;
    }

    return 0;
}