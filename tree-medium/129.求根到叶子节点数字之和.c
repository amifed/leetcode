/*
 * @lc app=leetcode.cn id=129 lang=c
 *
 * [129] 求根到叶子节点数字之和
 */
#include <stdlib.h>

#include "./TreeNode.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int perorder(struct TreeNode* root, int num) {
  if (!root) return 0;
  int _num = num * 10 + root->val;
  if (root->left == NULL && root->right == NULL) return _num;
  return perorder(root->left, _num) + perorder(root->right, _num);
}
int sumNumbers(struct TreeNode* root) {
  return perorder(root, 0);
}

// @lc code=end
