/*
 * @lc app=leetcode.cn id=304 lang=c
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (43.15%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 17.1K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 * 
 * 
 * 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
 * 
 * 示例:
 * 
 * 给定 matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 说明:
 * 
 * 
 * 你可以假设矩阵不可变。
 * 会多次调用 sumRegion 方法。
 * 你可以假设 row1 ≤ row2 且 col1 ≤ col2。
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start

typedef struct {
  int** dp;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
  if (matrixSize == 0 || matrixColSize[0] == 0) return NULL;
  NumMatrix* numMatrix = (NumMatrix*)malloc(sizeof(NumMatrix));
  numMatrix->dp = (int**)malloc(sizeof(int*) * (matrixSize + 1));
  for (int i = 0; i <= matrixSize; i++)
    numMatrix->dp[i] = (int*)calloc((matrixColSize[0] + 1), sizeof(int));
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixColSize[i]; j++)
      numMatrix->dp[i + 1][j + 1] = numMatrix->dp[i][j + 1] + numMatrix->dp[i + 1][j] + matrix[i][j] - numMatrix->dp[i][j];
  }
  return numMatrix;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
  return obj->dp[row2 + 1][col2 + 1] - obj->dp[row2 + 1][col1] - obj->dp[row1][col2 + 1] + obj->dp[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
  if (obj && obj->dp) free(obj->dp);
  if (obj) free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
// @lc code=end
// ["NumMatrix"]\n[[[]]]