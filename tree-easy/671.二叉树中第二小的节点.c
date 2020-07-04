/*
 * @lc app=leetcode.cn id=671 lang=c
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.89%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 20K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
 * 
 * 
 */
#include <limits.h>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Min(int a, int b) { return a > b ? b : a; }
int order(struct TreeNode *root, int min)
{
    if (!root)
        return -1;
    if (root->val > min)
        return root->val;
    int l = order(root->left, min);
    int r = order(root->right, min);
    if (l == -1 && r == -1)
        return -1;
    else if (l == -1)
        return r;
    else if (r == -1)
        return l;
    else
        return Min(l, r);
}
int findSecondMinimumValue(struct TreeNode *root)
{
    return order(root, root->val);
}

// @lc code=end
// Testcase Example:  '[2,2,5,null,null,5,7]'
// Testcase Example:  '[2,2,5,null,null,6,7]'
// Testcase Example:  '[2,5,3]'
// Testcase Example:  '[2,2,5,null,null,5,5]'
// Testcase Example:  '[2,3,5,3,3,6,7]'
// Testcase Example:  '[2,2,2,3,4,5,6]'
// Testcase Example:  '[2,6,3,7,8,4,5]'