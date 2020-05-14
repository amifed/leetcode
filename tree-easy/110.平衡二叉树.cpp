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
private:
  unordered_map<TreeNode *, int> memo;

public:
  int depth(TreeNode *root) {
    if (root == NULL)
      return 0;
    int ldepth, rdepth;
    if (memo.find(root->left) == memo.end())
      memo.insert({root->left, depth(root->left)});
    ldepth = memo[root->left];
    if (memo.find(root->right) == memo.end())
      memo.insert({root->right, depth(root->right)});
    rdepth = memo[root->right];
    return max(ldepth, rdepth) + 1;
  }
  // 自顶向下，记忆化
  bool isBalanced(TreeNode *root) {
    if (root == NULL)
      return true;
    int ldepth, rdepth;
    if (memo.find(root->left) == memo.end())
      memo.insert({root->left, depth(root->left)});
    ldepth = memo[root->left];
    if (memo.find(root->right) == memo.end())
      memo.insert({root->right, depth(root->right)});
    rdepth = memo[root->right];
    return isBalanced(root->left) && isBalanced(root->right) &&
           abs(ldepth - rdepth) < 2;
  }
};
// @lc code=end
