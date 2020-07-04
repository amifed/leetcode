/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 */
#include <stdbool.h>
#include <string.h>
// @lc code=start

bool valid(char* str) {
  if (strlen(str) > 3) return false;
  return *str == '0' ? strlen(str) == 1 : atoi(str) < 256;
}

char** restoreIpAddresses(char* s, int* returnSize) {
}

// @lc code=end
