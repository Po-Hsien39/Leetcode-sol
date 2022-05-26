/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(n^2)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int max = 0, start = 0, ind = 0, currInd, currMax, prev, next;
    while (ind < s.size())
    {
      currInd = ind;
      while (currInd < s.size() - 1 && s[currInd] == s[currInd + 1])
        currInd++;
      prev = ind, next = currInd;
      while (true)
      {
        if (s[prev] == s[next])
        {
          if (prev == 0 || next == s.size() - 1)
            break;
          else
          {
            prev--;
            next++;
          }
        }
        else
        {
          prev++;
          next--;
          break;
        }
      }
      currMax = next - prev + 1;
      if (currMax > max)
      {
        start = ind - ((currMax - (currInd - ind)) / 2);
        max = currMax;
      }
      ind = currInd + 1;
    }
    return s.substr(start, max);
  }
};