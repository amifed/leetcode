/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */
#include <limits.h>
#include <stdlib.h>
// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int lengthOfLongestSubstring(char* s) {
  int map[256] = {0}, max = 0;
  for (int i = 0, start = 0; s[i] != '\0'; i++) {
    if (map[s[i]] != 0)
      start = Max(start, map[s[i]]);
    max = Max(max, i - start + 1);
    map[s[i]] = i + 1;
  }
  return max;
}

// @lc code=end
