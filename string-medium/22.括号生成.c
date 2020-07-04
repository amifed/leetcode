/*
 * @lc app=leetcode.cn id=22 lang=c
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.71%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    92.2K
 * Total Submissions: 125K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

#include <string.h>
// @lc code=start
#define MAX_SIZE 1430
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void generate(char** result, int* returnSize, int left, int right, int n, int in, char* str) {
  if (left == n && right == n) {
    result[(*returnSize)] = calloc((2 * n + 1), sizeof(char));
    strcpy(result[(*returnSize)++], str);
    return;
  }

  if (left < n) {
    str[in] = '(';
    generate(result, returnSize, left + 1, right, n, in + 1, str);
  }
  if (right < left && right < n) {
    str[in] = ')';
    generate(result, returnSize, left, right + 1, n, in + 1, str);
  }
}
char** generateParenthesis(int n, int* returnSize) {
  char* str = (char*)calloc((2 * n + 1), sizeof(char));
  char** result = (char**)malloc(sizeof(char*) * MAX_SIZE);
  *returnSize = 0;
  generate(result, returnSize, 0, 0, n, 0, str);
  return result;
}

// int catalan(n) {
//   int i, j, h[n + 1];
//   h[0] = h[1] = 1;
//   for (i = 2; i <= n; i++) {
//     h[i] = 0;
//     for (j = 0; j < i; j++)
//       h[i] = h[i] + h[j] * h[i - j - 1];
//   }
//   return h[n];
// }
// @lc code=end
