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

#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR {
public:
    FibonacciR(const int &n);
    virtual ~FibonacciR();
    void PrintFibonacci();
private:
    FibonacciR();
    int Fibonacci(const int &n);
    const int *n_;
};


#endif
