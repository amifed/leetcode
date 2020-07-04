/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
  private:
  stack<TreeNode*> st;

  public:
  BSTIterator(TreeNode* root) {
    while (root)
      st.push(root), root = root->left;
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* root = st.top();
    int ret = root->val;
    st.pop();
    root = root->right;
    while (root)
      st.push(root), root = root->left;
    return ret;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !st.empty();
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
