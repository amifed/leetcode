/*
 * @lc app=leetcode.cn id=152 lang=c
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.67%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    42.8K
 * Total Submissions: 113.6K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
#include <limits.h>
// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
// int maxProduct(int *nums, int numsSize)
// {
//     if (numsSize == 0)
//         return 0;
//     int i, j, mul, max = nums[0], dp[numsSize];
//     dp[0] = nums[0];
//     for (i = 1; i < numsSize; i++)
//     {
//         dp[i] = nums[i];
//         mul = nums[i];
//         for (j = i - 1; j >= 0; j--)
//         {
//             mul *= nums[j];
//             if (dp[i] < mul)
//                 dp[i] = mul;
//         }
//         if (dp[i] > max)
//             max = dp[i];
//     }
//     for (i = 0; i < numsSize; i++)
//         printf("%d ", dp[i]);
//     return max;
// }
int maxProduct(int *nums, int numsSize)
{
    int i, temp, max = INT_MIN, imax = 1, imin = 1;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            temp = imax;
            imax = imin;
            imin = temp;
        }
        imax = Max(imax * nums[i], nums[i]);
        imin = Min(imin * nums[i], nums[i]);
        max = Max(imax, max);
    }
    return max;
}

// @lc code=end
// [2,4,7,-2,9,-3,5,-2,0,3,8]