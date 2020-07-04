/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.53%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    92.9K
 * Total Submissions: 212.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include <limits.h>
// @lc code=start
int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;  //由小到大排序
}
int threeSumClosest(int* nums, int numsSize, int target) {
  int i, p, q, num, res = nums[0] + nums[1] + nums[2];
  qsort(nums, numsSize, sizeof(int), comp);
  for (i = 0; i < numsSize - 2; i++) {
    p = i + 1;
    q = numsSize - 1;
    while (p < q) {
      num = nums[i] + nums[p] + nums[q];
      if (abs(target - num) < abs(target - res)) res = num;
      if (num < target)
        p++;
      else if (num > target)
        q--;
      else
        return target;
    }
  }
  return res;
}

// @lc code=end
