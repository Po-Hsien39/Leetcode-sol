#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
  vector<vector<int>> output;

public:
  vector<vector<int>> permuteUnique(vector<int> &nums)
  {
    vector<int> combination;
    vector<int> usedList(nums.size(), 0);
    sort(nums.begin(), nums.end());
    insertPermutation(nums, combination, usedList);
    return output;
  }

  void insertPermutation(vector<int> &nums, vector<int> &combine, vector<int> &usedList)
  {
    int current = -100;
    for (int i = 0; i < nums.size(); i++)
    {
      if (usedList[i])
        continue;
      if (current == nums[i])
        continue;
      else
        current = nums[i];

      if (combine.size() == nums.size() - 1)
      {
        vector<int> answer;
        answer.assign(combine.begin(), combine.end());
        answer.push_back(nums[i]);
        this->output.push_back(answer);
      }
      else
      {
        usedList[i] = 1;
        combine.push_back(nums[i]);
        insertPermutation(nums, combine, usedList);
        usedList[i] = 0;
        combine.pop_back();
      }
    }
  }
};
