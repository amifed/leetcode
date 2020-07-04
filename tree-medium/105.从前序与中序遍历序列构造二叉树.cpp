/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <../TreeNode.cpp>
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
  TreeNode *buildTree(vector<int> preorder, vector<int> inorder) {
    if (preorder.size() <= 0 || inorder.size() <= 0) {
      return NULL;
    }
    int pos = 0;
    while (pos < inorder.size() && preorder[0] != inorder[pos])
      pos++;
    TreeNode *root = new TreeNode(preorder.front());
    root->left =
        buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + pos + 1),
                  vector<int>(inorder.begin(), inorder.begin() + pos));
    root->right =
        buildTree(vector<int>(preorder.begin() + pos + 1, preorder.end()),
                  vector<int>(inorder.begin() + pos + 1, inorder.end()));
    return root;
  }
};
// @lc code=end
