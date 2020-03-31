/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (49.28%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    63.5K
 * Total Submissions: 128.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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


// 非递归后序遍历，遇到叶结点时，栈中的结点就是路径
bool hasPathSum(struct TreeNode *root, int sum)
{
    if (!root)
        return false;
    int i, top = -1, s;
    struct TreeNode *p = root;
    struct TreeNode *r = NULL;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1000);
    while (p || top != -1)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->left;
        }
        else
        {
            p = stack[top];
            if (p->right && p->right != r)
            {
                p = p->right;
                stack[++top] = p;
                p = p->left;
            }
            else
            {
                if (p->left == NULL && p->right == NULL)
                {
                    for (i = 0, s = 0; i <= top; i++)
                        s += stack[i]->val;
                    if (s == sum)
                        return true;
                }
                p = stack[top--];
                r = p;
                p = NULL;
            }
        }
    }
    return false;
}


// @lc code=end

