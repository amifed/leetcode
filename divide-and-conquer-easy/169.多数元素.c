/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */
#include <stdlib.h>
// @lc code=start

int comp(void const* a, void const* b) {
  return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), comp);
  return nums[numsSize / 2];
}

// @lc code=end
