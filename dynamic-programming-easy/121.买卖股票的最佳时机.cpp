/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        if (prices.size() == 0)
            return ret;
        int minn = prices[0];
        for (auto price : prices) {
            ret = max(ret, price - minn);
            minn = min(minn, price);
        }
        return ret;
    }
};
// @lc code=end