/*
 * @lc app=leetcode.cn id=637 lang=c
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (63.74%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 24.4K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 
 * 
 * 注意：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
 * 
 * 
 */
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double *averageOfLevels(struct TreeNode *root, int *returnSize)
{
    int front = 0, rear = 0, columnSize = 0;
    double sum = 0;
    struct TreeNode *p = NULL, *r = NULL, **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1500);
    double *average = (double *)malloc(sizeof(double) * 1000);
    *returnSize = 0;
    queue[front++] = root;
    r = root;
    while (front != rear)
    {
        p = queue[rear++];
        columnSize++;
        sum += p->val;
        if (p->left != NULL)
            queue[front++] = p->left;
        if (p->right != NULL)
            queue[front++] = p->right;
        if (r == p)
        {
            average[(*returnSize)++] = sum / columnSize;
            r = queue[front - 1];
            sum = 0;
            columnSize = 0;
        }
    }
    return average;
}


// @lc code=end

