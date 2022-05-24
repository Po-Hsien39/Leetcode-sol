// This solution try to use recursive function to solve the problem
// DFS

#include <iostream>
#include <vector>

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
  bool arrive;
  vector<int> result;

public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
  {
    this->arrive = false;
    vector<int> paths;
    findPath(original, paths, target);
    TreeNode *finalAns = cloned;

    for (int i = 0; i < this->result.size(); i++)
    {
      cout << this->result[i] << " ";
      if (this->result[i] == 0)
        finalAns = finalAns->left;
      else
        finalAns = finalAns->right;
    }

    return finalAns;
  }

  void findPath(TreeNode *current, vector<int> &paths, TreeNode *target)
  {
    if (arrive)
      return;
    if (current == target)
    {
      this->arrive = true;
      // this->result(paths);
      for (int i = 0; i < paths.size(); i++)
        this->result.push_back(paths[i]);

      return;
    }

    if (current->left)
    {
      paths.push_back(0);
      findPath(current->left, paths, target);
      paths.pop_back();
    }
    if (current->right)
    {
      paths.push_back(1);
      findPath(current->right, paths, target);
      paths.pop_back();
    }
  }
};