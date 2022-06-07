#include <iostream>

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;
    int sum1 = 2;
    int sum2 = 1;
    int res;
    for (int i = 3; i <= n; i++) {
      res = sum1 + sum2;
      sum2 = sum1;
      sum1 = res;
    }
    return res;
  }
};