/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include "./TreeNode.cpp"
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
  long predt = LONG_MIN;
  bool isValidBST(TreeNode* root) {
    if (root == NULL)
      return true;
    else {
      bool left = isValidBST(root->left);
      if (!left || predt >= root->val) return false;
      predt = root->val;
      return isValidBST(root->right);
    }
  }
};
// @lc code=end
