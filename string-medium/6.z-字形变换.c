/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (47.27%)
 * Likes:    628
 * Dislikes: 0
 * Total Accepted:    114.6K
 * Total Submissions: 241.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start

char *convert(char *s, int numRows) {
  if (s == NULL || numRows < 2) return s;
  int i, j, k, n = 0, len = strlen(s), cycle = 2 * numRows - 2;
  char *res = (char *)calloc((len + 1), sizeof(char));
  for (i = 0; i < numRows; i++) {
    for (j = 0; j + i < len; j += cycle) {
      res[n++] = s[j + i];
      if (i != 0 && i != numRows - 1 && j + cycle - i < len)
        res[n++] = s[j + cycle - i];
    }
  }
  return res;
}

// @lc code=end
// "LEETCODEISHIRING"\n3
// "A"\n2