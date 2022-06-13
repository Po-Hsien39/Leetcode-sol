/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/11
Time Complexity: O(n)
Space Complexity: O(1)
Method: Sliding Window Method
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int totals = 0;
    for (int i = 0; i < nums.size(); i++) totals += nums[i];
    if (totals < x) return -1;
    if (totals == x) return nums.size();
    int target = totals - x, slidingSum = 0, maxLength = -1, eInd = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0) slidingSum -= nums[i - 1];
      while (slidingSum < target && eInd < nums.size()) {
        slidingSum += nums[eInd];
        eInd++;
      }
      if (slidingSum == target) maxLength = max(maxLength, eInd - i);
    }
    return maxLength == -1 ? -1 : nums.size() - maxLength;
  }
};
