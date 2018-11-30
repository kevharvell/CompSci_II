/*****************************************************************************
 * Program name: Lab 10
 * Author: Kevin Harvell
 * Date: 6/4/2018
 * Description: Lab 10 borrows code from julian using fibonacci recursive and
 * non-recursive algorithms in order to assess run times between the two types
 * of algorithms.
*****************************************************************************
*
* The following code was modified from:
*
* Program.cpp
*
*  OS: Fedora 13
*  Language: Native C++
*  Compiler: GNU g++
*  Created on: Sep 11, 2010
*      Author: julian
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
using namespace std;

int main() {
    clock_t t;
    t = clock();

    unsigned int n=40;

    cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
    cout<<"\nCalling Recursive Fibonacci implementation"<<endl;
    FibonacciR fr(n);
    fr.PrintFibonacci();
    t = clock() - t;
    cout << "It took me " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds).\n";

    t = clock();
    cout<<"\nCalling Non-Recursive Fibonacci implementation"<<endl;
    FibonacciNR fnr(n);
    fnr.PrintFibonacci();
    t = clock() - t;
    cout << "It took me " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds).\n";
    cout << "Done!!!!" << endl;
    return 0;
}