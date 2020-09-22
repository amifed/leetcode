/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
struct Status {
    int a, b, c;
};
const int INF = 0x3f3f3f3f;
class Solution {
public:
    Status dfs(TreeNode* t) {
        if (!t) return {INF, 0, 0};
        auto l = dfs(t->left);
        auto r = dfs(t->right);
        int a = l.c + r.c + 1;//root 必须放置摄像头的情况下，覆盖整棵树需要的摄像头数目
        int b = min(a, min(l.a + r.b, l.b + r.a));//覆盖整棵树需要的摄像头数目，无论 root 是否放置摄像头
        int c = min(a, l.b + r.b);//覆盖两棵子树需要的摄像头数目，无论节点 root 本身是否被监控到
        return {a, b, c};
    }
    int minCameraCover(TreeNode *root) {
        return dfs(root).b;
    }
};
// @lc code=end
