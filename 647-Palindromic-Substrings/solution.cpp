#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{

public:
  int countSubstrings(string s)
  {
    vector<vector<bool>> palindromList;
    for (int i = 0; i < s.size(); i++)
    {
      vector<bool> temp;
      temp.assign(s.size(), false);
      temp[i] = true;
      palindromList.push_back(temp);
    }
    int result = s.size();
    for (int i = 1; i < palindromList.size(); i++)
    {
      for (int j = 0; j + i < palindromList[i].size(); j++)
      {
        int sPoint = j, ePoint = i + j;
        bool target = false;
        if (s[sPoint] == s[ePoint])
        {
          if (ePoint - sPoint == 1)
            target = true;
          else
            target = palindromList[sPoint + 1][ePoint - 1];
        }
        if (target)
        {
          palindromList[sPoint][ePoint] = target;
          result++;
        }
      }
    }
    return result;
  }
};
