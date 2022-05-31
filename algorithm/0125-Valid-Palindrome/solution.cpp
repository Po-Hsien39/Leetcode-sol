/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/31
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
  bool isPalindrome(string s)
  {
    int sPoint = 0;
    int ePoint = s.size() - 1;
    while (sPoint < ePoint)
    {
      int ascii1 = int(s[sPoint]);
      int ascii2 = int(s[ePoint]);
      while (true)
      {
        if (ascii1 <= 57 && ascii1 >= 48)
          break;
        if (ascii1 < 97)
          ascii1 += 32;
        if (!(ascii1 >= 97 && ascii1 <= 122))
        {
          sPoint++;
          if (sPoint > s.size() - 1)
          {
            ascii1 = 10000;
            break;
          }
          ascii1 = int(s[sPoint]);
        }
        else
          break;
      }
      while (true)
      {
        if (ascii2 <= 57 && ascii2 >= 48)
          break;
        if (ascii2 < 97)
          ascii2 += 32;
        if (!(ascii2 >= 97 && ascii2 <= 122))
        {
          ePoint--;
          if (ePoint < 0)
          {
            ascii2 = 10000;
            break;
          }
          ascii2 = int(s[ePoint]);
        }
        else
          break;
      }
      if (ascii1 != ascii2)
        return false;
      sPoint++;
      ePoint--;
    }
    return true;
  }
};