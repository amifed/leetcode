/*
 * @lc app=leetcode.cn id=590 lang=c
 *
 * [590] N叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (72.65%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    19.4K
 * Total Submissions: 26.7K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
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
/**
 * 递归
 **/
// void visit(struct Node* root, int* result, int* returnSize) {
//   if (root)
//     for (int i = 0; i < root->numChildren; i++) {
//       visit(root->children[i], result, returnSize);
//       result[(*returnSize)++] = root->children[i]->val;
//     }
// }
// int* postorder(struct Node* root, int* returnSize) {
//   int i, *result = (int*)calloc(MAX_SIZE, sizeof(int));
//   *returnSize = 0;
//   if (root == NULL) return result;
//   visit(root, result, returnSize);
//   result[(*returnSize)++] = root->val;
//   return result;
// }
/**
 * 迭代
 **/
void reverse(int* array, int arraySize) {
  for (int i = 0, j = arraySize - 1; i <= j; i++, j--) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
int* postorder(struct Node* root, int* returnSize) {
  int i, top = -1, *result = (int*)calloc(MAX_SIZE, sizeof(int));
  struct Node* p;
  struct Node** stack = (char**)malloc(sizeof(struct Node*) * MAX_SIZE);
  *returnSize = 0;
  if (root == NULL) return result;
  stack[++top] = root;
  while (top != -1) {
    p = stack[top--];
    if (p) result[(*returnSize)++] = p->val;
    // 从最后一个孩子开始入栈
    for (i = 0; i < p->numChildren; i++) {
      stack[++top] = p->children[i];
    }
  }
  reverse(result, *returnSize);
  free(stack);
  return result;
}
// @lc code=end
// [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
