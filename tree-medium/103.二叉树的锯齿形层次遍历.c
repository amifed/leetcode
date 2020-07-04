/*
 * @lc app=leetcode.cn id=103 lang=c
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.02%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    41.8K
 * Total Submissions: 77.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 2000
void reverse(int* arr, int arrSize) {
  int i, j, t;
  for (i = 0, j = arrSize - 1; i < j; i++, j--) {
    t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
  }
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  if (!root) return root;
  int front = 0, rear = 0, last = 0, columnSizes = 0;
  struct TreeNode *p, **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * MAX_SIZE);
  int** result = (int**)calloc(MAX_SIZE, sizeof(int));
  *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
  queue[front++] = root;
  result[(*returnSize)] = (int*)calloc(1, sizeof(int));
  while (front != rear) {
    p = queue[rear++];
    result[(*returnSize)][columnSizes] = p->val;
    columnSizes++;
    if (p->left) queue[front++] = p->left;
    if (p->right) queue[front++] = p->right;
    if (rear - 1 == last) {
      (*returnColumnSizes)[(*returnSize)] = columnSizes;
      if (*returnSize % 2 == 1) reverse(result[(*returnSize)], (*returnColumnSizes)[(*returnSize)]);
      (*returnSize)++;
      result[(*returnSize)] = (int*)calloc(columnSizes * 2, sizeof(int));
      last = front - 1;
      columnSizes = 0;
    }
  }
  free(queue);
  return result;
}

// @lc code=end
