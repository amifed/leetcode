/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        ListNode *odd = new ListNode, *even = new ListNode;
        ListNode *p = odd, *q = even;
        while (head) {
            p->next = head, p = p->next;
            head = head->next;
            q->next = head, q = q->next;
            if (head != nullptr)
                head = head->next;
        }
        p->next = even->next;
        return odd->next;
    }
};
// @lc code=end
