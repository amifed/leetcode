/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode *, ListNode *> reverseList(ListNode *head, ListNode *tail) {
        ListNode *pre = tail->next;
        ListNode *p = head;
        while (pre != tail) {
            ListNode *nex = p->next;
            p->next = pre;
            pre = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;
        while (head) {
            ListNode *tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail)
                    return hair->next;
            }
            ListNode *nex = tail->next;
            auto ret = reverseList(head, tail);
            head = ret.first, tail = ret.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};
// @lc code=end
