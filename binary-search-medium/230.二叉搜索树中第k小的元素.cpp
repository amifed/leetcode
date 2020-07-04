/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
  public:
  int numsOfTree(TreeNode* root) {
    if (!root) return 0;
    return 1 + numsOfTree(root->left) + numsOfTree(root->right);
  }
  int kthSmallest(TreeNode* root, int k) {
    int cnt = numsOfTree(root->left);
    if (k <= cnt)
      return kthSmallest(root->left, k);
    else if (k > cnt + 1)
      return kthSmallest(root->right, k - cnt - 1);
    return root->val;
  }
};
// @lc code=end
