/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (53.78%)
 * Likes:    867
 * Dislikes: 0
 * Total Accepted:    175.3K
 * Total Submissions: 326K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
 * 
 * 注意：你不能在买入股票前卖出股票。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * ⁠    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 
 */

// @lc code=start

int maxProfit(int* prices, int pricesSize) {
  if (pricesSize == 0) return 0;
  int i, min = prices[0], max = 0;
  for (i = 0; i < pricesSize; i++) {
    if (prices[i] < min)
      min = prices[i];
    if (prices[i] - min > max)
      max = prices[i] - min;
  }
  return max;
}

//暴力
// int maxProfit(int *prices, int pricesSize)
// {
//     int i, j, max = 0;
//     for (i = 0; i < pricesSize; i++)
//         for (j = i + 1; j < pricesSize; j++)
//             if (prices[j] - prices[i] > max)
//                 max = prices[j] - prices[i];
//     return max;
// }
// @lc code=end
