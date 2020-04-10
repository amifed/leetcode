/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.65%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 57K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
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

struct ListNode *partition(struct ListNode *head, int x) {
  if (head == NULL || head->next == NULL) return head;
  struct ListNode *before = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *after = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *p = before, *q = after;
  while (head != NULL) {
    if (head->val < x) {
      p->next = head;
      p = p->next;
    } else {
      q->next = head;
      q = q->next;
    }
    head = head->next;
  }
  q->next = NULL;
  p->next = after->next;
  return before->next;
}

// @lc code=end
