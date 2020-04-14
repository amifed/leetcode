/*
 * @lc app=leetcode.cn id=113 lang=c
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.97%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    41.2K
 * Total Submissions: 69.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
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
#define MAX_SIZE 700
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  if (root == NULL) return NULL;
  *returnColumnSizes = (int*)malloc(sizeof(int) * MAX_SIZE);
  int** result = (int**)malloc(sizeof(int) * MAX_SIZE);
  struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode) * MAX_SIZE);
  struct TreeNode *r, *p = root;
  int i, top = -1, cnt = 0;
  while (p || top != -1) {
    if (p) {
      stack[++top] = p;
      cnt += p->val;  //入栈计数
      p = p->left;
    } else {
      p = stack[top];
      if (p->right && p->right != r) {
        p = p->right;
        stack[++top] = p;
        cnt += p->val;  //入栈计数
        p = p->left;
      } else {
        p = stack[top--];
        if (p->left == NULL && p->right == NULL && cnt == sum) {  //叶结点且路径和等于sum
          result[*returnSize] = (int*)malloc(sizeof(int) * (top + 2));
          for (i = 0; i <= top + 1; i++) {
            result[*returnSize][i] = stack[i]->val;
          }
          (*returnColumnSizes)[(*returnSize)++] = top + 2;
        }
        cnt -= p->val;  //出栈减数
        r = p;
        p = NULL;
      }
    }
  }
  return result;
}

// @lc code=end
