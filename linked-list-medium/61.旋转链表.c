/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (39.99%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    53.3K
 * Total Submissions: 133.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
 * 
 */
#include <stdlib.h>

#include "ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
  if (k <= 0 || head == NULL) return head;
  int n = 1;
  struct ListNode* p = head;
  while (p->next != NULL) {  // 求长度
    p = p->next;
    n++;
  }
  if (n == k || n == 1)  // 求位置
    return head;
  else if (k > n)
    k = n - (k % n) - 1;
  else
    k = n - k - 1;
  p->next = head;  // 链表成环
  p = head;        // 重新搜索
  while (k > 0) {
    p = p->next;
    k--;
  }
  head = p->next;  // 链表解环
  p->next = NULL;
  return head;
}

// @lc code=end
// [0,1,2]\n4
// [1,2,3,4,5,6]\n7
// [1,2]\n2