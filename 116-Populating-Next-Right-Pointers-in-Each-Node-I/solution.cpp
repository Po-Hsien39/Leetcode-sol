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
        Node* current = root;

        while (current && current->left){
            Node* nextStartPtr = current;
            do
            {
                current->left->next = current->right;
                if (current->next) current->right->next = current->next->left;
                current = current->next;
            } while (current);
            current = nextStartPtr->left;
        }

        return root;
    }
};