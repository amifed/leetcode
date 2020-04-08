/*
 * @lc app=leetcode.cn id=120 lang=c
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (64.11%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 77.7K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */
#include <stdlib.h>
// @lc code=start

//bottom to top
#define Min(a, b) (a < b ? a : b)
int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
  if (triangle == NULL)
    return 0;
  int i, j;
  for (i = triangleSize - 2; i >= 0; i--)
    for (j = triangleColSize[i] - 1; j >= 0; j--)
      triangle[i][j] += Min(triangle[i + 1][j], triangle[i + 1][j + 1]);
  return triangle[0][0];
}
//top to bottom
// int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
// {
//     int i, j, min = INT_MAX;
//     int **dp = (int **)malloc(sizeof(int *) * triangleSize);
//     dp[0] = (int *)malloc(sizeof(int) * triangleColSize[0]);
//     dp[0][0] = triangle[0][0];
//     for (i = 1; i < triangleSize; i++)
//     {
//         dp[i] = (int *)malloc(sizeof(int) * triangleColSize[i]);
//         for (j = 0; j < triangleColSize[i]; j++)
//         {
//             if (j - 1 < 0)
//                 dp[i][j] = triangle[i][j] + dp[i - 1][j];
//             else if (i == j)
//                 dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = triangle[i][j] + Min(dp[i - 1][j], dp[i - 1][j - 1]);
//         }
//     }
//     for (i = 0; i < triangleColSize[triangleSize - 1]; i++)
//         if (dp[triangleSize - 1][i] < min)
//             min = dp[triangleSize - 1][i];
//     return min;
// }

// @lc code=end
