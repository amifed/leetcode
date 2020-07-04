/*
 * @lc app=leetcode.cn id=51 lang=c
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.57%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    35.7K
 * Total Submissions: 51.9K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
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
void backtrack(int n, int row, int* visited, char*** result, int* returnSize) {
  if (row == n) {
    result[*returnSize] = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
      result[*returnSize][i] = (char*)calloc(n + 1, sizeof(char));
      memset(result[*returnSize][i], '.', n);
      result[*returnSize][i][visited[i]] = 'Q';
    }
    (*returnSize)++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!check(visited, row, i)) continue;
    visited[row] = i;
    backtrack(n, row + 1, visited, result, returnSize);
    // visited[row] = 0; //此句无关紧要，但是回溯的思想
  }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int* visited = (int*)calloc(n, sizeof(int));
  char*** result = (char***)malloc(n * n * n * sizeof(char**));
  backtrack(n, 0, visited, result, returnSize);
  *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = n;
  return result;
}

// @lc code=end
