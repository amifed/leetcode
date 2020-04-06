/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.95%)
 * Likes:    1794
 * Dislikes: 0
 * Total Accepted:    196.5K
 * Total Submissions: 392.7K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include <limits.h>
// @lc code=start

int Max(int a, int b) { return a > b ? a : b; }
int maxSubArray(int *nums, int numsSize) {
  if (numsSize == 0) return INT_MIN;
  int i, max, dp[numsSize];
  for (dp[0] = nums[0], max = dp[0], i = 1; i < numsSize; i++) {
    dp[i] = dp[i - 1] <= 0 ? nums[i] : nums[i] + dp[i - 1];
    max = Max(max, dp[i]);
  }
  return max;
}

// @lc code=end
