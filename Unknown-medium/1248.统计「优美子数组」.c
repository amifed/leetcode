/*
 * @lc app=leetcode.cn id=1248 lang=c
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start

// int numberOfSubarrays(int* nums, int numsSize, int k) {
//   int i, count, res;
//   int* odd = (int*)malloc(sizeof(int) * (numsSize + 2));
//   for (i = 0, count = 0; i < numsSize; i++)
//     if (nums[i] & 1) odd[++count] = i;
//   odd[0] = -1, odd[++count] = numsSize;
//   for (i = 1, res = 0; i + k <= count; i++)
//     res += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
//   return res;
// }
int numberOfSubarrays(int* nums, int numsSize, int k) {
  int* count = (int*)calloc(numsSize + 1, sizeof(int));
  int i, odd = 0, res = 0;
  count[0] = 1;
  for (i = 0; i < numsSize; i++) {
    odd += (nums[i] & 1);
    res += odd >= k ? count[odd - k] : 0;
    count[odd]++;
  }
  return res;
}

// @lc code=end
// [2,2,2,1,2,2,1,2,2,2]\n2