/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.52%)
 * Likes:    3369
 * Dislikes: 0
 * Total Accepted:    407.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include<stdlib.h>
// @lc code=start

/**
 * 动态规划求解
 **/
int lengthOfLongestSubstring(char *s)
{
    if (s == NULL || strlen(s) < 1)
        return 0;
    if (strlen(s) == 1)
        return 1;
    int i, j, max, dp[31000];
    dp[0] = 1;
    if (s[0] == s[1])
        dp[1] = 1;
    else
        dp[1] = 2;
    max = dp[1];
    for (i = 2; s[i] != '\0'; i++)
    {
        for (j = i - 1; j > i - 1 - dp[i - 1] && s[i] != s[j]; j--)
            ;
        if (j == i - 1 - dp[i - 1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = i - j;
        if (dp[i] > max)
            max = dp[i];
    }
    return max;
}

// @lc code=end
