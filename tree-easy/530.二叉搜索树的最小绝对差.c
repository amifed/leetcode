/*
 * @lc app=leetcode.cn id=530 lang=c
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (55.92%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 20.5K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * 输出：
 * 1
 * 
 * 解释：
 * 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中至少有 2 个节点。
 * 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * 相同
 * 
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

void inOrder(struct TreeNode *root, int *pre, int *min)
{
    if (root)
    {
        inOrder(root->left, pre, min);
        if (abs(root->val - *pre) < *min)
            *min = abs(root->val - *pre);
        *pre = root->val;
        // printf("%d ", root->val);
        inOrder(root->right, pre, min);
    }
}

// 1 0 3 2 0 0 0
int getMinimumDifference(struct TreeNode *root)
{
    int pre = 0x7fffffff, min = 0x7fffffff;
    inOrder(root, &pre, &min);
    return min;
}


// @lc code=end

