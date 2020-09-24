/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define it insert
#define pob pop_back
#define pub push_back
#define emb emplace_back
#define all(v) (v).begin(), (v).end()
#define mkp(a, b) make_pair(a, b)
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 7;

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
public:
    int count, maxCount;
    TreeNode* pre = NULL;
    vector<int> ans;
    void inorder(TreeNode* t) {
        if (!t) return;
        inorder(t->left);
        if (!pre) count = 1;
        else if (pre->val == t->val) count++;
        else count = 1;
        if (count == maxCount) ans.push_back(t->val);
        else if (count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(t->val);
        }
        pre = t;
        inorder(t->right);
    }
    vector<int> findMode(TreeNode* root) {
        count = maxCount = 0;
        pre = NULL;
        inorder(root);
        return ans;
    }
};
// @lc code=end

