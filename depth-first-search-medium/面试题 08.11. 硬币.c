/*
 * @lc app=leetcode.cn lang=c
 *
 * [面试题 08.11] 硬币
 */
#define MOD 1000000007
int waysToChange(int n) {
  int coins[] = {25, 10, 5, 1}, coinsSize = 4;
  int i, j, *dp = (int*)calloc(n + 1, sizeof(int));
  dp[0] = 1;
  for (i = 0; i < coinsSize; i++) {
    for (j = coins[i]; j <= n; j++) {
      dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
    }
  }
  return dp[n];
}