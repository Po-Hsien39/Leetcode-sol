#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> result;

public:
  vector<vector<int>> combinationSum3(int k, int n)
  {
    vector<int> current;
    getCombination(k, n, current, 1);
    return result;
  }

  void getCombination(int k, int n, vector<int> &current, int target)
  {
    if (target > 9)
      return;
    if (k == 1)
    {
      if (n >= target && n <= 9)
      {
        vector<int> newVect;
        newVect.assign(current.begin(), current.end());
        newVect.push_back(n);
        this->result.push_back(newVect);
      }
      return;
    }
    if (n <= target)
      return;
    // Case when choosing target
    current.push_back(target);
    getCombination(k - 1, n - target, current, target + 1);
    current.pop_back();
    // Case when not choosing target
    getCombination(k, n, current, target + 1);
  }
};
