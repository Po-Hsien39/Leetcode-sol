/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/25
Time Complexity: O(nlgn)
Space Complexity: O(n)
Reference: LIS problem(problem 300)
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  static bool sortcol(const vector<int> &v1, const vector<int> &v2)
  {
    return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
  }
  int maxEnvelopes(vector<vector<int>> &envelopes)
  {
    sort(envelopes.begin(), envelopes.end(), sortcol);
    vector<int> maxEnvs;
    for (int i = 0; i < envelopes.size(); i++)
    {
      int target = envelopes[i][1];
      vector<int>::iterator up = lower_bound(maxEnvs.begin(), maxEnvs.end(), target);
      int targetBlock = up - maxEnvs.begin();
      if (targetBlock + 1 > maxEnvs.size()) // Create new vector
        maxEnvs.push_back(target);
      else // Push and Sort
        maxEnvs[targetBlock] = target;
    }
    return maxEnvs.size();
  }
};
