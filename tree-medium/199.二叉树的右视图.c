/*
 * @lc app=leetcode.cn id=199 lang=c
 *
 * [199] 二叉树的右视图
 * 
 * Testcase Example:  [1,2,3,4]
 * Testcase Example:  [1,2,null,3,4]
 * Testcase Example:  [1,2,null,3,null,4]
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
#define MAX_SIZE 128
void dfs(struct TreeNode* root, int depth, int* result, int* returnSize) {
  if (root) {
    result[depth] = root->val;
    if (depth >= *returnSize) *returnSize = depth + 1;
    dfs(root->left, depth + 1, result, returnSize);
    dfs(root->right, depth + 1, result, returnSize);
  }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
  *returnSize = 0;
  if (root == NULL) return NULL;
  int* result = (int*)malloc(MAX_SIZE * sizeof(int));
  dfs(root, 0, result, returnSize);
  return result;
}

// @lc code=end
