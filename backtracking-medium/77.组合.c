/*
 * @lc app=leetcode.cn id=77 lang=c
 *
 * [77] 组合
 */
#include <string.h>
// @lc code=start
#define MAX_SIZE 10240
void backtrack(int n, int k, int start, int* nums, int numsSize, int** result, int* returnSize) {
  if (numsSize == k) {
    result[*returnSize] = (int*)calloc(numsSize, sizeof(int));
    memcpy(result[(*returnSize)++], nums, numsSize * sizeof(int));
    return;
  }
  for (int i = start; i <= n; i++) {
    nums[numsSize] = i;
    backtrack(n, k, i + 1, nums, numsSize + 1, result, returnSize);
  }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int** result = (int**)malloc(MAX_SIZE * sizeof(int*));
  if (n == 0 || k == 0) return result;
  int* nums = (int*)calloc(k, sizeof(int));
  backtrack(n, k, 1, nums, 0, result, returnSize);
  *returnColumnSizes = (int*)calloc(*returnSize, sizeof(int));
  for (int i = 0; i < *returnSize; i++) {
    (*returnColumnSizes)[i] = k;
  }
  return result;
}

// @lc code=end
