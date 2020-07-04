/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.76%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 179.8K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
#include <limits.h>
#include <string.h>
// @lc code=start
#define Max(a, b) (a > b ? a : b)
int comp(const void *a, const void *b) {
  return **(int **)a - **(int **)b;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes) {
  *returnSize = 0;
  if (intervalsSize < 1) return intervals;
  int i, j;
  qsort(intervals, intervalsSize, sizeof(int *), comp);
  int **result = (int **)malloc(sizeof(int *) * intervalsSize);
  result[*returnSize] = (int *)malloc(sizeof(int) * 2);
  memcpy(result[(*returnSize)++], intervals[0], sizeof(int) * 2);
  for (i = 1; i < intervalsSize; i++) {
    if (result[*returnSize - 1][1] < intervals[i][0]) {
      result[*returnSize] = (int *)malloc(sizeof(int) * 2);
      result[*returnSize][0] = intervals[i][0];
      result[(*returnSize)++][1] = intervals[i][1];
    } else
      result[*returnSize - 1][1] = Max(result[*returnSize - 1][1], intervals[i][1]);
  }
  *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
  for (i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = 2;

  return result;
}

// @lc code=end
// [[5,6],[2,4],[1,3],[3,7],[9,11]]
// [[0,0]]
// [[0,0],[1,1],[2,2],[3,5]]