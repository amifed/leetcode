/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include "../ListNode.cpp"
#include "../TreeNode.cpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
  ListNode *findMiddleNode(ListNode *head) {
    ListNode *pre = NULL, *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    if (pre)
      pre->next = NULL;
    return slow;
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL)
      return NULL;
    ListNode *mid = findMiddleNode(head);
    TreeNode *root = new TreeNode(mid->val);
    if (mid == head)
      return root;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    return root;
  }
};
// @lc code=end
