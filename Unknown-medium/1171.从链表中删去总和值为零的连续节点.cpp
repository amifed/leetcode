/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode *removeZeroSumSublists(ListNode *head) {
        ListNode *L = new ListNode(0);
        L->next = head;
        unordered_map<int, ListNode *> prefixSumMap;
        ListNode *p = L;
        int prefixSum = 0;
        while (p) {
            prefixSum += p->val;
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                p = prefixSumMap[prefixSum]->next;
                int sum = prefixSum + p->val;
                while (prefixSum != sum) {
                    prefixSumMap.erase(sum);
                    p = p->next;
                    sum += p->val;
                }
                prefixSumMap[prefixSum]->next = p->next;
            } else
                prefixSumMap.insert({prefixSum, p});
            p = p->next;
        }
        return L->next;
    }
};
// @lc code=end
