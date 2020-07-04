/*
 * @lc app=leetcode.cn id=90 lang=c
 *
 * [90] 子集 II
 */

// @lc code=start

#define MAX_SIZE 10240
int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}
void backtrack(int* nums, int numsSize, int start, int* track, int trackSize, int** result, int* returnSize, int* returnColumnSizes) {
  result[*returnSize] = (int*)calloc(trackSize, sizeof(int));
  memcpy(result[*returnSize], track, trackSize * sizeof(int));
  returnColumnSizes[(*returnSize)++] = trackSize;
  if (trackSize == numsSize) return;
  for (int i = start; i < numsSize; i++) {
    track[trackSize] = nums[i];
    backtrack(nums, numsSize, i + 1, track, trackSize + 1, result, returnSize, returnColumnSizes);
    while (i < numsSize - 1 && nums[i] == nums[i + 1]) i++;
  }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int** result = (int**)malloc(MAX_SIZE * sizeof(int*));
  if (numsSize == 0) return result;
  int* track = (int*)calloc(numsSize, sizeof(int));
  *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
  qsort(nums, numsSize, sizeof(int), comp);
  backtrack(nums, numsSize, 0, track, 0, result, returnSize, *returnColumnSizes);
  return result;
}

// @lc code=end
