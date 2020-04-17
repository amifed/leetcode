/*
 * @lc app=leetcode.cn id=124 lang=c
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.71%)
 * Likes:    387
 * Dislikes: 0
 * Total Accepted:    33.7K
 * Total Submissions: 84.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */
#include <limits.h>
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
int Max(int a, int b) { return a > b ? a : b; }
int maxPath(struct TreeNode* root, int* max) {
  int left, right, pathMax;
  if (root == NULL) return 0;
  left = Max(maxPath(root->left, max), 0);
  right = Max(maxPath(root->right, max), 0);
  *max = Max(*max, root->val + left + right);
  return root->val + Max(left, right);  //两点之间
}
int maxPathSum(struct TreeNode* root) {
  int max = INT_MIN;
  maxPath(root, &max);
  return max;
}

// @lc code=end
// [1,2]
// [-3]
// [-2,-1]
// [2,-1,-2]