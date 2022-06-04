#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    ListNode *current = nullptr;
    while (!current || current->next)
    {
      ListNode *target;
      if (!current)
        target = head;
      else
        target = current->next;

      if (!target || !target->next)
        break;
      ListNode *first = target;
      ListNode *second = target->next;
      ListNode *last = target->next->next;
      second->next = first;
      first->next = last;

      current = first;
    }
    return head;
  }
};