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
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    int startSum = 1;
    int endSum = 1;
    for (int i = 1; i < nums.size(); i++) {
      startSum *= nums[i - 1];
      result[i] *= startSum;
      int j = nums.size() - i - 1;
      endSum *= nums[j + 1];
      result[j] *= endSum;
    }
    return result;
  }
};