/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.57%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    57.4K
 * Total Submissions: 88.5K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
#include <stdlib.h>

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
  if (preorderSize <= 0 || inorderSize <= 0) return NULL;
  struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  int index = 0;
  while (*(inorder + index) != *preorder && index < inorderSize) index++;
  root->val = *preorder;
  root->left = buildTree(preorder + 1, index, inorder, index);
  root->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, inorderSize - index - 1);
  return root;
}

// @lc code=end