/*
 * @lc app=leetcode.cn id=279 lang=c
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.16%)
 * Likes:    364
 * Dislikes: 0
 * Total Accepted:    47.9K
 * Total Submissions: 86.4K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
#include <limits.h>
// @lc code=start
// 找零钱问题相同
// 法一：暴力递归
int Min(int a, int b) { return a < b ? a : b; }
// int minNumSquares(int *sqrts, int sqrtsSize, int num) {
//   int i, sub, res = INT_MAX;
//   if (num < 0) return -1;
//   if (num == 0) return 0;
//   for (i = 0; i < sqrtsSize; i++) {
//     sub = minNumSquares(sqrts, sqrtsSize, num - sqrts[i]);
//     if (sub == -1) continue;
//     res = Min(res, sub + 1);
//   }
//   return res;
// }
// int numSquares(int n) {
//   int i, t, sqrtsSize = (int)sqrt(n);
//   int sqrts[sqrtsSize];
//   for (i = 0; i < sqrtsSize; i++) {
//     sqrts[i] = (i + 1) * (i + 1);
//   }
//   return minNumSquares(sqrts, sqrtsSize, n);
// }
// 法二：memo
// int minNumSquares(int *sqrts, int sqrtsSize, int num, int *memo) {
//   int i, sub, res = INT_MAX;
//   if (num < 0) return -1;
//   if (num == 0) return 0;
//   if (memo[num] != 0) return memo[num];
//   for (i = 0; i < sqrtsSize; i++) {
//     sub = minNumSquares(sqrts, sqrtsSize, num - sqrts[i], memo);
//     if (sub == -1) continue;
//     res = Min(res, sub + 1);
//   }
//   memo[num] = res;
//   return res;
// }
// int numSquares(int n) {
//   int i, t, sqrtsSize = (int)sqrt(n);
//   int sqrts[sqrtsSize], *memo = (int *)calloc(n + 1, sizeof(int));
//   for (i = 0; i < sqrtsSize; i++) {
//     sqrts[i] = (i + 1) * (i + 1);
//   }
//   return minNumSquares(sqrts, sqrtsSize, n, memo);
// }
// 法三：动态规划
int numSquares(int n) {
  int i, j, sqrtsSize = (int)sqrt(n);
  int sqrts[sqrtsSize], *dp = (int *)malloc((n + 1) * sizeof(int));
  for (i = 0; i <= n; i++) dp[i] = n + 1;
  for (i = 0; i < sqrtsSize; i++) {
    sqrts[i] = (i + 1) * (i + 1);
  }
  dp[0] = 0;
  for (i = 0; i <= n; i++) {
    for (j = 0; j < sqrtsSize; j++) {
      if (i < sqrts[j]) continue;
      dp[i] = Min(dp[i - sqrts[j]] + 1, dp[i]);
    }
  }
  return dp[n];
}

// @lc code=end
