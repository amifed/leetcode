/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 */

// @lc code=start

//动态规划
#define MAX_SIZE 5096
// int* grayCode(int n, int* returnSize) {
//   *returnSize = 1;
//   int* result = (int*)calloc(MAX_SIZE, sizeof(int));
//   for (int i = 0; i < n; i++)
//     for (int j = (1 << i) - 1; j > -1; j--)
//       result[(*returnSize)++] += (result[j] + (1 << i));
//   return result;
// }
int* grayCode(int n, int* returnSize) {
  *returnSize = 1 << n;
  int* result = (int*)calloc(MAX_SIZE, sizeof(int));
  for (int i = 0; i < *returnSize; i++)
    result[i] = (i >> 1) ^ i;
  return result;
}

// @lc code=end
