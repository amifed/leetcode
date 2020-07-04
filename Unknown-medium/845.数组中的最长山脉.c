/*
 * @lc app=leetcode.cn id=845 lang=c
 *
 * [845] 数组中的最长山脉
 *
 * https://leetcode-cn.com/problems/longest-mountain-in-array/description/
 *
 * algorithms
 * Medium (34.08%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 12.3K
 * Testcase Example:  '[2,1,4,7,3,2,5]'
 *
 * 我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：
 * 
 * 
 * B.length >= 3
 * 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... >
 * B[B.length - 1]
 * 
 * 
 * （注意：B 可以是 A 的任意子数组，包括整个数组 A。）
 * 
 * 给出一个整数数组 A，返回最长 “山脉” 的长度。
 * 
 * 如果不含有 “山脉” 则返回 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1,4,7,3,2,5]
 * 输出：5
 * 解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
 * 
 * 
 * 示例 2：
 * 
 * 输入：[2,2,2]
 * 输出：0
 * 解释：不含 “山脉”。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 * 
 * 
 */
#include <limits.h>
// @lc code=start
int Max(int a, int b) { return a > b ? a : b; }
int longestMountain(int *A, int ASize)
{
    int i, l, r, max = 0;
    for (i = 1; i < ASize - 1; i++)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            for (l = i; l - 1 >= 0 && A[l - 1] < A[l]; l--);
            for (r = i; r + 1 < ASize && A[r] > A[r + 1]; r++);
            max = Max(r - l + 1, max);
        }
    }
    return max;
}

// @lc code=end
// [1,2,3,4,3,2]