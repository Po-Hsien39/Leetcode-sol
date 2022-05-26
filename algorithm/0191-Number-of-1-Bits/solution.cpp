/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/26
Time Complexity: O(1)
Space Complexity: O(1)
Solution: Use bitset<32> & to_string to turn n into string
------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  int hammingWeight(uint32_t n)
  {
    string target = bitset<32>(n).to_string();
    int res = 0;
    for (int i = 0; i < target.size(); i++)
    {
      if (target[i] == '1')
        res++;
    }
    return res;
  }
};