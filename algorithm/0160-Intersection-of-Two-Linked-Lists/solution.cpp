#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = getLength(headA);
    int lengthB = getLength(headB);
    int maxLen = max(lengthA, lengthB);
    for (int i = 0; i < maxLen; i++) {
      if (!headA || !headB) return nullptr;

      if (lengthB > lengthA) {
        lengthB--;
        headB = headB->next;
        continue;
      } else if (lengthA > lengthB) {
        lengthA--;
        headA = headA->next;
        continue;
      } else {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
      }
    }
    return nullptr;
  }
  int getLength(ListNode *head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
  }
};