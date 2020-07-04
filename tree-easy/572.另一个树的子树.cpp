/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */
#include <bits/stdc++.h>

#include <../TreeNode.cpp>
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
  bool isSameTree(TreeNode* s, TreeNode* t) {
    if (s == NULL && t == NULL)
      return true;
    else if (s == NULL || t == NULL)
      return false;
    if (s->val == t->val)
      return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    return false;
  }
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == NULL)
      return false;
    else if (s->val == t->val && isSameTree(s, t))
      return true;
    else
      return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};
// @lc code=end
// [3,4,5,1,2]\n[4,1,2]
// [1,1]\n[1]
// [3,4,5,1,null,2]\n[3,1,2]