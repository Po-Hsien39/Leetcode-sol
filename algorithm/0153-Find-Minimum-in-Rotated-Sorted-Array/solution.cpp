/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/9
Time Complexity: O(lgn)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int target = nums[0];
    int sInd = 1, eInd = nums.size() - 1;
    while (sInd < eInd) {
      int mid = (sInd + eInd) / 2;
      if (nums[mid] < target && nums[mid] < nums[mid - 1]) return nums[mid];
      if (nums[mid] > target)
        sInd = mid + 1;
      else
        eInd = mid - 1;
    }
    return target;
  }
};