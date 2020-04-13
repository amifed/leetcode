/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (49.62%)
 * Likes:    546
 * Dislikes: 0
 * Total Accepted:    90.5K
 * Total Submissions: 182.3K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
  if (listsSize < 1) return NULL;
  int i, j, cur;
  while (listsSize > 1) {
    for (cur = 0, i = 0, j = listsSize - 1; i < j;)
      lists[cur++] = mergeTwoLists(lists[i++], lists[j--]);
    listsSize = i == j ? cur + 1 : cur;
  }
  return lists[0];
}

// @lc code=end
