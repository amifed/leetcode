/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.77%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    82.8K
 * Total Submissions: 170.9K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */

// @lc code=start
#define MAX_SIZE 512
typedef struct {
  int x;
  int y;
} Coord;
int numIslands(char** grid, int gridSize, int* gridColSize) {
  Coord* queue = (Coord*)malloc(MAX_SIZE * sizeof(Coord));
  int i, j, front = 0, rear = 0, islands = 0;
  for (i = 0; i < gridSize; i++) {
    for (j = 0; j < gridColSize[i]; j++) {
      if (grid[i][j] == '1') {
        islands++;
        grid[i][j] = '0';
        queue[front].x = i;  //入队
        queue[front++].y = j;
        while (front != rear) {
          Coord coord = queue[rear++];
          if (coord.x - 1 > -1 && grid[coord.x - 1][coord.y] == '1') {  //上
            grid[coord.x - 1][coord.y] = '0';
            queue[front].x = coord.x - 1;
            queue[front++].y = coord.y;
          }
          if (coord.x + 1 < gridSize && grid[coord.x + 1][coord.y] == '1') {  //下
            grid[coord.x + 1][coord.y] = '0';
            queue[front].x = coord.x + 1;
            queue[front++].y = coord.y;
          }
          if (coord.y - 1 > -1 && grid[coord.x][coord.y - 1] == '1') {  //左
            grid[coord.x][coord.y - 1] = '0';
            queue[front].x = coord.x;
            queue[front++].y = coord.y - 1;
          }
          if (coord.y + 1 < gridColSize[coord.x] && grid[coord.x][coord.y + 1] == '1') {  //右
            grid[coord.x][coord.y + 1] = '0';
            queue[front].x = coord.x;
            queue[front++].y = coord.y + 1;
          }
        }
        front = 0;
        rear = 0;
      }
    }
  }
  return islands;
}

// @lc code=end
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]