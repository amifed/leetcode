/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.25%)
 * Likes:    906
 * Dislikes: 0
 * Total Accepted:    214.6K
 * Total Submissions: 313.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */
#include <stdlib.h>

#include "./ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  struct ListNode* last = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return last;
}

// @lc code=end
