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

using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {
    int strLength = max(a.size(), b.size());
    string result = "";
    bool accumulate = false;
    for (int i = 0; i < strLength; i++)
    {
      int int1 = 0;
      int int2 = 0;
      if (a.size() > i)
        int1 = a[a.size() - i - 1] - '0';
      if (b.size() > i)
        int2 = b[b.size() - i - 1] - '0';
      int current = int1 + int2;
      if (accumulate)
      {
        current++;
        accumulate = false;
      }
      if (current >= 2)
      {
        current -= 2;
        accumulate = true;
      }
      result.insert(0, to_string(current));
    }
    if (accumulate)
      result.insert(0, "1");
    return result;
  }
};
