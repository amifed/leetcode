/*
 * @lc app=leetcode.cn id=198 lang=c
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (44.03%)
 * Likes:    706
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 214.1K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 */

// @lc code=start

//dp[0]=nums[0] dp[1]=nums[1]，
//i > 1时，dp[i] = nums[i] + MAX(dp[i-2] ~ dp[0])
//最高金额 = MAX(dp);
int Max(int a, int b) { return a > b ? a : b; }
int rob(int* nums, int numsSize) {
  if (numsSize == 0)
    return 0;
  if (numsSize == 1)
    return nums[0];
  if (numsSize == 2)
    return Max(nums[0], nums[1]);
  int i, j, k, max, *dp = (int*)malloc(sizeof(int) * numsSize);
  dp[0] = nums[0];
  dp[1] = nums[1];
  dp[2] = nums[0] + nums[2];
  max = Max(Max(dp[0], dp[1]), dp[2]);
  for (i = 3; i < numsSize; i++) {
    dp[i] = nums[i] + Max(dp[i - 2], dp[i - 3]);
    if (max < dp[i])
      max = dp[i];
  }
  return max;
}

// @lc code=end
