/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
------------------------------------------
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
private:
  vector<vector<int>> result;
  int n;
  int k;

public:
  vector<vector<int>> combine(int n, int k)
  {
    vector<int> target;
    this->n = n;
    this->k = k;
    getCombination(0, target);
    return this->result;
  }
  void getCombination(int pos, vector<int> &target)
  {
    if (target.size() == k)
    {
      vector<int> vect2(target);
      this->result.push_back(vect2);
      return;
    }
    target.push_back(pos + 1);
    getCombination(pos + 1, target);
    target.pop_back();
    if (target.size() + (n - pos - 1) >= k)
      getCombination(pos + 1, target);
  }
};