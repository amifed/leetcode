/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.84%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    62.9K
 * Total Submissions: 150.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 *
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回它的最小深度  2.
 *
 */
#include "TreeNode.h"
#include "stdlib.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Min(int a, int b) { return a < b ? a : b; }
int minDepth(struct TreeNode *root) {
  if (!root) return 0;
  int left = minDepth(root->left);
  int right = minDepth(root->right);
  return 1 + ((left == 0 || right == 0) ? left + right : Min(left, right));
}

// @lc code=end
