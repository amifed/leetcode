/*
 * @lc app=leetcode.cn id=78 lang=c
 *
 * [78] 子集
 */

// @lc code=start

#define MAX_SIZE 10240
void backtrack(int* nums, int numsSize, int start, int* track, int trackSize, int** result, int* returnSize, int* returnColumnSizes) {
  result[*returnSize] = (int*)calloc(trackSize, sizeof(int));
  memcpy(result[*returnSize], track, trackSize * sizeof(int));
  returnColumnSizes[(*returnSize)++] = trackSize;
  if (trackSize == numsSize) return;
  for (int i = start; i < numsSize; i++) {
    track[trackSize] = nums[i];
    backtrack(nums, numsSize, i + 1, track, trackSize + 1, result, returnSize, returnColumnSizes);
  }
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int** result = (int**)malloc(MAX_SIZE * sizeof(int*));
  if (numsSize == 0) return result;
  int* track = (int*)calloc(numsSize, sizeof(int));
  *returnColumnSizes = (int*)calloc(MAX_SIZE, sizeof(int));
  backtrack(nums, numsSize, 0, track, 0, result, returnSize, *returnColumnSizes);
  return result;
}

// @lc code=end
