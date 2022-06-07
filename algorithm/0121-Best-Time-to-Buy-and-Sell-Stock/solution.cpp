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
  int maxProfit(vector<int>& prices) {
    int buyPrice = INT_MAX;
    int maxPro = 0;
    for (int i = 1; i < prices.size(); i++) {
      buyPrice = min(buyPrice, prices[i - 1]);
      maxPro = max(maxPro, prices[i] - buyPrice);
    }
    return maxPro;
  }
};