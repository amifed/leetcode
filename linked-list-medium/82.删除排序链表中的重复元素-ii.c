/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (46.91%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    39.8K
 * Total Submissions: 84.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 * 
 */
#include <ListNode.h>
#include <stdlib.h>
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
  struct ListNode *p, *q, *s;
  while (head != NULL && head->next != NULL && head->val == head->next->val) {
    p = head;
    q = head->next;
    while (q != NULL && p->val == q->val) {
      s = q;
      q = q->next;
      free(s);
    }
    s = head;
    head = q;
    free(s);
  }
  if (head == NULL || head->next == NULL) return head;
  s = head;
  p = s->next;
  q = p->next;
  while (s != NULL && p != NULL && q != NULL) {
    while (q != NULL && p->val == q->val)
      q = q->next;
    if (p->next != q) {
      s->next = q;
      p = s->next;
      if (p != NULL) q = p->next;
    } else {
      s = p;
      p = q;
      q = q->next;
    }
  }
  return head;
}

// @lc code=end
// [1,1,1,2,2,2,3,4]
// [1,1,1,2,2,2]
//  [1,1,1,2,2,2,3,4,5,5,6,7,7,7]
//  [1,1,1,2,2,2,3,4,5,5,6,7,7,7,8,9]