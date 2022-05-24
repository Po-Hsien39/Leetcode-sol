#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
private:

    vector<Node *> nodeList;

public:
    Node* connect(Node* root) {
        if (root) connectSingle(root, 0);
        return root;
    }

    void connectSingle(Node* target, int layer){
      if (layer == nodeList.size()) nodeList.push_back(target);
      else {
        nodeList[layer]->next = target;
        nodeList[layer] = target;
      }
      if (target->left) connectSingle(target->left, layer + 1);
      if (target->right) connectSingle(target->right, layer + 1);
    }

};