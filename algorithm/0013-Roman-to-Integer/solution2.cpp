/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(n)
Space Complexity: O(1)
Solution: Using if-else statement to record Char => Int, faster than previous solution
------------------------------------------
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
  int getInt(char target)
  {
    if (target == 'I')
      return 1;
    else if (target == 'V')
      return 5;
    else if (target == 'X')
      return 10;
    else if (target == 'L')
      return 50;
    else if (target == 'C')
      return 100;
    else if (target == 'D')
      return 500;
    else
      return 1000;
  }

  int romanToInt(string s)
  {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (i < s.size() - 1)
      {
        int target = getInt(s[i]);
        if (target < getInt(s[i + 1]))
          sum -= target;
        else
          sum += target;
      }
      else
        sum += getInt(s[i]);
    }
    return sum;
  }
};
