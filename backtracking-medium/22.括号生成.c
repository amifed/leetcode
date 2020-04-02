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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//递归回溯求解，注意减枝
void generate(int left, int right, int n, char *str, int index, char **result, int *returnSize) {
  if (left == n && right == n) {  //左右括号都用完
    result[(*returnSize)] = (char *)malloc(sizeof(char) * (2 * n + 1));
    str[index] = '\0';
    strcpy(result[(*returnSize)++], str);
    return;
  }

  if (left < n) {  //当左括号没用完时
    str[index] = '(';
    generate(left + 1, right, n, str, index + 1, result, returnSize);
  }
  if (left > right && right < n) {  //右括号数量必须小于左括号，否则一定不合法，且右括号没有用完
    str[index] = ')';
    generate(left, right + 1, n, str, index + 1, result, returnSize);
  }
}

char **generateParenthesis(int n, int *returnSize) {
  char *str = (char *)malloc(sizeof(char) * (2 * n + 1));
  char **result = (char **)malloc(sizeof(char *) * 2500);
  *returnSize = 0;
  generate(0, 0, n, str, 0, result, returnSize);
  return result;
}

// @lc code=end
