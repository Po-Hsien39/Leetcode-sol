/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(nlgn)
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
      vector<int>::iterator up = lower_bound(lisLengths.begin(), lisLengths.end(), target);
      int targetBlock = up - lisLengths.begin();
      if (targetBlock + 1 > lisLengths.size()) // Create new vector
        lisLengths.push_back(target);
      else // Push and Sort
        lisLengths[targetBlock] = target;
    }
    return lisLengths.size();
  }
};