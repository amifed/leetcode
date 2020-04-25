/*
 * @lc app=leetcode.cn id=54 lang=c
 *
 * [54] 螺旋矩阵
 * 
 * [[1]]
 */

// @lc code=start
#define MAX_SIZE 512
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int i, j, n, level;
  int* result = (int*)calloc(MAX_SIZE, sizeof(int));
  if (matrixSize == 0) {
    *returnSize = 0;
    return result;
  }
  *returnSize = matrixSize * matrixColSize[0];
  for (level = 1, n = 0; n < *returnSize - 1; level++) {
    for (i = j = level - 1; j < matrixColSize[0] - level && n < *returnSize; j++)
      result[n++] = matrix[i][j];
    for (; i < matrixSize - level && n < *returnSize; i++)
      result[n++] = matrix[i][j];
    for (; j >= level && n < *returnSize; j--)
      result[n++] = matrix[i][j];
    for (; i >= level && n < *returnSize; i--)
      result[n++] = matrix[i][j];
  }
  if (*returnSize % 2 == 1)
    result[n] = matrix[matrixSize / 2][matrixColSize[0] / 2];
  return result;
}

// @lc code=end
