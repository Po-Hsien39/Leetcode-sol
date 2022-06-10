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
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int sInd = 0, eInd = numbers.size() - 1;
    while (sInd < eInd) {
      if (numbers[sInd] + numbers[eInd] == target)
        break;
      else if (numbers[sInd] + numbers[eInd] < target)
        sInd++;
      else
        eInd--;
    }
    result.push_back(sInd + 1);
    result.push_back(eInd + 1);
    return result;
  }
};