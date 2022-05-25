/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(n^2)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    vector<int> lisLengths;
    for (int i = 0; i < nums.size(); i++)
    {
      int target = nums[i];
      int targetBlock = 0;
      for (int j = lisLengths.size() - 1; j >= 0; j--)
      {
        if (target > lisLengths[j])
        {
          targetBlock = j + 1;
          break;
        }
      }
      if (targetBlock + 1 > lisLengths.size()) // Create new vector
        lisLengths.push_back(target);
      else // Push and Sort
        lisLengths[targetBlock] = target;
    }
    return lisLengths.size();
  }
};