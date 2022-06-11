/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/6/10
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> targetMap;
    int sPoint = 0, maxSize = 0, currSize = 0;
    for (int i = 0; i < s.size(); i++) {
      // If there is already this key
      if (targetMap.find(s[i]) != targetMap.end() && targetMap[s[i]] >= sPoint) {
        sPoint = targetMap[s[i]] + 1;
        currSize = i - targetMap[s[i]];
      } else
        currSize++;
      maxSize = max(maxSize, currSize);
      targetMap[s[i]] = i;
    }
    return maxSize;
  }
};

int main() {
  Solution mySol;
  int res = mySol.lengthOfLongestSubstring("baba");
  cout << res << '\n';

  return 0;
}