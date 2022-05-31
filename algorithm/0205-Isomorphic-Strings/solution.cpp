/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/31
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    unordered_map<char, char> letters;
    unordered_map<char, bool> haveUsed;
    for (int i = 0; i < s.length(); i++)
    {
      if (letters.find(s[i]) != letters.end())
      {
        if (letters[s[i]] != t[i])
          return false;
      }
      else
      {
        if (haveUsed.find(t[i]) != haveUsed.end())
          return false;
        letters[s[i]] = t[i];
        haveUsed[t[i]] = true;
      }
    }
    return true;
  }
};