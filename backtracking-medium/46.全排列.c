/*
 * @lc app=leetcode.cn id=46 lang=c
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.49%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    102.4K
 * Total Submissions: 137.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
#
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
void backtrack(int* nums, int numsSize, int** result, int* returnSize, int** returnColumnSizes, int first) {
  if (first == numsSize) {
    result[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
    memcpy(result[*returnSize], nums, sizeof(int) * numsSize);
    (*returnColumnSizes)[(*returnSize)++] = numsSize;
  }
  for (int i = first; i < numsSize; i++) {
    if (first != i) swap(nums + first, nums + i);
    backtrack(nums, numsSize, result, returnSize, returnColumnSizes, first + 1);
    if (first != i) swap(nums + first, nums + i);
  }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  if (numsSize <= 0) return NULL;
  int factor = factorial(numsSize);
  int* arr = (int*)malloc(sizeof(int) * numsSize);
  *returnColumnSizes = (int*)malloc(sizeof(int) * factor);
  int** result = (int**)malloc(sizeof(int*) * factor);
  backtrack(nums, numsSize, result, returnSize, returnColumnSizes, 0);
  return result;
}

// @lc code=end
