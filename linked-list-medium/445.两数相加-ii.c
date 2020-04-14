/*
 * @lc app=leetcode.cn id=445 lang=c
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (54.65%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    20K
 * Total Submissions: 36K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 进阶：
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 8 -> 0 -> 7
 * 
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
#define MAX_SIZE 100
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
  int top1 = -1, top2 = -1;
  int* s1 = (int*)calloc(MAX_SIZE, sizeof(int));
  int* s2 = (int*)calloc(MAX_SIZE, sizeof(int));
  while (l1) {
    s1[++top1] = l1->val;
    l1 = l1->next;
  }
  while (l2) {
    s2[++top2] = l2->val;
    l2 = l2->next;
  }
  struct ListNode* ans = NULL;
  int carry = 0;
  while (top1 > -1 || top2 > -1 || carry != 0) {
    int a = top1 > -1 ? s1[top1--] : 0;
    int b = top2 > -1 ? s2[top2--] : 0;
    int num = a + b + carry;
    carry = num / 10;
    num %= 10;
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = num;
    node->next = ans;
    ans = node;
  }
  return ans;
}

// @lc code=end
