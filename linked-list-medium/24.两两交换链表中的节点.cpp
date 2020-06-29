/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *swapPairs(ListNode *head) {
    //     ListNode *odd = new ListNode(0), *even = new ListNode(0);
    //     ListNode *p = odd, *q = even;
    //     while (head) {
    //         p->next = head, p = p->next;
    //         head = head->next;
    //         q->next = head, q = q->next;
    //         if (head != nullptr)
    //             head = head->next;
    //     }
    //     p->next = NULL;
    //     ListNode *ret = new ListNode(0);
    //     ListNode *r = ret;
    //     odd = odd->next, even = even->next;
    //     while (odd && even) {
    //         r->next = even;
    //         even = even->next;
    //         r = r->next;
    //         r->next = odd;
    //         odd = odd->next;
    //         r = r->next;
    //     }
    //     r->next = odd ? odd : even;
    //     return ret->next;
    // }
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
// @lc code=end
