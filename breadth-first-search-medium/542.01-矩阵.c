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
#define MAX_SIZE 10240
#define Min(a, b) (a < b ? a : b)

typedef struct {
  int x;
  int y;
} Coord;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  int i, j, x, y, front = 0, rear = 0;
  *returnSize = matrixSize;
  int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  //左，右，下，上
  int** result = (int**)malloc(matrixSize * sizeof(int*));
  Coord* queue = (Coord*)malloc(MAX_SIZE * sizeof(Coord));
  (*returnColumnSizes) = (int*)malloc(matrixSize * sizeof(int));
  memcpy(*returnColumnSizes, matrixColSize, matrixSize * sizeof(int));
  // 初始化
  for (i = 0; i < matrixSize; i++) {
    result[i] = (int*)calloc(matrixColSize[i], sizeof(int));
    for (j = 0; j < matrixColSize[i]; j++) {
      if (matrix[i][j] != 0)
        result[i][j] = INT_MAX;
      else {
        queue[front].x = i;
        queue[front++].y = j;
      }
    }
  }
  // 广度优先搜索
  while (front != rear) {
    Coord coord = queue[rear++];
    for (i = 0; i < 4; i++) {
      x = coord.x + dirs[i][0];
      y = coord.y + dirs[i][1];
      if (x >= 0 && x < matrixSize && y >= 0 && y < matrixColSize[0]) {
        if (result[x][y] > result[coord.x][coord.y] + 1) {
          result[x][y] = result[coord.x][coord.y] + 1;
          queue[front].x = x;
          queue[front++].y = y;
        }
      }
    }
  }
  return result;
}

// @lc code=end
