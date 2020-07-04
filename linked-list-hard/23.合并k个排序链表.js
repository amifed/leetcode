/*
 * @lc app=leetcode.cn id=23 lang=javascript
 *
 * [23] 合并K个排序链表
 */
import { ListNode } from "../ListNode";
// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
const mergeKLists = function (lists) {
  if (lists.length === 0) return null;
  const mergeTwoLists = (l1, l2) => {
    if (l1 === null) return l2;
    if (l2 === null) return l1;
    if (l1.val < l2.val) {
      l1.next = mergeTwoLists(l1.next, l2);
      return l1;
    } else {
      l2.next = mergeTwoLists(l1, l2.next);
      return l2;
    }
  };
  const merge = (left, right) => {
    if (left === right) return lists[left];
    let mid = (left + right) >> 1;
    return mergeTwoLists(merge(left, mid), merge(mid + 1, right));
  };
  return merge(0, lists.length - 1);
};
// @lc code=end
