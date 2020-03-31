/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (61.30%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 159.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return 0;
    }
    // last 用来指向每层的最后一个结点
    int front = 0, rear = 0, last = 0, columnSizes = 0;
    struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode) * 1000);
    int **result = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    struct TreeNode *p = NULL;
    *returnSize = 0;
    queue[front++] = root;
    result[(*returnSize)] = (int *)malloc(sizeof(int) * (front - rear));
    while (front != rear)
    {
        p = queue[rear++];
        result[(*returnSize)][columnSizes] = p->val;
        columnSizes++;
        if (p->left != NULL)
        {
            queue[front++] = p->left;
        }
        if (p->right != NULL)
        {
            queue[front++] = p->right;
        }
        if (rear - 1 == last)
        {
            (*returnColumnSizes)[(*returnSize)] = columnSizes;
            (*returnSize)++;
            result[(*returnSize)] = (int *)malloc(sizeof(int) * (columnSizes * 2));
            last = front - 1;
            columnSizes = 0;
        }
    }
    return result;
}


// @lc code=end

