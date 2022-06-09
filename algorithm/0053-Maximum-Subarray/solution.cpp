/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/8
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], current = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (current < 0) current = 0;
      current += nums[i];
      maxSum = max(maxSum, current);
    }
    return maxSum;
  }
};