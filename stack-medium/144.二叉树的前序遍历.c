/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (64.80%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    91.3K
 * Total Submissions: 140.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include "TreeNode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_SIZE 512
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;
  int* result = (int*)malloc(MAX_SIZE * sizeof(int));
  struct TreeNode** stack = (struct TreeNode**)malloc(MAX_SIZE * sizeof(struct TreeNode*));
  struct TreeNode* p = root;
  int top = -1;
  while (p || top != -1) {
    while (p) {
      result[(*returnSize)++] = p->val;
      stack[++top] = p;
      p = p->left;
    }
    if (top != -1) {
      p = stack[top--];
      p = p->right;
    }
  }
  free(stack);
  return result;
}

// @lc code=end
