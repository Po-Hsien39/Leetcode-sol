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
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    return !(transformation(s).compare(transformation(t)));
  }

  string transformation(string target)
  {
    string result = "";
    unordered_map<char, int> characters;
    for (int i = 0; i < target.size(); i++)
    {
      if (characters.find(target[i]) == characters.end())
        characters[target[i]] = i;
      result += to_string(target[i]);
    }
    return result;
  }
};