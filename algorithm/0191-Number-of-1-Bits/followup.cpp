/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/26
Source: LeetCode Discussion
Time Complexity: O(1)
Space Complexity: O(1)
Solution: Record the Answer first & split the input to two 16 bits int
------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  void precompute(int f[])
  {
    const int len = 1 << 16;
    for (int i = 1; i < len; i++)
      f[i] = f[i >> 1] + (i & 1);
  }
  int hammingWeight(uint32_t n)
  {
    const int len = 1 << 16;
    int f[len];
    precompute(f);
    return f[n / len] + f[n % len]; // O(1) call
  }
};