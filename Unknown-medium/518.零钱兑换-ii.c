/*
 * @lc app=leetcode.cn id=518 lang=c
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
// 超时
// int comp(void const* a, void const* b) {
//   return *(int*)a - *(int*)b;
// }
// void backtrack(int amount, int* coins, int coinsSize, int start, int* cnt) {
//   if (amount == 0) {
//     (*cnt)++;
//     return;
//   }
//   for (int i = start; i < coinsSize; i++) {
//     if (amount - coins[i] < 0) break;
//     backtrack(amount - coins[i], coins, coinsSize, i, cnt);
//   }
// }
// int change(int amount, int* coins, int coinsSize) {
//   int cnt = 0;
//   qsort(coins, coinsSize, sizeof(int), comp);
//   backtrack(amount, coins, coinsSize, 0, &cnt);
//   return cnt;
// }
int change(int amount, int* coins, int coinsSize) {
  int i, j, *dp = (int*)calloc(amount + 1, sizeof(int));
  dp[0] = 1;
  for (i = 0; i < coinsSize; i++) {
    for (j = coins[i]; j <= amount; j++) {
      dp[j] += dp[j - coins[i]];  
    }
  }
  return dp[amount];
}

// @lc code=end
