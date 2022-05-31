/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/31
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    unordered_map<int, bool> intMap;
    for (int &target : arr)
    {
      if (intMap[target * 2] || (target % 2 == 0 && intMap[target / 2]))
        return true;
      intMap[target] = true;
    }
    return false;
  }
};