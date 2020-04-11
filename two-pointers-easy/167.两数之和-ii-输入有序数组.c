/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (53.12%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    82.1K
 * Total Submissions: 154K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
  int p, q, *result = (int*)calloc(2, sizeof(int));
  for (p = 0, q = numbersSize - 1; p < q;) {
    if (numbers[p] + numbers[q] == target) {
      result[0] = p + 1;
      result[1] = q + 1;
      break;
    } else if (numbers[p] + numbers[q] < target)
      p++;
    else
      q--;
  }
  *returnSize = 2;
  return result;
}

// @lc code=end
