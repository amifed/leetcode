/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define it insert
#define pob pop_back
#define pub push_back
#define all(v) (v).begin(), (v).end()
using LL = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using PII = pair<int, int>;
using PIL = pair<int, LL>;
using PLL = pair<LL, LL>;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
class Solution {
public:
    VVI memo;
    VI v;
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        v = VI(nums.begin(), nums.end());
        v.it(v.begin(), 1);
        v.pub(1);
        memo.resize(n + 2, VI(n + 2, -1));
        return solve(0, n + 1);
    }
    int solve(int l, int r) {
        if (l >= r - 1) {
            return 0;
        }
    }
};
// @lc code=end
