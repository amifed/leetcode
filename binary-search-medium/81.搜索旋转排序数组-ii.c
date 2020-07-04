/*
 * @lc app=leetcode.cn id=81 lang=c
 *
 * [81] 搜索旋转排序数组 II
 */
#include <stdbool.h>
// @lc code=start

bool search(int* nums, int numsSize, int target) {
  int left = 0, right = numsSize - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] == target)
      return true;
    if (nums[left] == nums[mid])
      left++;
    else if (nums[left] < nums[mid]) {                 //left orderly
      if (nums[left] <= target && target < nums[mid])  //in left
        right = mid - 1;
      else
        left = mid + 1;
    } else {                                            //right orderly
      if (nums[mid] < target && target <= nums[right])  //in right
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  return false;
}

// @lc code=end
// [1,3,1,1,1]\n3
// [1,1,3,1]\n3
