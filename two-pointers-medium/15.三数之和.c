/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.20%)
 * Likes:    1943
 * Dislikes: 0
 * Total Accepted:    187.1K
 * Total Submissions: 713.2K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start

// 算法思想：先将数组排序，枚举第一个元素，在之后的元素中使用双指针查找另外两个元素
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 30000
int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;  //由小到大排序
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int i, p, q, **result = (int**)malloc(sizeof(int*) * MAX_SIZE);
  qsort(nums, numsSize, sizeof(int), comp);
  *returnSize = 0;
  for (i = 0; i < numsSize - 2 && nums[i] <= 0;) {
    p = i + 1;
    q = numsSize - 1;
    while (p < q) {
      if (nums[p] + nums[q] < -nums[i])
        p++;
      else if (nums[p] + nums[q] > -nums[i])
        q--;
      else {
        result[*returnSize] = (int*)malloc(sizeof(int) * 3);
        result[*returnSize][0] = nums[i];
        result[*returnSize][1] = nums[p];
        result[*returnSize][2] = nums[q];
        (*returnSize)++;
        while (nums[p] == nums[++p] && p < q)
          ;
        while (nums[q] == nums[--q] && p < q)
          ;
      }
    }
    while (nums[i] == nums[++i] && i < numsSize - 2)
      ;
  }
  *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
  for (i = 0; i < *returnSize; i++) {
    (*returnColumnSizes)[i] = 3;
  }
  return result;
}

// @lc code=end
//
//