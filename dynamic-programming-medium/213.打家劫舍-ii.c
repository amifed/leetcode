/*
 * @lc app=leetcode.cn id=213 lang=c
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (37.03%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 73.4K
 * Testcase Example:  '[2,3,2]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 */
#include <limits.h>
// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int rob(int* nums, int numsSize) {
  if (numsSize == 0)
    return 0;
  if (numsSize == 1)
    return nums[0];
  int i, j, n, res = INT_MIN, max, *dp = (int*)malloc(sizeof(int) * numsSize);
  for (i = 0; i < 2; i++) {
    for (j = i, n = 0, max = INT_MIN; n < numsSize - 1; j = (j + 1) % numsSize, n++) {
      if (n == 0 || n == 1)
        dp[n] = nums[j];
      else if (n == 2)
        dp[n] = dp[0] + nums[j];
      else
        dp[n] = nums[j] + Max(dp[n - 2], dp[n - 3]);
      if (max < dp[n])
        max = dp[n];
    }
    res = Max(res, max);
  }
  return res;
}

// @lc code=end
// [3,1,6,9,3,6,9,3,3]