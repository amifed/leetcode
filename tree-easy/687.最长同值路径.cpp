/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */
#include <bits/stdc++.h>

#include "../TreeNode.cpp"
using namespace std;
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
  int ret;
 public:
  int recursion(TreeNode* root) {
    if (root == NULL) return 0;
    int left = recursion(root->left);
    int right = recursion(root->right);
    left += root->left && root->left->val == root->val ? 1 : -left;
    right += root->right && root->right->val == root->val ? 1 : -right;
    ret = max(ret, left + right);
    return max(left, right);
  }
  int longestUnivaluePath(TreeNode* root) {
    ret = 0;
    recursion(root);
    return ret;
  }
};
// @lc code=end
