/*
 * @lc app=leetcode.cn id=216 lang=c
 *
 * [216] 组合总和 III
 */

// @lc code=start

#define MAX_SIZE 256
void backtrack(int* candidates, int candidatesSize, int target, int k, int start, int* nums, int index, int** result, int* returnSize, int* returnColumnSizes) {
  if (target == 0 && index == k) {
    result[*returnSize] = (int*)calloc(index, sizeof(int));
    memcpy(result[*returnSize], nums, index * sizeof(int));
    returnColumnSizes[(*returnSize)++] = index;
    return;
  }
  for (int i = start; i < candidatesSize; i++) {
    if (target - candidates[i] < 0 || index > k) break;
    if (i > start && candidates[i] == candidates[i - 1]) continue;
    nums[index] = candidates[i];
    backtrack(candidates, candidatesSize, target - candidates[i], k, i + 1, nums, index + 1, result, returnSize, returnColumnSizes);
  }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int** result = (int**)malloc(MAX_SIZE * sizeof(int*));
  *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
  if (k == 0 && n == 0) return result;
  int candidatesSize = 9;
  int* candidates = (int*)malloc(candidatesSize * sizeof(int));
  for (int i = 0; i < candidatesSize; i++)
    candidates[i] = i + 1;
  int* nums = (int*)calloc(candidatesSize, sizeof(int));
  backtrack(candidates, candidatesSize, n, k, 0, nums, 0, result, returnSize, *returnColumnSizes);
  return result;
}

// @lc code=end
