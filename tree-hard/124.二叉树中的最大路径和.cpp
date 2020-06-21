/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode *node) {
        if (node == NULL)
            return 0;
        int left = max(maxGain(node->left), 0);
        int right = max(maxGain(node->right), 0);
        maxSum = max(maxSum, node->val + left + right);
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode *root) {
        maxGain(root);
        return maxSum;
    }
};
// @lc code=end
