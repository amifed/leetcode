/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int dfs(TreeNode *root, int sum) {
        if (!root)
            return 0;
        int tmp = sum * 10 + root->val;
        if (!root->left && !root->right)
            return tmp;
        return dfs(root->left, tmp) + dfs(root->right, tmp);
    }
    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
};
// @lc code=end
