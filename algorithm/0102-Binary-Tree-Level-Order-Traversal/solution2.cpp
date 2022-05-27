/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(n)
Space Complexity: O(n)
Algorithm: BFS Algorithm
------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    queue<pair<TreeNode *, int>> nodeLists;
    nodeLists.push({root, 1});
    while (!nodeLists.empty())
    {
      TreeNode *target = nodeLists.front().first;
      int level = nodeLists.front().second;
      nodeLists.pop();
      if (target)
      {
        if (level > result.size())
          result.push_back(vector<int>(1, target->val));
        else
          result[level - 1].push_back(target->val);
        nodeLists.push({target->left, level + 1});
        nodeLists.push({target->right, level + 1});
      }
    }

    return result;
  }
};