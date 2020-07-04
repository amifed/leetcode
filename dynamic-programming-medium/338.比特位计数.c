/*
 * @lc app=leetcode.cn id=338 lang=c
 *
 * [338] 比特位计数
 *
 * https://leetcode-cn.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (74.89%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 45.7K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: [0,1,1]
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: [0,1,1,2,1,2]
 * 
 * 进阶:
 * 
 * 
 * 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 * 要求算法的空间复杂度为O(n)。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
  int i, square;
  *returnSize = 0;
  int* dp = (int*)calloc(num + 1, sizeof(int));
  dp[(*returnSize)++] = 0;
  for (i = 1; i <= num; i++) {
    if (log2(i) == (int)log2(i)) {
      dp[(*returnSize)++] = 1;
      square = i;
    } else {
      dp[(*returnSize)++] = dp[square] + dp[i - square];
    }
  }
  // for (i = 1, square = 1; i <= num; i++) {
  //   if (i == square) {
  //     dp[(*returnSize)++] = 1;
  //     square *= 2;
  //   } else {
  //     dp[(*returnSize)++] = 1 + dp[i - square / 2];
  //   }
  // }
  // for (i = 1; i <= num; i++) {
  //   if (i % 2 == 0)
  //     dp[(*returnSize)++] = dp[i / 2];
  //   else
  //     dp[(*returnSize)++] = dp[i - 1] + 1;
  // }

  return dp;
}

// @lc code=end
