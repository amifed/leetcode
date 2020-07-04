/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // count nodes and to cycle
        int n = 1;
        ListNode *p = head;
        while (p->next) {
            n++;
            p = p->next;
        }
        p->next = head;
        // find pos
        k %= n;
        n = n - k - 1;
        ListNode *pre = head;
        for (int i = 0; i < n; i++)
            pre = pre->next;
        p = pre->next;
        pre->next = nullptr;
        return p;
    }
};
// @lc code=end
