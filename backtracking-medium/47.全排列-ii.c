/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.78%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    51.1K
 * Total Submissions: 88K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int factorial(int n) {
  int num = 1;
  while (n > 0) {
    num *= n;
    n--;
  }
  return num;
}
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;  //由小到大排序
}
bool chechRepeat(int* nums, int numsSize, int** result, int* returnSize) {
  for (int i = 0; i < *returnSize; i++) {
    if (memcmp((void*)nums, (void*)result[i], sizeof(int) * numsSize) == 0) return false;
  }
  return true;
}
void backtrack(int* nums, int numsSize, int** result, int* returnSize, int** returnColumnSizes, int first, bool* used) {
  if (first == numsSize && chechRepeat(nums, numsSize, result, returnSize)) {
    result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
    memcpy(result[*returnSize], nums, sizeof(int) * numsSize);
    (*returnColumnSizes)[(*returnSize)++] = numsSize;
    return;
  }
  for (int i = first; i < numsSize; i++) {
    if ((first != i && nums[first] == nums[i] && !used[i - 1]) || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
      continue;
    if (first != i) swap(nums + first, nums + i);
    used[i] = true;
    backtrack(nums, numsSize, result, returnSize, returnColumnSizes, first + 1, used);
    used[i] = false;
    if (first != i) swap(nums + first, nums + i);
  }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  if (numsSize <= 0) return NULL;
  int factor = factorial(numsSize);
  *returnColumnSizes = (int*)malloc(sizeof(int) * factor);
  int** result = (int**)malloc(sizeof(int*) * factor);
  bool* used = (bool*)calloc(numsSize, sizeof(bool));
  qsort(nums, numsSize, sizeof(int), comp);
  backtrack(nums, numsSize, result, returnSize, returnColumnSizes, 0, used);
  return result;
}

// @lc code=end
// [2,2,1,1]