/*
 * @lc app=leetcode.cn id=264 lang=c
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (50.82%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 40.6K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start


int Min(int a, int b, int c) { return a > b ? (b > c ? c : b) : (a > c ? c : a); }
int nthUglyNumber(int n)
{
    int i, dp[n];
    dp[0] = 1;
    int ugly, i2 = 0, i3 = 0, i5 = 0;
    for (i = 1; i < n; i++)
    {
        ugly = Min(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
        dp[i] = ugly;
        if (ugly == dp[i2] * 2)
            i2++;
        if (ugly == dp[i3] * 3)
            i3++;
        if (ugly == dp[i5] * 5)
            i5++;
    }
    return dp[n - 1];
}


// @lc code=end

