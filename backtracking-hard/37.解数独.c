/*
 * @lc app=leetcode.cn id=37 lang=c
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (60.49%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 41K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */
#include <stdbool.h>
// @lc code=start
bool isVaild(char** board, int row, int col, char ch) {
  int i;
  for (i = 0; i < 9; i++) {
    if (board[row][i] == ch) return false;                                        // 行
    if (board[i][col] == ch) return false;                                        // 列
    if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == ch) return false;  // 九宫格
  }
  return true;
}

bool backtrack(char** board, int row, int col) {
  char ch;
  if (col == 9) {
    return backtrack(board, row + 1, 0);
  }
  if (row == 9) return true;
  if (board[row][col] != '.') {
    return backtrack(board, row, col + 1);
  }
  for (ch = '1'; ch <= '9'; ch++) {
    if (!isVaild(board, row, col, ch)) continue;
    board[row][col] = ch;
    if (backtrack(board, row, col + 1)) return true;
    board[row][col] = '.';
  }
  return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
  backtrack(board, 0, 0);
}

// @lc code=end
