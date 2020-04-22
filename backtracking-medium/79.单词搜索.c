/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 */
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start
bool backtrack(char** board, int boardSize, int* boardColSize, bool** visited, int dir[4][2], int x, int y, char* word) {
  if (*word == '\0') return true;
  if (board[x][y] == *word) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int _x = x + dir[i][0];
      int _y = y + dir[i][1];
      if (_x > -1 && _x < boardSize && _y > -1 && _y < boardColSize[_x] && !visited[_x][_y])
        if (backtrack(board, boardSize, boardColSize, visited, dir, _x, _y, word + 1))
          return true;
    }
    visited[x][y] = false;
    return *(word + 1) == '\0';
  }
  return false;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
  if (boardSize == 0 || word == NULL) return false;
  int i, j, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  //上 右 下 左
  bool** visited = (bool**)malloc(boardSize * sizeof(bool*));
  for (i = 0; i < boardSize; i++)
    visited[i] = (bool*)calloc(boardColSize[i], sizeof(bool));
  for (i = 0; i < boardSize; i++)
    for (j = 0; j < boardColSize[i]; j++)
      if (backtrack(board, boardSize, boardColSize, visited, dir, i, j, word))
        return true;
  return false;
}

// @lc code=end
// [["A"]]\n"A"