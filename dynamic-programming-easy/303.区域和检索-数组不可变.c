/*
 * @lc app=leetcode.cn id=303 lang=c
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (60.64%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 56.4K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */
#include <stdlib.h>
// @lc code=start

typedef struct
{
  int *sums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize) {
  int i = 0;
  if (numsSize == 0)
    return NULL;
  NumArray *numArray = (NumArray *)malloc(sizeof(NumArray));
  numArray->sums = (int *)malloc(sizeof(int) * numsSize);
  numArray->sums[0] = nums[0];
  for (i = 1; i < numsSize; i++)
    numArray->sums[i] = numArray->sums[i - 1] + nums[i];
  return numArray;
}

int numArraySumRange(NumArray *obj, int i, int j) {
  if (i == 0)
    return obj->sums[j];
  return obj->sums[j] - obj->sums[i - 1];
}

void numArrayFree(NumArray *obj) {
  if (obj != NULL) free(obj->sums);
  free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
// @lc code=end
