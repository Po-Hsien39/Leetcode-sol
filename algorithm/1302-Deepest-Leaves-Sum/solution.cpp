#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    int deepLeavesSum;
    int currentLayer;

public:
    int deepestLeavesSum(TreeNode* root) {
        this->deepLeavesSum = 0;
        this->currentLayer = -1;
        findChildren(root, 0);
        return this->deepLeavesSum;
    }

    void findChildren(TreeNode* root, int layer){
        if (layer > this->currentLayer) {
          this->currentLayer = layer;
          this->deepLeavesSum = root->val;
        }else this->deepLeavesSum += root->val;
        if (root->left) findChildren(root->left, layer + 1);
        if (root->right) findChildren(root->right, layer + 1);
    }

};