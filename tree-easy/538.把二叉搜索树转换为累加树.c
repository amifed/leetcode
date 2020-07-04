/*
 * @lc app=leetcode.cn id=538 lang=c
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (59.72%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 33.5K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void inOrder(struct TreeNode *root, int *sum)
{
    int num;
    if (root)
    {
        inOrder(root->right, sum);
        num = root->val;
        root->val += (*sum);
        (*sum) += num;
        inOrder(root->left, sum);
    }
}

struct TreeNode *convertBST(struct TreeNode *root)
{
    int sum = 0;
    inOrder(root, &sum);
    return root;
}


// @lc code=end

