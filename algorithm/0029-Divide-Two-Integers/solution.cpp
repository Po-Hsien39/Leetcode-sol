/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/30
Source: LeetCode Discussion
Space Complexity: O(1)
Solution: Using the way bit division to solve the problem
How bit division?: https://www.cuemath.com/numbers/binary-division/
------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution
{
public:
  int divide(int dividend, int divisor)
  {
    if (dividend == divisor)
      return 1;
    if (dividend == 0)
      return 0;
    unsigned int newDividend = abs(dividend);
    unsigned int newDivisor = abs(divisor);
    unsigned int result = 0;
    bool positive = (dividend < 0 == divisor < 0);
    while (newDividend >= newDivisor)
    {
      int pow = 0;
      while (newDividend > (newDivisor << (pow + 1)))
        pow++;
      newDividend -= (newDivisor << pow);
      result += (1 << pow);
    }
    if (result == (1 << 31) && positive)
      return INT_MAX;

    return result * (positive ? 1 : -1);
  }
};