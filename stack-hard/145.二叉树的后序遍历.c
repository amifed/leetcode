/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.74%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    67.8K
 * Total Submissions: 95.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <stdlib.h>

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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;
  int* result = (int*)malloc(MAX_SIZE * sizeof(int));
  struct TreeNode** stack = (struct TreeNode**)malloc(MAX_SIZE * sizeof(struct TreeNode*));
  struct TreeNode *p = root, *r;
  int top = -1;
  while (p || top != -1) {
    if (p) {
      stack[++top] = p;
      p = p->left;
    } else {
      p = stack[top];
      if (p->right && p->right != r) {
        p = p->right;
        stack[++top] = p;
        p = p->left;
      } else {
        p = stack[top--];
        result[(*returnSize)++] = p->val;
        r = p;
        p = NULL;
      }
    }
  }
  return result;
}

// @lc code=end
