#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    vector<char> brackets;
    for (int i = 0; i < s.size(); i++)
    {
      char target = s[i];
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        brackets.push_back(s[i]);
      else
      {
        if (brackets.size() == 0)
          return false;
        char prevChr = brackets.back();
        brackets.pop_back();
        if (!((s[i] == ')' && prevChr == '(') || (s[i] == ']' && prevChr == '[') || (s[i] == '}' && prevChr == '{')))
          return false;
      }
    }
    if (brackets.size() != 0)
      return false;
    return true;
  }
};