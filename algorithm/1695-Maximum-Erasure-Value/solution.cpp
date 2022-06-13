#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int sPtr = 0;
    int targetArr[10001];
    memset(targetArr, -1, 10001 * sizeof(int));
    int currentSum = 0, maximum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      currentSum += nums[i];
      if (targetArr[nums[i]] >= sPtr) {
        for (int j = sPtr; j <= targetArr[nums[i]]; j++) currentSum -= nums[j];
        sPtr = targetArr[nums[i]] + 1;
      }
      targetArr[nums[i]] = i;
      maximum = max(maximum, currentSum);
    }
    return maximum;
  }
};