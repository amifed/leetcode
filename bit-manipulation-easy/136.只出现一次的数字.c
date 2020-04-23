/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start

/*
 * 位运算 - 异或(^)
 * 
 * a^0 = a
 * a^a = 0
 * a^b^a = a^a^b = 0^b = b;
 */
int singleNumber(int* nums, int numsSize) {
  int i, num;
  for (i = 0, num = 0; i < numsSize; i++)
    num ^= nums[i];
  return num;
}

// @lc code=end
