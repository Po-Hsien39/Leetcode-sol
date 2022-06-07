/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/7
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int ptr1 = m - 1;
    int ptr2 = n - 1;
    for (int i = m + n - 1; i >= 0; i--) {
      if (ptr2 < 0) continue;
      if (ptr1 < 0) {
        nums1[i] = nums2[ptr2];
        ptr2--;
      }
      if (nums2[ptr2] > nums1[ptr1]) {
        nums1[i] = nums2[ptr2];
        ptr2--;
      } else {
        nums1[i] = nums1[ptr1];
        ptr1--;
      }
    };
  }
};