/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <limits.h>
// @lc code=start
int Min(int a, int b) { return a < b ? a : b; }
// int findMin(int* nums, int numsSize) {
//   int min = INT_MAX, left = 0, mid, right = numsSize - 1;
//   while (left <= right) {
//     mid = left + (right - left) / 2;
//     min = Min(min, nums[mid]);
//     if (nums[left] <= nums[mid] && nums[mid] < nums[right])
//       right = mid - 1;
//     else if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
//       if (nums[left] > nums[right])
//         left = mid + 1;
//       else
//         right = mid - 1;
//     } else if (nums[left] > nums[mid] && nums[right] > nums[mid])
//       right = mid - 1;
//     else
//       break;
//   }
//   return min;
// }
int findMin(int* nums, int numsSize) {
  int left = 0, mid, right = numsSize - 1;
  while (right > left) {
    mid = left + (right - left) / 2;
    if (nums[mid] > nums[right])
      left = mid + 1;
    else
      right = mid;
  }
  return nums[left];
}

// @lc code=end
// [4,5,6,7,0,1,2]