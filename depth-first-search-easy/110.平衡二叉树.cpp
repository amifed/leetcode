/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include "../TreeNode.cpp"
#include <bits/stdc++.h>
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
  //递归，自底向上
  bool isBalancedTreeHelper(TreeNode *root, int &height) {
    if (root == NULL) {
      height = -1;
      return true;
    }
    int left, right;
    if (isBalancedTreeHelper(root->left, left) &&
        isBalancedTreeHelper(root->right, right) && abs(left - right) < 2) {
      height = max(left, right) + 1;
      return true;
    }
    return false;
  }
  bool isBalanced(TreeNode *root) {
    int height;
    return isBalancedTreeHelper(root, height);
  }
};
// @lc code=end
