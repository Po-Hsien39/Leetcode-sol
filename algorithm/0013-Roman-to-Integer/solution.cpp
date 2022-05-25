/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(n)
Space Complexity: O(1)
Solution: Using map to record Char => Int
------------------------------------------
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    map<string, int> charMap = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
    };
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
      int target = charMap[s.substr(i, 1)];

      int next = -1;
      if (i < s.size() - 1)
        next = charMap[s.substr(i + 1, 1)];
      if (i == (s.size() - 1) || target >= next)
        sum += target;
      else
        sum -= target;
    }
    return sum;
  }
};
