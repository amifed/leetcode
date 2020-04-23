/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize) {
  int i, j;
  *returnSize = rowIndex + 1;
  int *result = malloc((rowIndex + 1) * sizeof(int *));
  for (i = 0; i <= rowIndex; i++) {
    result[i] = 1;
    for (j = i - 1; j > 0; j--)
      result[j] += result[j - 1];
  }
  return result;
}

// @lc code=end
