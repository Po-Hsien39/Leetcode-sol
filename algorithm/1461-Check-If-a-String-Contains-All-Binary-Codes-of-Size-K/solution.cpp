/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/31
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool hasAllCodes(string s, int k)
  {
    int reqSize = 1 << k;
    int allOne = reqSize - 1;
    if (s.size() < reqSize)
      return false;
    bool target[reqSize];
    memset(target, 0, reqSize);

    int sum = 0;
    int number;
    for (int i = 0; i < s.size() - k + 1; i++)
    {
      if (i == 0)
        number = stoi(s.substr(i, k), 0, 2);
      else
        number = ((number << 1) & allOne) | (s[i] - '0');
      if (!target[number])
      {
        target[number] = true;
        sum++;
      }
    }

    if (sum == reqSize)
      return true;
    return false;
  }
};