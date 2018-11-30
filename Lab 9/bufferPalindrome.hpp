/*****************************************************************************
 * Program name: bufferPalindrome
 * Author: Kevin Harvell
 * Date: 5/30/2018
 * Description: bufferPalindrome either simulates a buffer using a queue or
 * creates a palindrome using a stack.
*****************************************************************************/

#include <queue>
#include <stack>


#ifndef BUFFERPALINDROME_HPP
#define BUFFERPALINDROME_HPP

void promptSettings(int &numRounds, int &pushChance, int &popChance);
void printBuffer(std::queue<int> buffer);

#endif
