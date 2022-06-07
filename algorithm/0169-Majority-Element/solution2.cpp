/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/7
Time Complexity: O(n)
Space Complexity: O(1)
Algoithm: Boyer–Moore majority vote algorithm
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int res = 1;
    int currentTarget = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (currentTarget == nums[i]) {
        res++;
      } else {
        if (res == 0) {
          res++;
          currentTarget = nums[i];
        } else if (res > 0) {
          res--;
        }
      }
    }
    return currentTarget;
  }
};