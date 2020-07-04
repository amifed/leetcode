/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    204
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 56.8K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start

int factorial(int n) {
  int num = 1;
  for (; n > 0; n--)
    num *= n;
  return num;
}
void deleteItem(int *nums, int numsSize, int in) {
  for (; in < numsSize - 1; in++)
    nums[in] = nums[in + 1];
}
char *getPermutation(int n, int k) {
  int i, j = 0, nums[n], factor;
  char *res = (char *)calloc(10, sizeof(char));
  for (i = 0; i < n; i++)  //初始化一个 [1,2,3,……,n] 数组
    nums[i] = i + 1;
  for (i = 0, k--; i < n; i++)  //k要先减去1
  {
    factor = factorial(n - i - 1);
    res[j++] = nums[k / factor] + '0';
    deleteItem(nums, n - i, k / factor);  //取出一个元素
    k %= factor;
  }
  return res;
}

// @lc code=end
// 5\n88
// 6\n457
// 9\n373

/**
例如： n = 6, k = 373
初始化数组 nums = [1, 2, 3, 4, 5, 6];
首先应该明白，以 1 开头的全排列有 5! 个，以 2 开头的全排列有 5! 个 …… 共 5! * 6 = 6! 个；

故 k = 373 时，全排列的第一个数字应该是 nums[ k / 5! ] = 4 ;
数组删除 4, 此时 nums = [1, 2, 3, 5, 6]; k %= 5! = 12 ;
接下来就是在 nums 中找第 12 个全排列，重复 1，2 步即可 。
注意数组下标是从 0 开始，k 首先要减去 1
**/