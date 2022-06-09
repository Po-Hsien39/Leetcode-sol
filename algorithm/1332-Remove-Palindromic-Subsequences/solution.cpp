/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/8
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int removePalindromeSub(string s) {
    int sPoint = 0;
    int ePoint = s.size() - 1;
    while (sPoint <= ePoint) {
      if (s[sPoint] != s[ePoint]) return 2;
      sPoint++;
      ePoint--;
    }
    return 1;
  }
};