/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/29
Source: LeetCode Discussion
Time Complexity: O(n^2)
Space Complexity: O(1)
Solution: Represent each character by bit
------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    vector<int> wordBits;
    int result = 0;
    for (auto &element : words)
    {
      int target = 0;
      for (int i = 0; i < element.size(); i++)
      {
        int newValue = 1 << (int(element[i]) - 97);
        target = target | newValue;
      }
      wordBits.push_back(target);
    }
    for (int i = 0; i < words.size(); i++)
      for (int j = 0; j < i; j++)
        if (!(wordBits[i] & wordBits[j]))
        {
          int newAns = words[i].size() * words[j].size();
          result = max(result, newAns);
        }
    return result;
  }
};