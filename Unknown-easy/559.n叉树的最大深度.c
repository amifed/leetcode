/*
 * @lc app=leetcode.cn id=559 lang=c
 *
 * [559] N叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (68.77%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    19.4K
 * Total Submissions: 28.2K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 我们应返回其最大深度，3。
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总不会超过 5000。
 * 
 */
#include <Node.h>
#include <limits.h>
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
int Max(int a, int b) { return a > b ? a : b; }
int* maxDepth(struct Node* root) {
  if (root == NULL) return 0;
  int max = 0;
  for (int i = 0; i < root->numChildren; i++) {
    max = Max(max, maxDepth(root->children[i]));
  }
  return max + 1;
}
// @lc code=end
