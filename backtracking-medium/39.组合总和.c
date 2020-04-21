/*
 * @lc app=leetcode.cn id=39 lang=c
 *
 * [39] 组合总和
 */
#include <string.h>
// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 256
int comp(void const* a, void const* b) {
  return *(int*)a - *(int*)b;
}
void backtrack(int* candidates, int candidatesSize, int target, int start, int* nums, int index, int** result, int* returnSize, int* returnColumnSizes) {
  if (target == 0) {
    result[*returnSize] = (int*)calloc(index, sizeof(int));
    memcpy(result[*returnSize], nums, index * sizeof(int));
    returnColumnSizes[(*returnSize)++] = index;
    return;
  }
  for (int i = start; i < candidatesSize; i++) {
    if (target - candidates[i] < 0) break;
    nums[index] = candidates[i];
    backtrack(candidates, candidatesSize, target - candidates[i], i, nums, index + 1, result, returnSize, returnColumnSizes);
  }
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int** result = (int**)malloc(MAX_SIZE * sizeof(int*));
  *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
  if (candidatesSize == 0) return result;
  int* nums = (int*)calloc(MAX_SIZE, sizeof(int));
  qsort(candidates, candidatesSize, sizeof(int), comp);
  backtrack(candidates, candidatesSize, target, 0, nums, 0, result, returnSize, *returnColumnSizes);
  return result;
}

// @lc code=end
