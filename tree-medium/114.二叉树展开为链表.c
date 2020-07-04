/*
 * @lc app=leetcode.cn id=114 lang=c
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (68.11%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    35.9K
 * Total Submissions: 52.5K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */
#include <stdlib.h>

#include "TreeNode.h"
// @lc code=start
#define MAX_SIZE 512

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
  struct TreeNode** stack = (struct TreeNode**)malloc(MAX_SIZE * sizeof(struct TreeNode*));
  struct TreeNode *p = root, *r, *prev = NULL;  //前一个结点初始为空
  int top = -1;
  while (p || top != -1) {
    if (p) {
      stack[++top] = p;
      p = p->right;
    } else {
      p = stack[top];
      if (p->left && p->left != r) {
        p = p->left;
        stack[++top] = p;
        p = p->right;
      } else {
        p = stack[top--];

        p->left = NULL;   //左孩子结点置空
        p->right = prev;  //右孩子结点指向前一个结点
        prev = p;         //记录当前结点

        r = p;
        p = NULL;
      }
    }
  }
}

// @lc code=end
