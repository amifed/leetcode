/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.01%)
 * Likes:    660
 * Dislikes: 0
 * Total Accepted:    100K
 * Total Submissions: 188K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <math.h>
// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1000
void backtrack(char* digits, char* phone[8], char* str, int index, char** result, int* returnSize) {
  if (*digits == '\0') {
    result[(*returnSize)] = (char*)calloc(strlen(str) + 1, sizeof(char));
    strcpy(result[(*returnSize)++], str);
    return;
  }
  int len = strlen(phone[(*digits - '2')]);
  for (int i = 0; i < len; i++) {
    str[index] = phone[(*digits - '2')][i];
    backtrack(digits + 1, phone, str, index + 1, result, returnSize);
  }
}
char** letterCombinations(char* digits, int* returnSize) {
  char* phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  char* str = (char*)calloc(strlen(digits) + 1, sizeof(char));
  char** result = (char**)malloc(sizeof(char*) * MAX_SIZE);
  *returnSize = 0;
  if (strlen(digits) > 0)
    backtrack(digits, phone, str, 0, result, returnSize);
  return result;
}

// @lc code=end
