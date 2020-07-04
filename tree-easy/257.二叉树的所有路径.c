/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (63.02%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    30.4K
 * Total Submissions: 48.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void copy(char *path, int val, int *j)
{
    int i = 0, *nums = (int *)malloc(sizeof(int) * 10);
    if (val < 0)
    {
        path[(*j)++] = '-';
        val = -val;
    }
    while (val != 0)
    {
        nums[i++] = val % 10;
        val /= 10;
    }
    while (i > 0)
    {
        path[(*j)++] = nums[--i] + '0';
    }
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    if (!root)
        return NULL;
    int top = -1, i, j;
    struct TreeNode *p = root, *r = NULL;
    struct TreeNode **stack = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1000);
    char **path = (char **)malloc(sizeof(char *) * 2000);
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
                p = stack[top--];
                if (p->left == NULL && p->right == NULL)
                {
                    path[(*returnSize)] = (char *)malloc(sizeof(char) * 1000);
                    for (i = 0, j = 0; i <= top; i++)
                    {
                        copy(path[(*returnSize)], stack[i]->val, &j);
                        path[(*returnSize)][j++] = '-';
                        path[(*returnSize)][j++] = '>';
                    }
                    copy(path[(*returnSize)], stack[i]->val, &j);
                    path[(*returnSize)][j] = '\0';
                    (*returnSize)++;
                }
                r = p;
                p = NULL;
            }
        }
    }
    return path;
}


// @lc code=end

