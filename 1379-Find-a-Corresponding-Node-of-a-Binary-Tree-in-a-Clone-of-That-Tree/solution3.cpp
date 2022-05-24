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
        queue<TreeNode*> answerList;
        TreeNode* finalAns;
        answerList.push(cloned);
        while (!answerList.empty()){
            TreeNode* answer = answerList.front();
            answerList.pop();
            if (answer->val == target->val){
              finalAns = answer;
              break;
            }
            if (answer->left) answerList.push(answer->left);
            if (answer->right) answerList.push(answer->right);
        }
        return finalAns;
    }
};