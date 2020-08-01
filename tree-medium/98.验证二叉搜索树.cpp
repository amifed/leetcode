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
    /*     long long pre = LLONG_MIN;
    bool valid(TreeNode *root, long long lower, long long upper) {
        if (!root) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return valid(root->left, lower, root->val) && valid(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode *root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    } */

    /*     bool isValidBST(TreeNode *root) {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (!left || pre >= root->val) return false;
        pre = root->val;
        return isValidBST(root->right);
    } */
    long long upper = LLONG_MAX;
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        bool right = isValidBST(root->right);
        if (!right || upper <= root->val) return false;
        upper = root->val;
        return isValidBST(root->left);
    }
};
// @lc code=end
