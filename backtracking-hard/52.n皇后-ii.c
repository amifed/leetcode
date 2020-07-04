/*
 * @lc app=leetcode.cn id=52 lang=c
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.76%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 26.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
#include <stdbool.h>
#include <string.h>
// @lc code=start

bool check(int* visited, int row, int col) {
  for (int i = 0; i < row; i++)
    if (col == visited[i] || row + col == (visited[i] + i) || row - col == i - visited[i])
      return false;
  return true;
}
void backtrack(int n, int row, int* visited, int* returnSize) {
  if (row == n) {
    (*returnSize)++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!check(visited, row, i)) continue;
    visited[row] = i;
    backtrack(n, row + 1, visited, returnSize);
    // visited[row] = 0; //此句无关紧要，但是回溯的思想
  }
}
int totalNQueens(int n) {
  int returnSize = 0;
  int* visited = (int*)calloc(n, sizeof(int));
  backtrack(n, 0, visited, &returnSize);
  return returnSize;
}

// @lc code=end
