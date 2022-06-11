/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/10
Time Complexity: O(lgn)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) return mid;
      // If left part is sorted
      if (nums[start] <= nums[mid]) {
        if (target >= nums[start] && target < nums[mid])
          end = mid - 1;
        else
          start = mid + 1;
      } else {  // Else if right part is sorted
        if (target > nums[mid] && target <= nums[end])
          start = mid + 1;
        else
          end = mid - 1;
      }
    }
    return -1;
  }
};