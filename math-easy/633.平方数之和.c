/*
 * @lc app=leetcode.cn id=633 lang=c
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (33.10%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 53.3K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */
#include <stdbool.h>
// @lc code=start

bool judgeSquareSum(int c) {
  int i, j, squareSum;
  for (i = 0, j = (int)sqrt(c); i <= j;) {
    squareSum = c - j * j;
    if (squareSum == i * i)
      return true;
    else if (squareSum < i * i)
      j--;
    else
      i++;
  }
  return false;
}

// @lc code=end
// 2147482647