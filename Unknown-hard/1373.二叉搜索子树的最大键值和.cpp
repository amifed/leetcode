/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Ret {
    bool valid;
    int sum, min, max;
    Ret(bool v = true, int s = 0, int min = INT_MIN, int max = INT_MAX) : valid(v), sum(s), min(min), max(max) {}
};
class Solution {
public:
    int ret = 0;
    Ret dfs(TreeNode *root) {
        if (!root) {
            return Ret();
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (!left.valid || !right.valid || left.max >= root->val || right.min <= root->val)
            return Ret(false);
        int sum = left.sum + right.sum + root->val;
        ret = max(ret, sum);
        return Ret(true, sum, min(left.min, root->val), max(right.max, root->val));
    }
    int maxSumBST(TreeNode *root) {
        dfs(root);
        return ret;
    }
};
// @lc code=end
TreeNode *inputTree()

{

    int n, count = 0;

    char item[100];

    cin >> n;

    if (n == 0)

        return NULL;

    cin >> item;

    TreeNode *root = new TreeNode(atoi(item));

    count++;

    queue<TreeNode *> nodeQueue;

    nodeQueue.push(root);

    while (count < n)

    {

        TreeNode *node = nodeQueue.front();

        nodeQueue.pop();

        cin >> item;

        count++;

        if (strcmp(item, "null") != 0)

        {

            int leftNumber = atoi(item);

            node->left = new TreeNode(leftNumber);

            nodeQueue.push(node->left);
        }

        if (count == n)

            break;

        cin >> item;

        count++;

        if (strcmp(item, "null") != 0)

        {

            int rightNumber = atoi(item);

            node->right = new TreeNode(rightNumber);

            nodeQueue.push(node->right);
        }
    }

    return root;
}

int main()

{

    TreeNode *root;

    root = inputTree();

    int res = Solution().maxSumBST(root);

    cout << res;
}