/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/7
Time Complexity: O(nlgn)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int cur = nums[0];
    int curSum = 1;
    int maxSum = 0;
    int maxTarget = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (cur == nums[i])
        curSum++;
      else {
        cur = nums[i];
        curSum = 1;
      }
      if (curSum > maxSum) {
        maxSum = curSum;
        maxTarget = nums[i];
      }
    }
    return maxTarget;
  }
};