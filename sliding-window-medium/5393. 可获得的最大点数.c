/*
 * @lc app=leetcode.cn id=5393 lang=c
 *
 * [5393] 可获得的最大点数
 */
#include <limits.h>
// @lc code=start

int Min(int a, int b) { return a < b ? a : b; }
int maxScore(int* cardPoints, int cardPointsSize, int k) {
  int i, sum = 0, min = INT_MAX, window_sum = 0, window = cardPointsSize - k;
  for (i = 0; i < cardPointsSize; i++)
    sum += cardPoints[i];
  for (i = 0; i < cardPointsSize; i++) {
    window_sum += cardPoints[i];
    if (i >= window) window_sum -= cardPoints[i - window];
    if (i >= window - 1) min = Min(min, window_sum);
  }
  return sum - min;
}

// @lc code=end
