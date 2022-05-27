/*
------------------------------------------
Name: Tristan Wu
File: solution.cpp
Date: 2022/5/27
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
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
  void findTraverse(TreeNode *current, vector<int> &target)
  {
    if (current)
    {
      findTraverse(current->left, target);
      target.push_back(current->val);
      findTraverse(current->right, target);
    }
  }
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> target;
    findTraverse(root, target);
    return target;
  }
};