/*
 * @lc app=leetcode.cn id=64 lang=c
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.13%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    74.9K
 * Total Submissions: 114.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start

#define Min(a, b) (a < b ? a : b)
int minPathSum(int **grid, int gridSize, int *gridColSize) {
  int i, j;
  long dp[gridSize][gridColSize[0]];
  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < gridColSize[i]; j++) {
      if (i - 1 < 0 && j - 1 < 0)  //[0][0]
        dp[i][j] = grid[i][j];
      else if (i - 1 < 0)  //第一列
        dp[i][j] = grid[i][j] + dp[i][j - 1];
      else if (j - 1 < 0)  //第一行
        dp[i][j] = grid[i][j] + dp[i - 1][j];
      else
        dp[i][j] = grid[i][j] + Min(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[gridSize - 1][gridColSize[0] - 1];
}

// @lc code=end
