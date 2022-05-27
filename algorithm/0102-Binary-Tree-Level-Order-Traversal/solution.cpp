/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(n)
Space Complexity: O(1)
Algorithm: DFS Algorithm
------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void getLevel(TreeNode *current, int level, vector<vector<int>> &result)
  {
    if (current)
    {
      if (level > result.size())
        result.push_back(vector<int>(1, current->val));
      else
        result[level - 1].push_back(current->val);
      getLevel(current->left, level + 1, result);
      getLevel(current->right, level + 1, result);
    }
  }

  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    getLevel(root, 1, result);
    return result;
  }
};