/*
 * @lc app=leetcode.cn id=223 lang=c
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (42.69%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    7.9K
 * Total Submissions: 18.5K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
 * 
 * 每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: -3, 0, 3, 4, 0, -1, 9, 2
 * 输出: 45
 * 
 * 说明: 假设矩形面积不会超出 int 的范围。
 * 
 */

// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int area1 = (C - A) * (D - B);
  int area2 = (G - E) * (H - F);
  if (C < E || G < A || B > H || F > D)  // 不相交
    return area1 + area2;
  int xl = Max(A, E), xr = Min(C, G);
  int yb = Max(B, F), yt = Min(D, H);
  return area1 - (xr - xl) * (yt - yb) + area2;
}

// @lc code=end
// -1\n0\n0\n1\n0\n-1\n1\n0 不相交
// 0\n0\n3\n3\n0\n0\n3\n3
// 1\n1\n3\n3\n2\n2\n4\n4