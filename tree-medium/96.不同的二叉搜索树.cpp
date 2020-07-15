/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    unordered_map<int, int> memo;

public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (memo.count(n) > 0)
            return memo[n];
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += numTrees(i - 1) * numTrees(n - i);
        }
        return memo[n] = cnt;
    }
};
// @lc code=end
