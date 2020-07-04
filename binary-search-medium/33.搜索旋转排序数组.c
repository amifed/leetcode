/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start

int search(int* nums, int numsSize, int target) {
  int left = 0, right = numsSize - 1, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[left] <= nums[mid]) {                 //left orderly
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
  return -1;
}

// @lc code=end
//[3,1]\n1