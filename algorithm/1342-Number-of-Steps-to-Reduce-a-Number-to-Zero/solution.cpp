/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(lgn)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>

using namespace std;

class Solution
{
public:
  int numberOfSteps(int num)
  {
    int count = 0;
    while (num != 0)
    {
      if (num % 2 == 0)
        num /= 2;
      else
        num -= 1;
      count++;
    }
    return count;
  }
};
