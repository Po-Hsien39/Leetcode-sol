/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/11
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    map<int, int> targetMap;
    targetMap[x] = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (sum > x) break;
      targetMap[x - sum] = i + 1;
    }
    int minOperation = INT_MAX;
    for (int i = nums.size(); i >= 0; i--) {
      if (i == nums.size())
        sum = 0;
      else
        sum += nums[i];
      if (sum > x) break;
      if (targetMap.find(sum) != targetMap.end()) {
        if (i > targetMap[sum] - 1)
          minOperation = min(minOperation, targetMap[sum] + (int)nums.size() - i);
        else
          break;
      }
    }
    return minOperation == INT_MAX ? -1 : minOperation;
  }
};