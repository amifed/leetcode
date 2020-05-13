/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
  // from top to down
  // int minimumTotal(vector<vector<int>> &triangle) {
  //   int min_path = INT_MAX;
  //   vector<vector<int>> dp(triangle.begin(), triangle.end());
  //   for (int i = 1; i < triangle.size(); i++) {
  //     for (int j = 0; j < triangle[i].size(); j++) {
  //       if (j == 0)
  //         dp[i][j] = dp[i - 1][j];
  //       else if (j == i)
  //         dp[i][j] = dp[i - 1][j - 1];
  //       else
  //         dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
  //       dp[i][j] += triangle[i][j];
  //     }
  //   }
  //   for (int i = 0; i < dp.back().size(); i++) {
  //     min_path = min(min_path, dp.back()[i]);
  //   }
  //   return min_path;
  // }
  // from down to top
  int minimumTotal(vector<vector<int>> &triangle) {
    int min_path = INT_MAX;
    vector<vector<int>> dp(triangle.begin(), triangle.end());
    for (int i = triangle.size() - 2; i > -1; i--) {
      for (int j = triangle[i].size() - 1; j > -1; j--)
        dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
    }
    return dp[0][0];
  }
};
// @lc code=end
int main() {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << Solution().minimumTotal(triangle) << endl;
  return 0;
}