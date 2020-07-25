/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    bool recursive(TreeNode *lnode, TreeNode *rnode) {
        if (!lnode && !rnode)
            return true;
        else if (!lnode || !rnode)
            return false;
        else if (lnode->val == rnode->val)
            return recursive(lnode->left, rnode->right) && recursive(lnode->right, rnode->left);
        else
            return false;
    }
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return recursive(root->left, root->right);
    }
};
// @lc code=end