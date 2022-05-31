/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/31
Time Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    bool positive = x > 0;
    long long targetVal = x;
    if (!positive)
      targetVal *= -1;
    string target = to_string(targetVal);
    std::reverse(target.begin(), target.end());
    targetVal = stoll(target);
    if (targetVal > INT_MAX && positive)
      return 0;
    if (!positive && (-targetVal < INT_MIN))
      return 0;
    return targetVal * (positive ? 1 : -1);
  }
};