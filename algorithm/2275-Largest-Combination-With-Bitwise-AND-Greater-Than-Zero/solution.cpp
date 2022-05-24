#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    int maxResult = 0;
    vector<int> recordList(24, 0);
    for (int i = 0; i < candidates.size(); i++)
    {
      int target = candidates[i];

      for (int j = 23; j >= 0; j--)
      {
        if (target >= pow(2, j))
        {
          recordList[j] += 1;
          if (recordList[j] > maxResult)
            maxResult = recordList[j];
          target -= pow(2, j);
        }
      }
    }
    for (int i = 0; i <= 23; i++)
    {
      cout << recordList[i] << " ";
    }

    return maxResult;
  }
};