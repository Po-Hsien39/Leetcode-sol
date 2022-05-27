/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(m * n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    string result = "";
    bool sameChr = true;
    for (int i = 0; i < strs[0].size(); i++)
    {
      char target = strs[0][i];

      for (int j = 0; j < strs.size(); j++)
        if (strs[j][i] != target)
        {
          sameChr = false;
          break;
        }
      if (!sameChr)
        break;
      result += target;
    }
    return result;
  }
};