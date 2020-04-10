/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (36.99%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    41.9K
 * Total Submissions: 109.8K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start
/**
 * 反转字符串
 **/
void reverse(char* str, int start, int end) {
  if (str == NULL) return str;
  int i, j;
  char s;
  for (i = start, j = end; i < j; i++, j--) {
    s = str[i];
    str[i] = str[j];
    str[j] = s;
  }
}
/**
 * 去除中间空格
 **/
void compact(char* s) {
  if (s == NULL || *s == '\0') return s;
  int i = 0, p = 0;
  bool pre_space = false;  //上一个字符是空格
  do {
    if (!(s[i] == ' ' && pre_space)) {
      s[p++] = s[i];
      pre_space = (s[i] == ' ');
    }
  } while (s[i++] != '\0');
}
/**
 * 去除尾部空格
 **/
void trim(char* s) {
  int p = strlen(s) - 1;
  while (p >= 0 && s[p] == ' ') {
    s[p--] = '\0';
  }
}
char* reverseWords(char* s) {
  trim(s);  //除去尾部空格
  int i, p, len = strlen(s);
  if (s == NULL || len < 2) return s;
  reverse(s, 0, len - 1);                  //整体反转
  for (i = 0, p = 0; s[i] != '\0'; i++) {  //逐个单词反转
    if (s[i] == ' ') {
      reverse(s, p, i - 1);
      p = i + 1;
    }
  }
  reverse(s, p, i - 1);  //反转最后一个单词
  compact(s);            //去除中间空格
  trim(s);               //首部空格反转后在尾部，再次去除尾部空格
  return s;
}

// @lc code=end
// "  hello world!  "
// "a good   example"
// "    i am jinyang     ding      "