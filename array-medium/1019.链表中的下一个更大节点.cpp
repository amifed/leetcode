/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode *head) {
        stack<pair<int, int>> st;
        vector<int> ret;
        int cnt = 0;
        while (head) {
            ret.push_back(0);
            while (!st.empty() && st.top().second < head->val) {
                ret[st.top().first] = head->val;
                st.pop();
            }
            st.push({cnt, head->val});
            cnt++;
            head = head->next;
        }
        return ret;
    }
};
// @lc code=end
