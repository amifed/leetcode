/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.52%)
 * Likes:    1039
 * Dislikes: 0
 * Total Accepted:    74.8K
 * Total Submissions: 149.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start

int Min(int a, int b) { return a < b ? a : b; }

// 每次求横向一层的水量
int trap(int* height, int heightSize) {
  if (heightSize < 3) return 0;
  int p = 0, rain = 0, top = -1;
  int stack[heightSize];
  while (p < heightSize) {
    while (top > -1 && height[p] > height[stack[top]]) {
      int h = height[stack[top--]];
      if (top == -1) break;
      int length = p - stack[top] - 1;
      int width = Min(height[stack[top]], height[p]) - h;
      rain += length * width;
    }
    stack[++top] = p++;
  }
  return rain;
}

// @lc code=end
