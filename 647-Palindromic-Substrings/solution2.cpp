#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{

public:
  int countSubstrings(string s)
  {
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
      result += getPalindrom(i, i, s);
      result += getPalindrom(i, i + 1, s);
    }
    return result;
  }
  int getPalindrom(int prev, int next, string s)
  {
    int sum = 0;
    while (true)
    {
      if (prev < 0 || next > s.size() - 1)
        break;
      if (s[prev] == s[next])
      {
        sum++;
        prev--;
        next++;
      }
      else
        break;
    }
    return sum;
  }
};
