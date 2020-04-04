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

int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
// int trap(int* height, int heightSize) {
//   if (heightSize < 3) return 0;
//   int i, j, max_left, max_right, rain = 0;
//   for (i = 1; i < heightSize - 1; i++) {
//     max_left = 0;
//     max_right = 0;
//     for (j = i; j >= 0; j--)
//       max_left = Max(max_left, height[j]);
//     for (j = i; j < heightSize; j++)
//       max_right = Max(max_right, height[j]);
//     rain += Min(max_left, max_right) - height[i];
//   }
//   return rain;
// }

int trap(int* height, int heightSize) {
  if (heightSize < 3) return 0;
  int i, rain = 0;
  int left_max[heightSize], right_max[heightSize];
  // 从左往右找最小
  left_max[0] = height[0];
  for (i = 1; i < heightSize; i++) {
    left_max[i] = Max(left_max[i - 1], height[i]);
  }
  // 从右往左找最大
  right_max[heightSize - 1] = height[heightSize - 1];
  for (i = heightSize - 2; i >= 0; i--) {
    right_max[i] = Max(right_max[i + 1], height[i]);
  }

  for (i = 1; i < heightSize - 1; i++) {
    rain += Min(left_max[i], right_max[i]) - height[i];
  }
  return rain;
}

// @lc code=end
