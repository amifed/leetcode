/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.45%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 89.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
  if (head == NULL) return head;
  struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode *pre = L, *p, *r, *pm;
  L->next = head;
  while (m > 1) {
    pre = pre->next;
    m--;
    n--;
  }
  pm = pre->next;
  p = pre->next;
  pre->next = NULL;
  while (n > 0 && p != NULL) {
    r = p;
    p = p->next;
    r->next = pre->next;
    pre->next = r;
    n--;
  }
  pm->next = p;
  return L->next;
}

// @lc code=end
// [1]\n1\n1