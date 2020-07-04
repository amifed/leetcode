/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.52%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 45.7K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
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

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
  if (inorderSize <= 0 || postorderSize <= 0) return NULL;
  struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  int index = 0;
  while (*(inorder + index) != *(postorder + postorderSize - 1) && index < inorderSize) index++;
  root->val = *(postorder + postorderSize - 1);
  root->left = buildTree(inorder, index, postorder, index);
  root->right = buildTree(inorder + index + 1, inorderSize - index - 1, postorder + index, postorderSize - index - 1);
  return root;
}

// @lc code=end
