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
  void kthNode(TreeNode* root, vector<int>& nodes) {
    if (root) {
      kthNode(root->left, nodes);
      nodes.push_back(root->val);
      kthNode(root->right, nodes);
    }
  }
  int kthSmallest(TreeNode* root, int k) {
    vector<int> nodes;
    kthNode(root, nodes);
    return nodes[k - 1];
  }
};
// @lc code=end
