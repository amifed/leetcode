/*
 * @lc app=leetcode.cn id=59 lang=c
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = n;
  int** result = (int**)malloc(n * sizeof(int*));
  *returnColumnSizes = (int*)calloc(n, sizeof(int));
  if (n == 0) return result;
  int i, j, m, level;
  for (i = 0; i < n; i++) {
    result[i] = (int*)calloc(n, sizeof(int));
    (*returnColumnSizes)[i] = n;
  }
  for (level = 1, m = 0; m < n * n - 1; level++) {
    for (i = j = level - 1; j < n - level && m < n * n; j++)
      result[i][j] = ++m;
    for (; i < n - level && m < n * n; i++)
      result[i][j] = ++m;
    for (; j >= level && m < n * n; j--)
      result[i][j] = ++m;
    for (; i >= level && m < n * n; i--)
      result[i][j] = ++m;
  }
  if (n & 1) result[n / 2][n / 2] = n * n;
  return result;
}

// @lc code=end
