/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
private:
    int ret = 0;

public:
    pair<int, int> dfs(TreeNode *root) {
        if (!root)
            return {INT_MAX, INT_MIN};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int minVal = min(left.first, right.first);
        int maxVal = max(left.second, right.second);
        if (minVal != INT_MAX)
            ret = max(ret, abs(root->val - minVal));
        if (maxVal != INT_MIN)
            ret = max(ret, abs(root->val - maxVal));
        return {min(root->val, minVal), max(root->val, maxVal)};
    }
    int maxAncestorDiff(TreeNode *root) {
        dfs(root);
        return ret;
    }
};
// @lc code=end
