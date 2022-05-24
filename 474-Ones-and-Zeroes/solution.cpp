// Recursive

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
  int result;
  vector<vector<vector<int>>> recordList;

public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    this->recordList.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    this->result = 0;
    return getForm(strs, strs.size() - 1, m, n);
  }
  int getForm(vector<string> &strs, int s, int m, int n)
  {
    if (s < 0)
      return 0;

    if (this->recordList[s][m][n] != -1)
      return this->recordList[s][m][n];

    string target = strs[s];
    int count0 = 0, count1 = 0;
    for (int i = 0; i < target.size(); i++)
    {
      if (target[i] == '0')
        count0++;
      else
        count1++;
    }
    if (m >= count0 && n >= count1)
      this->recordList[s][m][n] = max(getForm(strs, s - 1, m, n), getForm(strs, s - 1, m - count0, n - count1) + 1);
    else
      this->recordList[s][m][n] = getForm(strs, s - 1, m, n);

    return this->recordList[s][m][n];
  }
};