// This solution using BFS & run on two tree at the same time
// 50%

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> nodeList;
        queue<TreeNode*> answerList;
        TreeNode* finalAns;
        nodeList.push(original);
        answerList.push(cloned);
        while (!nodeList.empty()){
            TreeNode* current = nodeList.front();
            TreeNode* answer = answerList.front();
            nodeList.pop();
            answerList.pop();
            if (current == target){
              finalAns = answer;
              break;
            }
            if (current->left) {
              nodeList.push(current->left);
              answerList.push(answer->left);
            }
            if (current->right) {
              nodeList.push(current->right);
              answerList.push(answer->right);
            }
        }
        return finalAns;
    }
};