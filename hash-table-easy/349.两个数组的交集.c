/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.53%)
 * Likes:    173
 * Dislikes: 0
 * Total Accepted:    60.5K
 * Total Submissions: 87.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 1024
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int i, *hash = (int*)calloc(MAX_SIZE, sizeof(int)), *res = (int*)calloc(MAX_SIZE, sizeof(int));
  for (i = 0; i < nums1Size; i++) {
    if (hash[nums1[i]] == 0) hash[nums1[i]]++;
  }
  *returnSize = 0;
  for (i = 0; i < nums2Size; i++) {
    if (hash[nums2[i]]) {
      hash[nums2[i]]--;
      res[(*returnSize)++] = nums2[i];
    }
  }
  return res;
}

// @lc code=end
