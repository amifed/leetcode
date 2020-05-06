/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.back() + 1, 0);
    auto day = days.begin();
    for (int i = 1; i < dp.size(); i++) {
      if (i != *day)
        dp[i] = dp[i - 1];
      else {
        dp[i] =
            min(min(dp[max(0, i - 1)] + costs[0], dp[max(0, i - 7)] + costs[1]),
                dp[max(0, i - 30)] + costs[2]);
        day++;
      }
    }
    return dp.back();
  }
};
// @lc code=end
int main() {
  vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
  Solution().mincostTickets(days, costs);
  return 0;
}