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

#include "FibonacciR.hpp"
#include <iostream>

FibonacciR::FibonacciR() {
}

FibonacciR::FibonacciR(const int &n):n_(&n){
}

FibonacciR::~FibonacciR() {
}

int FibonacciR::Fibonacci(const int &n){
 	if(n==0)
  		return 0;
  	else if(n==1)
  		return 1;
  	return Fibonacci(n-1) + Fibonacci(n-2);
}
void FibonacciR::PrintFibonacci(){
 	int FibonaciNum=Fibonacci(*n_);
 	std::cout<<*n_<<"th fibonacci number: "<<FibonaciNum<<std::endl;
}
