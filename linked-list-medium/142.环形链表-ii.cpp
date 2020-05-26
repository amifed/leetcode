/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "../ListNode.cpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> visited;
    ListNode *p = head;
    while (p) {
      if (visited.count(p))
        return p;
      visited.insert(p);
      p = p->next;
    }
    return NULL;
  }
};
// @lc code=end
