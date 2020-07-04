/*
 * @lc app=leetcode.cn id=1044 lang=c
 *
 * [1044] 最长重复子串
 */
#include <limits.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
#define MAX_SIZE 100000
struct Substring {
  char *str;
  int freq;
};
int Max(int a, int b) { return a > b ? a : b; }
void swap(struct Substring **a, struct Substring **b) {
  struct Substring *temp = *a;
  *a = *b;
  *b = temp;
}
// 稳定的排序---冒泡排序，不会破坏相对位置
void bubble_sort(struct Substring **subs, int subsSize) {
  int i, j;
  bool flag = false;
  for (i = 0; i < subsSize - 1; i++) {
    for (j = subsSize - 1; j > i; j--) {
      if (strlen(subs[j - 1]->str) < strlen(subs[j]->str)) {
        swap(&subs[j - 1], &subs[j]);
        flag = true;
      } else if (strlen(subs[j - 1]->str) == strlen(subs[j]->str) && strcmp(subs[j]->str, subs[j - 1]->str)) {
        swap(&subs[j - 1], &subs[j]);
        flag = true;
      }
    }
    if (flag == false) return;
  }
}
void longestCommonSubstring(char *str1, int len1, char *str2, int len2, int **dp) {
  int i, j;
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else
        dp[i][j] = 0;
    }
  }
}
char *longestDupSubstring(char *S) {
  int i, j, k, l, m, n = 2, len, subsSize = 0;
  char *str = S;
  struct Substring **subs = (struct Substring **)malloc(MAX_SIZE * sizeof(struct Substring *));
  len = strlen(str);
  int **dp = (int **)malloc((len + 1) * sizeof(int *));
  for (i = 0; i <= len; i++)
    dp[i] = (int *)calloc(len + 1, sizeof(int));
  //形成 dp
  longestCommonSubstring(str, len, str, len, dp);
  // 重复子串统计
  for (i = 1; i <= len; i++) {
    for (j = 1; j <= len; j++) {
      if (j <= i) continue;  //对称，只取上半部分
      if (dp[i][j] >= n) {
        for (l = n; l <= dp[i][j]; l++) {  //所有子串
          for (k = 0; k < subsSize; k++)   //判断子串是否存在
            if (strncmp(str + j - l, subs[k]->str, l) == 0) break;
          if (k < subsSize) {        //存在
            for (m = i; m < j; m++)  //避免重复统计
              if (l == dp[m][j]) break;
            if (m == j) subs[k]->freq++;
          } else {  //不存在
            subs[subsSize] = (struct Substring *)malloc(sizeof(struct Substring));
            subs[subsSize]->str = (char *)calloc(l + 1, sizeof(char));
            strncpy(subs[subsSize]->str, str + j - l, l * sizeof(char));
            subs[subsSize++]->freq = 2;
          }
        }
      }
    }
  }
  bubble_sort(subs, subsSize);
  if (subsSize == 0) {
    char *res = (char *)calloc(2, sizeof(char));
    return res;
  } else
    return subs[0]->str;
}

// @lc code=end
