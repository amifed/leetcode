/*
 * @lc app=leetcode.cn id=137 lang=c
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start

int singleNumber(int* nums, int numsSize) {
  int one = 0, two = 0;
  for (int i = 0; i < numsSize; i++) {
    one = one ^ nums[i] & ~two;
    two = two ^ nums[i] & ~one;
  }
  return one;
}

// @lc code=end