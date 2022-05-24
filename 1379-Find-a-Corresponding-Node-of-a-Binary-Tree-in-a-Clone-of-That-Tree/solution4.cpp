// This solution only run on the target tree(if value is the same, then return)

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
  TreeNode *result;

public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
  {
    this->result = 0;
    isSame(cloned, target);
    return this->result;
  }

  void isSame(TreeNode *current, TreeNode *target)
  {
    if (this->result)
      return;
    if (current->val == target->val)
    {
      this->result = current;
      return;
    }
    if (current->left)
      isSame(current->left, target);
    if (current->right)
      isSame(current->right, target);
  }
};