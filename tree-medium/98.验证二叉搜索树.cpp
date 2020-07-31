/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (!left || pre >= root->val) return false;
        pre = root->val;
        return isValidBST(root->right);
    }
};
// @lc code=end
