/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/28
Time Complexity: O(n)
Space Complexity: O(1)
Solution: https://leetcode.com/problems/missing-number/discuss/2081525/Very-Simple-or-C%2B%2B-solution-or-beats-95
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int sInd = 0;
    for (int i = nums.size() - 1; i > 0; i--)
    {
      if (nums[i] > nums[i - 1])
      {
        for (int j = nums.size() - 1; j > 0; j--)
        {
          if (nums[j] > nums[i - 1])
          {
            swap(nums[i - 1], nums[j]);
            break;
          }
        }
        sInd = i;
        break;
      }
    }
    reverse(nums.begin() + sInd, nums.end());
  }
};