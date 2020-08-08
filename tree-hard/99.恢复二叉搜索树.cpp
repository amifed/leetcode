/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *pre = nullptr, *x = nullptr, *y = nullptr;
    void inorder(TreeNode *root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (pre != nullptr && pre->val > root->val) {
            if (x == nullptr) {
                x = pre;
            }
            y = root;
        }
        pre = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode *root) {
        inorder(root);
        swap(x->val, y->val);
    }
};
// @lc code=end
