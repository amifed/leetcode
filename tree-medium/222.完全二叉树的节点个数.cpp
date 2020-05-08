/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
  //   int countNodes(TreeNode* root) {
  //     return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
  //   }
  int depth(TreeNode* root) {
    int depth = 0;
    while (root) root = root->left, depth++;
    return depth;
  }
  int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    int ldepth = depth(root->left), rdepth = depth(root->right);
    if (ldepth == rdepth)
      return countNodes(root->right) + (1 << ldepth);
    else
      return countNodes(root->left) + (1 << rdepth);
  }
};
// @lc code=end
