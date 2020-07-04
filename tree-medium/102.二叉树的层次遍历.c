/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.30%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 159.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
#include <TreeNode.h>
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
#define MAX_SIZE 1024
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
  // last 用来指向每层的最后一个结点
  *returnSize = 0;
  int front = 0, rear = 0, last = 0;
  struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_SIZE), *p;
  *returnColumnSizes = (int *)calloc(MAX_SIZE, sizeof(int));
  int **result = (int **)malloc(sizeof(int *) * MAX_SIZE);
  if (root == NULL) return result;
  queue[front++] = root;
  result[(*returnSize)] = (int *)calloc(front - rear, sizeof(int));
  while (front != rear) {
    p = queue[rear++];
    result[*returnSize][(*returnColumnSizes)[*returnSize]++] = p->val;
    if (p->left != NULL) queue[front++] = p->left;
    if (p->right != NULL) queue[front++] = p->right;
    if (rear - 1 == last) {
      result[++(*returnSize)] = (int *)calloc(front - rear, sizeof(int));
      last = front - 1;
    }
  }
  return result;
}

// @lc code=end
