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
  int missingNumber(vector<int> &nums)
  {
    int totals = (1 + nums.size()) * nums.size() / 2;
    for (int i = 0; i < nums.size(); i++)
      totals -= nums[i];
    return totals;
  }
};