/*
 * @lc app=leetcode.cn id=91 lang=c
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.29%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 177.9K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */
#include <stdlib.h>
#include <string.h>
// @lc code=start

int numDecodings(char *s) {
  if (s == NULL || strlen(s) < 1 || *s == '0')
    return 0;
  int i, pre, cur, temp;
  for (pre = cur = 1, i = 1; s[i] != '\0'; i++) {
    temp = cur;
    if (s[i] == '0')
      if (s[i - 1] == '1' || s[i - 1] == '2')
        cur = pre;
      else
        return 0;
    else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] > '0' && s[i] < '7'))
      cur += pre;
    pre = temp;
  }
  return cur;
}

// @lc code=end
