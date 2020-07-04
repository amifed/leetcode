/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 */
#include <stdlib.h>

#include "../ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  if (l1 == NULL)
    return l2;
  else if (l2 == NULL)
    return l1;
  else {
    if (l1->val < l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
}
struct ListNode* merge(struct ListNode** lists, int left, int right) {
  if (left == right) return lists[left];
  int mid = (left + right) >> 1;
  return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if (listsSize == 0) return NULL;
  return merge(lists, 0, listsSize - 1);
}

// @lc code=end
