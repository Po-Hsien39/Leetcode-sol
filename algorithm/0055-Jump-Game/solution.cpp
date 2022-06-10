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
  bool canJump(vector<int>& nums) {
    int arrive = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (i > arrive) return false;
      arrive = max(arrive, i + nums[i]);
      if (arrive >= nums.size() - 1) return true;
    }
    return arrive >= nums.size() - 1;
  }
};