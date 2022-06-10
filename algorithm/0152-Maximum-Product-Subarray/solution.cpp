/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/9
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0], curNegative = nums[0];
    int firstNeg = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (currentSum == 0) {
        currentSum = nums[i];
        curNegative = nums[i];
        if (nums[i] < 0) firstNeg = i;
      } else {
        currentSum *= nums[i];
        if (curNegative > 0) {
          curNegative *= nums[i];
          if (nums[i] < 0) firstNeg = i;
        }
      }
      if (currentSum != 0) {
        int currMax = firstNeg == i ? currentSum : max(currentSum, currentSum / curNegative);
        maxSum = max(maxSum, currMax);
      } else
        maxSum = max(maxSum, 0);
    }
    return maxSum;
  }
};