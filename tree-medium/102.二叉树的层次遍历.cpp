/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (root == NULL)
      return ret;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty()) {
      int levelSize = Q.size();
      ret.push_back(vector<int>());
      for (int i = 0; i < levelSize; i++) {
        auto p = Q.front();
        Q.pop();
        ret.back().push_back(p->val);
        if (p->left)
          Q.push(p->left);
        if (p->right)
          Q.push(p->right);
      }
    }
    return ret;
  }
};
// @lc code=end
