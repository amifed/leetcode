/*
 * @lc app=leetcode.cn id=542 lang=c
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.14%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 42.6K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 * 
 * 两个相邻元素间的距离为 1 。
 * 
 * 示例 1: 
 * 输入:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 输出:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * 
 * 
 * 示例 2: 
 * 输入:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 1 1 1
 * 
 * 
 * 输出:
 * 
 * 
 * 0 0 0
 * 0 1 0
 * 1 2 1
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵的元素个数不超过 10000。
 * 给定矩阵中至少有一个元素是 0。
 * 矩阵中的元素只在四个方向上相邻: 上、下、左、右。
 * 
 * 
 */
#include <limits.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
#define Min(a, b) (a < b ? a : b)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  int i, j;
  *returnSize = matrixSize;
  int** dp = (int**)malloc(matrixSize * sizeof(int*));
  (*returnColumnSizes) = (int*)malloc(matrixSize * sizeof(int));
  memcpy(*returnColumnSizes, matrixColSize, matrixSize * sizeof(int));
  for (i = 0; i < matrixSize; i++) {
    dp[i] = (int*)calloc(matrixColSize[i], sizeof(int));
    for (j = 0; j < matrixColSize[i]; j++)
      if (matrix[i][j] != 0) dp[i][j] = INT_MAX;
  }
  // 左 上
  for (i = 0; i < matrixSize; i++)
    for (j = 0; j < matrixColSize[i]; j++) {
      if (i - 1 >= 0) dp[i][j] = Min(dp[i][j], dp[i - 1][j] + 1);
      if (j - 1 >= 0) dp[i][j] = Min(dp[i][j], dp[i][j - 1] + 1);
    }
  // 右 下
  for (i = matrixSize - 1; i >= 0; i--)
    for (j = matrixColSize[i] - 1; j >= 0; j--) {
      if (i + 1 < matrixSize) dp[i][j] = Min(dp[i][j], dp[i + 1][j] + 1);
      if (j + 1 < matrixColSize[i]) dp[i][j] = Min(dp[i][j], dp[i][j + 1] + 1);
    }
  return dp;
}

// @lc code=end
// [[1,1,1],[1,1,1],[1,1,0]]
// [[0],[0],[0],[0],[0]]
// #define SIZE 3
// int main() {
//   int i, j, matrixSize = SIZE;
//   int** matrix = (int**)malloc(sizeof(int*) * SIZE);
//   int* matrixColSize = (int*)malloc(sizeof(int) * SIZE);
//   for (i = 0; i < SIZE; i++) {
//     matrix[i] = (int*)malloc(sizeof(int) * SIZE);
//     matrixColSize[i] = SIZE;
//     // 测试数据： 1 1 1 1 1 1 1 1 0
//     for (j = 0; j < matrixColSize[i]; j++)
//       scanf("%d", &matrix[i][j]);
//   }
//   int returnSize, *returnColumnSizes;
//   int** result = updateMatrix(matrix, matrixSize, matrixColSize, &returnSize, &returnColumnSizes);
//   // 打印结果
//   for (i = 0; i < returnSize; i++) {
//     for (j = 0; j < returnColumnSizes[i]; j++)
//       printf("%d ", result[i][j]);
//     printf("\n");
//   }
//   return 0;
// }