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

#include "FibonacciNR.hpp"

#include <iostream>

FibonacciNR::FibonacciNR() {

}

FibonacciNR::FibonacciNR(const int &n):n_(&n){

}

FibonacciNR::~FibonacciNR() {
}

int FibonacciNR::Fibonacci(const int &n)
{
    int first =0;
    int second=1;
    int counter=2;
    while(counter < n)
    {
        int temp=second;
        second=first+second;
        first=temp;
        ++counter;
    }
    if(n==0)
        return 0;
    else
        return first+second;
}
void FibonacciNR::PrintFibonacci(){
    const int result = Fibonacci(*n_);
    std::cout<<*n_<<"th fibonacci Number:"<<result<<std::endl;
}
