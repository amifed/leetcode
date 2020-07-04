/*
 * @lc app=leetcode.cn id=377 lang=c
 *
 * [377] 组合总和 Ⅳ
 */
#include <limits.h>
// @lc code=start
// 超时
// int comp(void const* a, void const* b) {
//   return *(int*)a - *(int*)b;
// }
// int backtrack(int* nums, int numsSize, int target, int* result, int* memo) {
//   if (memo[target] != 0) return memo[target];
//   if (target == 0) return 1;
//   int res = 0;
//   for (int i = 0; i < numsSize; i++) {
//     if (target - nums[i] < 0) break;
//     res += backtrack(nums, numsSize, target - nums[i], result, memo);
//   }
//   memo[target] = res;
//   return res;
// }
// int combinationSum4(int* nums, int numsSize, int target) {
//   int result = 0;
//   qsort(nums, numsSize, sizeof(int), comp);
//   int* memo = (int*)calloc(target + 1, sizeof(int));
//   int res = backtrack(nums, numsSize, target, &result, memo);
//   for (int i = 0; i <= target; i++)
//     printf("%d ", memo[i]);
//   return res;
// }
int combinationSum4(int* nums, int numsSize, int target) {
  int i, j;
  int* dp = (int*)calloc(target + 1, sizeof(int));
  dp[0] = 1;
  for (i = 1; i <= target; i++) {
    for (j = 0; j < numsSize; j++) {
      if (i - nums[j] < 0) continue;
      if (dp[i] > INT_MAX - dp[i - nums[j]]) {  //防止超int范围
        dp[i] = 0;                              //不要返回0 因为i可能不到target 但是有组合和为target
        break;
      }
      dp[i] += dp[i - nums[j]];
    }
  }
  return dp[target];
}

// @lc code=end
// [3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]\n10
// [1,2,3]\n32
// 0 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 35890 66012 121415 223317 410744 755476 1389537 2555757 4700770 8646064 15902591 29249425 53798080 98950096 181997601
// [3,33,333]\n10000