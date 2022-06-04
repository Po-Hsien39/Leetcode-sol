#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
public:
  string target = "";
  bool positive = true;
  bool start = false;
  bool intStart = false;
  int myAtoi(string s)
  {
    for (char key : s)
    {
      int asciiKey = int(key);
      if (!start)
      {
        if (key == '-')
        {
          positive = false;
          start = true;
        }
        else if (key == '+')
          start = true;
        else if (asciiKey <= 57 && asciiKey >= 48)
        {
          start = true;
          if (asciiKey != 48)
          {
            target += key;
            intStart = true;
          }
        }
        else if (key != ' ')
          return 0;
      }
      else
      {
        if (asciiKey <= 57 && asciiKey >= 48)
        {
          if (!intStart && key == '0')
            continue;
          target += key;
          intStart = true;
        }
        else
          break;
      }
    }
    long long result = 0;
    if (target.size() > 10)
      if (positive)
        return INT_MAX;
      else
        return INT_MIN;
    for (int i = 0; i < target.size(); i++)
      result += (pow(10, target.size() - i - 1) * (target[i] - '0'));
    if (!positive)
      result *= -1;
    if (result > INT_MAX)
      return INT_MAX;
    if (result < INT_MIN)
      return INT_MIN;
    return result;
  }
};