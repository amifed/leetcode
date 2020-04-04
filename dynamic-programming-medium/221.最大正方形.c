/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (39.35%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    28.7K
 * Total Submissions: 72.9K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
#include <limits.h>
// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b, int c) { return a < b ? a < c ? a : c : b < c ? b : c; }
int maximalSquare(char **matrix, int matrixSize, int *matrixColSize) {
  int rows = matrixSize, cols = rows > 0 ? matrixColSize[0] : 0;
  int i, j, maxsqlen = 0;
  int **dp = (int **)malloc(sizeof(int *) * (rows + 1));
  for (i = 0; i <= matrixSize; i++)
    dp[i] = (int *)calloc(cols + 1, sizeof(int));
  for (i = 1; i <= rows; i++) {
    for (j = 1; j <= cols; j++) {
      if (matrix[i - 1][j - 1] == '1') {
        dp[i][j] = Min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        maxsqlen = Max(maxsqlen, dp[i][j]);
      }
    }
  }
  return maxsqlen * maxsqlen;
}

// @lc code=end
// [["0"]]