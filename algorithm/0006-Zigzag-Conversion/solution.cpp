/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    string result = "";
    int gaps = 2 * (numRows - 1);
    for (int i = 0; i < numRows; i++)
    {
      int currGap = 2 * (numRows - i - 1);
      int index = 0;
      while (index <= s.size())
      {
        result += s[index];
        if (!currGap)
        {
          index += currGap;
          currGap = gaps - currGap;
        }
        else
        {
          currGap = gaps - currGap;
          index += currGap;
        }
      }
    }
    return result;
  }
};

int main()
{
  return 0;
}