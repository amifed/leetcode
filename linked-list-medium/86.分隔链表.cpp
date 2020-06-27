/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        ListNode *p1 = h1, *p2 = h2;
        while (head != NULL) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = h2->next;
        return h1->next;
    }
};
// @lc code=end
