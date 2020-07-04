/*
 * @lc app=leetcode.cn id=589 lang=c
 *
 * [589] N叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (72.62%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 30.8K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的前序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其前序遍历: [1,3,5,6,2,4]。
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */
#include <Node.h>
#include <stdlib.h>
// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
#define MAX_SIZE 10240
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 迭代
int* preorder(struct Node* root, int* returnSize) {
  int i, top = -1, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  struct Node *p, **stack = (char**)malloc(sizeof(struct Node*) * MAX_SIZE);
  *returnSize = 0;
  if (root == NULL) return result;
  stack[++top] = root;
  while (top != -1) {
    p = stack[top--];
    result[(*returnSize)++] = p->val;
    // 从最后一个孩子开始入栈
    for (i = p->numChildren - 1; i >= 0; i--)
      stack[++top] = p->children[i];
  }
  free(stack);
  return result;
}
//  递归
// void visit(struct Node* root, int* result, int* returnSize) {
//   if (root)
//     for (int i = 0; i < root->numChildren; i++) {
//       result[(*returnSize)++] = root->children[i]->val;
//       visit(root->children[i], result, returnSize);
//     }
// }
// int* preorder(struct Node* root, int* returnSize) {
//   int i, *result = (int*)calloc(MAX_SIZE, sizeof(int));
//   *returnSize = 0;
//   if (root == NULL) return result;
//   result[(*returnSize)++] = root->val;
//   visit(root, result, returnSize);
//   return result;
// }
// @lc code=end
