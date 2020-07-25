/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return vector<vector<int>>();
        bool order = true;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ret;
        while (!q.empty()) {
            int n = q.size();
            deque<int> dq;
            for (int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                if (order)
                    dq.push_back(p->val);
                else
                    dq.push_front(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            ret.push_back(vector<int>(dq.begin(), dq.end()));
            order = !order;
        }
        return ret;
    }
};
// @lc code=end
