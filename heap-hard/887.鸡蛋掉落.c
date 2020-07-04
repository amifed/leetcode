/*
 * @lc app=leetcode.cn id=887 lang=c
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode-cn.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (21.58%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 46.2K
 * Testcase Example:  '1\n2'
 *
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 * 
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 * 
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
 * 
 * 你的目标是确切地知道 F 的值是多少。
 * 
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：K = 1, N = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 * 如果它没碎，那么我们肯定知道 F = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
 * 
 * 
 * 示例 2：
 * 
 * 输入：K = 2, N = 6
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：K = 3, N = 14
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 */
#include <limits.h>
#include <string.h>
// @lc code=start
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
int recursion(int **memo, int k, int n) {
  if (k == 1) return n;
  if (n == 0) return 0;
  if (memo[k][n] != -1) return memo[k][n];
  int temp = INT_MAX;
  /* 线性查找
  for (int i = 1; i <= n; i++) {
    int _break = recursion(memo, k - 1, i - 1);
    int un_break = recursion(memo, k, n - i);
    temp = Min(temp, Max(_break, un_break) + 1);
  }*/
  /* 二分查找 */
  int low = 1, mid, high = n;
  while (low <= high) {
    mid = (low + high) / 2;
    int _break = recursion(memo, k - 1, mid - 1);
    int un_break = recursion(memo, k, n - mid);
    if (_break > un_break) {
      high = mid - 1;
      temp = Min(temp, _break + 1);
    } else {
      low = mid + 1;
      temp = Min(temp, un_break + 1);
    }
  }
  memo[k][n] = temp;
  return temp;
}

int superEggDrop(int K, int N) {
  int **memo = (int **)malloc((K + 1) * sizeof(int *));
  for (int i = 0; i <= K; i++) {
    memo[i] = (int *)malloc((N + 1) * sizeof(int));
    memset(memo[i], -1, (N + 1) * sizeof(int));
  }
  return recursion(memo, K, N);
}

// @lc code=end
// 3\n14
// 49\n1000