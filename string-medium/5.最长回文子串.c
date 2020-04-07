/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.13%)
 * Likes:    1966
 * Dislikes: 0
 * Total Accepted:    226.1K
 * Total Submissions: 773.4K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start

//中心扩展法
int expandAroundCenter(char *s, int left, int right) {
  int len = strlen(s);
  while (left >= 0 && right < len && s[left] == s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
}
char *longestPalindrome(char *s) {
  if (s == NULL || strlen(s) < 1)
    return "";
  if (strlen(s) == 1)
    return s;
  int i, max = -1, left, right, start, end, odd, even;
  for (i = 0; s[i] != '\0'; i++) {
    odd = expandAroundCenter(s, i, i);       //奇
    even = expandAroundCenter(s, i, i + 1);  //偶
    if (odd > even) {
      left = i - (odd / 2);
      right = i + (odd / 2);
    } else {
      left = i + 1 - (even / 2);
      right = i + (even / 2);
    }
    if (max < right - left) {
      max = right - left;
      start = left;
      end = right;
    }
  }
  *(s + end + 1) = '\0';
  return s + start;
}

// @lc code=end
