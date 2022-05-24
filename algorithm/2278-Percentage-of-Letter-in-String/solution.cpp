#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution
{
public:
  int percentageLetter(string s, char letter)
  {
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
      if (s[i] == letter)
        sum++;
    return round(sum * 100 / s.size());
  }
};